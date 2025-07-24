#pragma once

#include "InputData.hpp"
#include "Strategy.hpp"

#include <array>

#define PLAYERS_COUNT_IN_MATCH 3

typedef std::array<std::array<int, PLAYERS_COUNT_IN_MATCH>, 8> GameMatrix; //magic num 8 is 2**3 (fix needed)

class PrisonerSimulator
{
    public:
    PrisonerSimulator(InputData& data);
    void run();

    private:    
    InputData input_data;
    GameMatrix game_matrix;
    std::vector<std::unique_ptr<Strategy>> strategies;
    std::vector<int> score {0, 0, 0};
    std::vector<Strategy::Choice> last_choice {Strategy::BETRAY, Strategy::BETRAY, Strategy::BETRAY};
    void compute_score();
};

