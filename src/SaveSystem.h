#pragma once

#include <string>
#include "Types.h" 

class SaveSystem {
    public:
        static bool Save(const GameState& state, const std::string& path);
        static bool Load(GameState& state, const std::string& path);
};
