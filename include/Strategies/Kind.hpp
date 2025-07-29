#pragma once

#include "IStrategy.hpp"

class Kind : public IStrategy
{
    public:
    Choice make_turn() override;
    void give_last_results(const std::vector<Choice>& last_choice) override;
};

