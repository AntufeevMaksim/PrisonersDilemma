
#include "PrisonerSimulator.hpp"
#include "Strategy.hpp"
#include "OutputData.hpp"
#include "MatrixLoader.hpp"

#include <algorithm>
#include <array>

PrisonerSimulator::PrisonerSimulator(InputData& data) : input_data{data},
                                                        game_matrix{MatrixLoader::LoadMatrix(data.get_matrix_path())}
{
    for (const std::string& name : input_data.get_strategy_names())
    {
        strategies.push_back(Strategy::create(name));
    }
}


void PrisonerSimulator::run()
{
    for (size_t i = 0; i < input_data.get_steps_count(); ++i)
    {
        for (size_t k = 0; k < strategies.size(); ++k)
        {
            last_choice[k] = strategies[k]->make_turn();
        }

        compute_score();

        for (size_t k = 0; k < strategies.size(); ++k)
        {
            strategies[k]->give_last_results(last_choice);
        }
    }

    OutputData::print_results(score);
}


void PrisonerSimulator::compute_score()
{
    int idx = 4 * (last_choice[0] == Strategy::BETRAY ? 1 : 0);
    idx += 2 * (last_choice[1] == Strategy::BETRAY ? 1 : 0);
    idx += 1 * (last_choice[2] == Strategy::BETRAY ? 1 : 0);

    std::transform( //add score for this turn to total score
        score.begin(), score.end(),
        game_matrix[idx].begin(),
        score.begin(),
        [](int a, int b) { return a + b; }
    );
}
