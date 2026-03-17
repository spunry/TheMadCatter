#include "Game.h" 

#include <algorithm> 
#include <raylib.h>
#include <string> 

#include "Constants.h" 
#include "SaveSystem.h" 

Game::Game() = default;
Game::~Game() = default;

void Game::Run() {
    Init();

    while(running_ && !WindowShouldClose()) {
        float dt = GetFrameTime();

        Update(dt);
        Draw();
    }

    Shutdown();
}

void Game::Init() {
    InitWindow(Constants::ScreenWidth, Constants::ScreenHeight, Constants::WindowTitle);
    SetTargetFPS(60);

    catPosition_ = {
        Constants::ScreenWidth * 0.5f,
        Constants::ScreenHeight * 0.5f - 30.0f
    };

    state_.cat.anger = 0.0f;
    state_.cat.angerMax = Constants::MaxAnger;
    state_.cat.angerPerClick = Constants::BaseAngerPerClick;
    state_.cat.angerPerSecond = 0.0f;

    SaveSystem::Load(state_, "data/save.json");
}

void Game::Update(float dt) {
    HandleInput();
    UpdateGameplay(dt);
}

void Game::HandleInput() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();

        if (IsMouseOverCat(mousePos)) {
            HandleCatClick();
        }
    }

    if (IsKeyPressed(KEY_S)) {
        SaveSystem::Save(state_, "data/save.json");
    }
}

void Game::HandleCatClick() {
    state_.totalClicks += 1;
    state_.clickRemainder += 1;  

    while(state_.clickRemainder >= Constants::ClicksPerMadPoint) {
        state_.clickRemainder -= Constants::ClicksPerMadPoint;
        state_.madPoints += 1;
    }

    state_.cat.anger += state_.cat.angerPerClick;
    state_.cat.anger += std::min(state_.cat.anger, state_.cat.angerMax);

    if (state_.cat.anger >= 95.0f) {
        state_.showJumpScareFlash = true;
        state_.jumpScareFlashTimer = 0.25f;
        ResetCatAfterScare();
    }
}

void Game::UpdateGameplay(float dt) {
    state_.cat.anger += state_.cat.angerPerSecond * dt;
    state_.cat.anger = std::min(state_.cat.anger, state_.cat.angerMax);

    if (state_.showJumpScareFlash) {
        state_.jumpScareFlashTimer -= dt;
        if (state_.jumpScareFlashTimer <= 0.0f) {
            state_.showJumpScareFlash = false;
            state_.jumpScareFlashTimer = 0.0f;
        }
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(DARKGRAY);

    DrawCat();
    DrawUI();

    if (state_.showJumpScareFlash) {
        DrawRectangle(0, 0, Constants::ScreenWidth, Constants::ScreenHeight, Fade(RED, 0.45f));
        DrawText("THE CAT SNAPPED!", 410, 320, 40, WHITE);
    }

    EndDrawing();
}

void Game::DrawCat() const {
    Color catColor = ORANGE;

    if (state_.cat.anger >= 80.0f) {
        catColor = MAROON;
    } else if (state_.cat.anger >= 60.0f) {
        catColor = RED;
    } else if (state_.cat.anger >= 40.0f) {
        catColor = ORANGE;
    } else if (state_.cat.anger >= 20.0f) {
        catColor = GOLD;
    }

    DrawCircleV(catPosition_, Constants::CatRadius, catColor);
    DrawText("CAT", static_cast<int>(catPosition_.x) - 28, static_cast<int>(catPosition_.y) - 12, 28, BLACK);
}

void Game::DrawUI() const {
    DrawText("The Mad Catter", 30, 20, 34, WHITE);

    DrawText(TextFormat("Clicks: %lld", state_.totalClicks), 30, 80, 28, WHITE);
    DrawText(TextFormat("Mad Points: %lld", state_.madPoints), 30, 120, 28, WHITE);
    DrawText(TextFormat("Click Remainder: %d / %d", state_.clickRemainder, Constants::ClicksPerMadPoint), 30, 160, 24, LIGHTGRAY);

    DrawText(TextFormat("Anger: %.0f / %.0f", state_.cat.anger, state_.cat.angerMax), 30, 220, 28, WHITE);

    const int barX = 30;
    const int barY = 260;
    const int barW = 360;
    const int barH = 28;
    
    DrawRectangle(barX, barY, barW, barH, GRAY);

    float percent = state_.cat.anger / state_.cat.angerMax;
    int fillW = static_cast<int>(barW * percent);

    DrawRectangle(barX, barY, fillW, barH, RED);
    DrawRectangleLines(barX, barY, barW, barH, WHITE);

    DrawText("Click the cat", 500, 620, 30, WHITE);
    DrawText("Press S to save", 30, 320, 22, LIGHTGRAY);
}

bool Game::IsMouseOverCat(Vector2 mousePos) const {
    return CheckCollisionPointCircle(mousePos, catPosition_, Constants::CatRadius);
}

void Game::ResetCatAfterScare() {
    state_.cat.anger = 0.0f;
}

void Game::Shutdown() {
    SaveSystem::Save(state_, "data/save.json");
    CloseWindow();
}
