#pragma once

#include "Strategy.hpp"

class Traitor : public Strategy
{
    public:
    Choice make_turn() override;
    void give_last_results(std::vector<Choice>& last_choice) override;
};