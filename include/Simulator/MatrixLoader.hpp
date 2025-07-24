#pragma once

#include "PrisonerSimulator.hpp"

#include <string>
#include <vector>
#include <array>
#include <fstream>

class MatrixLoader
{
    public:
    MatrixLoader() = delete;
    static GameMatrix LoadMatrix(const std::string& path);

    private:
    static void write_to_array(std::array<int, PLAYERS_COUNT_IN_MATCH>& arr, std::ifstream& file);
};
