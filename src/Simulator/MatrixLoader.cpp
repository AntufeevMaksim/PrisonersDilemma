#include "MatrixLoader.hpp"

#include <stdexcept>

GameMatrix MatrixLoader::LoadMatrix(const std::string& path)
{
    GameMatrix matrix;

    std::ifstream file {path};
    
    if (!file){
        throw std::runtime_error("Cannot open matrix file");
    }

    for (size_t i = 0; i < 8; ++i)//magic num 8 is 2**3 (fix needed)
    {
        write_to_array(matrix[i], file);
    }

    return matrix;
}

void MatrixLoader::write_to_array(std::array<int, STRATEGIES_COUNT>& arr, std::ifstream& file)
{
    size_t count = 0;

    while (count < STRATEGIES_COUNT && file >> arr[count]) {
        ++count;
    }

    if (count < STRATEGIES_COUNT) {
        throw std::runtime_error("File contains fewer than " + 
                               std::to_string(STRATEGIES_COUNT) + " numbers");
    }

}

