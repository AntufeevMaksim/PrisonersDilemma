#pragma once

#include <vector>
#include <string>

class InputData
{
    public:

    enum Mode
    {
        FAST,
        DETAILED
    };

    InputData(int argc, char* argv[]);
    std::vector<std::string> get_strategy_names();
    Mode get_mode();
    size_t get_steps_count();
    std::string get_config_path();
    std::string get_matrix_path();

    
};
