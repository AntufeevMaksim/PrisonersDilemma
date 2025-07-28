
#include "PrisonerSimulator.hpp"
#include "Strategy.hpp"
#include "OutputData.hpp"
#include "MatrixLoader.hpp"

#include <algorithm>
#include <array>

PrisonerSimulator::PrisonerSimulator(InputData &data) : input_data{data},
                                                        game_matrix{MatrixLoader::LoadMatrix(data.get_matrix_path())},
                                                        score(data.get_strategy_names().size(), 0),
                                                        last_choice(data.get_strategy_names().size(), Strategy::BETRAY)
{
    for (const std::string &name : input_data.get_strategy_names())
    {
        strategies.push_back(Strategy::create(name));
    }
}

void PrisonerSimulator::run()
{
    if (input_data.get_mode() == InputData::TOURNAMENT)
    {
        play_tournament();
    }
    else
    {
        play_one_game({0, 1, 2});
    }
}

void PrisonerSimulator::compute_score(const std::array<int, STRATEGIES_COUNT> &strategies_idx)
{
    int idx = 4 * (last_choice[strategies_idx[0]] == Strategy::BETRAY ? 1 : 0);
    idx += 2 * (last_choice[strategies_idx[1]] == Strategy::BETRAY ? 1 : 0);
    idx += 1 * (last_choice[strategies_idx[2]] == Strategy::BETRAY ? 1 : 0);        

    for (size_t i = 0; i < STRATEGIES_COUNT; i++)
    {
        score[strategies_idx[i]] += game_matrix[idx][i]; 
    }
    
}

void PrisonerSimulator::play_one_game(const std::array<int, STRATEGIES_COUNT> &strategies_idx)
{
    for (size_t i = 0; i < input_data.get_steps_count(); ++i)
    {
        for (int idx : strategies_idx)
        {
            last_choice[idx] = strategies[idx]->make_turn();
        }

        compute_score(strategies_idx);

        if (input_data.get_mode() == InputData::DETAILED)
        {
            InputData::read_char();
            OutputData::print_results(score);
        }

        for (int idx : strategies_idx)
        {
            strategies[idx]->give_last_results(last_choice);
        }
    }

    OutputData::print_results(score);
}

void PrisonerSimulator::play_tournament()
{
    for (int i = 0; (size_t)i < strategies.size(); i++)
    {
        for (int j = i + 1; (size_t)j < strategies.size(); j++)
        {
            for (int k = j + 1; (size_t)k < strategies.size(); k++)
            {
                play_one_game({i, j, k});
            }
            
        }
        
    }
    
}
