#pragma once

#include "raylib.h" 
#include "Types.h" 

class Game {
    public:
        Game();
        ~Game();

        void Run();

    private:                                    // Private methods 
        void Init();
        void Update(float dt);
        void Draw();
        void Shutdown();

        void HandleInput();
        void UpdateGameplay(float dt);
        void DrawUI() const;
        void DrawCat() const;
        void HandleCatClick();
        bool IsMouseOverCat(Vector2 mousePos) const;
        void ResetCatAfterScare();

    private:                                    // Private data
        GameState state_{};
        Vector2 catPosition_{};
        bool running_ = true;
};
