#pragma once

#include "InputData.hpp"
#include "IStrategy.hpp"

#include <array>

#define STRATEGIES_COUNT 3

typedef std::array<std::array<int, STRATEGIES_COUNT>, 8> GameMatrix; //magic num 8 is 2**3 (fix needed)

class PrisonerSimulator
{
    public:
    PrisonerSimulator(InputData& data);
    void run();

    private:    
    InputData input_data;
    GameMatrix game_matrix;
    std::vector<std::unique_ptr<IStrategy>> strategies;
    std::vector<int> score;
    std::vector<IStrategy::Choice> last_choice;

    void compute_score(const std::array<int, STRATEGIES_COUNT> &strategies_idx);
    void play_one_game(const std::array<int, STRATEGIES_COUNT>& strategies_idx);
    void play_tournament();
};

