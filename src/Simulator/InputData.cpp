
#include "InputData.hpp"

InputData::InputData(int argc, char* argv[])
{
    strategy_names = std::vector<std::string> {"Kind", "Kind", "Traitor"};
    game_mode = FAST;
    steps_count = 10;
    config_path = "";
    matrix_path = "/home/maksim/MyPrograms/cpp_projects/prisoners_dilemma/matrix";
}

const std::vector<std::string>& InputData::get_strategy_names() const
{
    return strategy_names; 
}

InputData::GameMode InputData::get_mode() const
{
    return game_mode;
}

size_t InputData::get_steps_count() const
{
    return steps_count;
}

const std::string& InputData::get_config_path() const
{
    return config_path;
}

const std::string& InputData::get_matrix_path() const
{
    return matrix_path;
}