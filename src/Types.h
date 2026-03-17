#pragma once

#include <string>

struct CatState {
    float anger = 0.0f;
    float angerMax = 100.0f;
    float angerPerClick = 1.0f;
    float angerPerSecond = 0.0f;
};

struct GameState {
    long long totalClicks = 0;
    long long madPoints = 0;
    int clickRemainder = 0;

    CatState cat{};

    bool showJumpScareFlash = false;
    float jumpScareFlashTimer = 0.0f;
};
