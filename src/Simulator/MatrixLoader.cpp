#include "MatrixLoader.hpp"

#include <stdexcept>

GameMatrix MatrixLoader::LoadMatrix(const std::string& path)
{
    GameMatrix matrix;

    std::ifstream file {path};
    
    if (!file) {
        throw std::runtime_error("Cannot open matrix file");
    }

    for (size_t i = 0; i < 8; ++i)//magic num 8 is 2**3 (fix needed)
    {
        write_to_array(matrix[i], file);
    }

    return matrix;
}

void MatrixLoader::write_to_array(std::array<int, PLAYERS_COUNT_IN_MATCH>& arr, std::ifstream& file)
{
    size_t count = 0;

    while (count < PLAYERS_COUNT_IN_MATCH && file >> arr[count]) {
        ++count;
    }

    if (count < PLAYERS_COUNT_IN_MATCH) {
        throw std::runtime_error("File contains fewer than " + 
                               std::to_string(PLAYERS_COUNT_IN_MATCH) + " numbers");
    }

}

