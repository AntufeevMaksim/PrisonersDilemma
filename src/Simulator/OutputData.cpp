#include "OutputData.hpp"

#include <ranges>
#include <iostream>

void OutputData::print_results(std::vector<int> score)
{
    for (int i : score | std::views::all) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

