#pragma once

#include "IStrategy.hpp"

class Traitor : public IStrategy
{
    public:
    Choice make_turn() override;
    void give_last_results(const std::vector<Choice>& last_choice) override;
};