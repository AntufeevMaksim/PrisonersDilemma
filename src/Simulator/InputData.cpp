
#include "InputData.hpp"

#include <cstring>
#include <stdexcept>
#include <filesystem>

InputData::InputData(int argc, char *argv[])
{
    game_mode = FAST;
    steps_count = 10;
    config_path = "";
    matrix_path = "/home/maksim/MyPrograms/cpp_projects/prisoners_dilemma/matrix";

    int curr = 1;
    curr = parse_strategy_names(argc, argv, curr);
    parse_game_parameters(argc, argv, curr);
}

const std::vector<std::string> &InputData::get_strategy_names() const
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

const std::string &InputData::get_config_path() const
{
    return config_path;
}

const std::string &InputData::get_matrix_path() const
{
    return matrix_path;
}

int InputData::parse_strategy_names(int argc, char *argv[], int curr)
{
    for (; curr < argc; ++curr)
    {
        std::string arg = argv[curr];
        if (arg.find("--") == 0)
        {
            break;
        }
        strategy_names.push_back(arg);
    }
    return curr + 1;
}

void InputData::parse_game_mode(const std::string &mode)
{
    if (mode == "detailed")
    {
        game_mode = GameMode::DETAILED;
    }
    else if (mode == "fast")
    {
        game_mode = GameMode::FAST;
    }
    else if (mode == "tournament")
    {
        game_mode = GameMode::TOURNAMENT;
    }
    else
    {
        throw std::invalid_argument("Invalid game mode");
    }
}

void InputData::parse_steps_count(const std::string &count)
{
    try
    {
        steps_count = std::stoi(count);
    }
    catch (const std::exception &)
    {
        throw std::invalid_argument("Invalid steps count");
    }
}

void InputData::parse_config_path(const std::string& path)
{
    config_path = path;
    if (!std::filesystem::exists(path))
    {
        throw std::invalid_argument("Invalid config path");
    }    
}

void InputData::parse_matrix_path(const std::string &path)
{
    matrix_path = path;
    if (!std::filesystem::exists(path))
    {
        throw std::invalid_argument("Invalid matrix path");
    }

}

void InputData::parse_game_parameters(int argc, char *argv[], int curr)
{

    for (; curr < argc; ++curr)
    {
        std::string arg = argv[curr];

        if (arg.find("--mode=") == 0)
        {
            parse_game_mode(arg.substr(7));
        }
        else if (arg.find("--steps=") == 0)
        {
            parse_steps_count(arg.substr(8));
        }
        else if (arg.find("--configs=") == 0)
        {
            parse_config_path(arg.substr(10));
        }
        else if (arg.find("--matrix=") == 0)
        {
            parse_matrix_path(arg.substr(9));
        }
        else
        {
            throw std::invalid_argument("Неизвестный аргумент: " + arg);
        }
    }

    if (game_mode == TOURNAMENT && strategy_names.size() < 4)
    {
        throw std::invalid_argument("Tournament mode requires min 4 strategies");
    }
    if (game_mode != TOURNAMENT && strategy_names.size() != 3)
    {
        throw std::invalid_argument("This mode requires exactly 3 strategies");
    }

}
