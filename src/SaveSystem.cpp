#include "SaveSystem.h" 

bool SaveSystem::Save(const GameState& state, const std::string& path) {
    (void)state;
    (void)path;
    return true;
}

bool SaveSystem::Load(GameState& state, const std::string& path) {
    (void)state;
    (void)path;
    return false; 
}
