#pragma once

#include <memory>
#include <string>
#include <vector>

class Strategy
{
    public:
    enum Choice
    {
        COOPERATE,
        BETRAY
    };

    virtual ~Strategy() = default;

    static std::unique_ptr<Strategy> create(const std::string& name);
    virtual void give_last_results(std::vector<Choice>& last_choice) = 0;
    virtual Choice make_turn() = 0;

};
