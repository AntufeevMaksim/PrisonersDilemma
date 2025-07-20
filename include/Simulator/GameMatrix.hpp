#pragma once

#include <string>
#include <vector>

class GameMatrix
{
    public:
    GameMatrix(std::string& load_path);
    std::vector<int> get_points();
};
