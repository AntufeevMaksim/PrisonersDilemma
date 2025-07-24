#pragma once

#include <vector>
#include <string>

class InputData
{
    public:

    enum GameMode
    {
        FAST,
        DETAILED
    };

    InputData(int argc, char* argv[]);
    const std::vector<std::string>& get_strategy_names() const;
    GameMode get_mode() const;
    size_t get_steps_count() const;
    const std::string& get_config_path() const;
    const std::string& get_matrix_path() const;

    private:
    std::vector<std::string> strategy_names;
    GameMode game_mode;
    size_t steps_count;
    std::string config_path;
    std::string matrix_path;

    
};
