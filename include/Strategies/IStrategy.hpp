#pragma once

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

class IStrategy
{
    public:
    enum Choice
    {
        COOPERATE,
        BETRAY
    };

    virtual ~IStrategy() = default;

    virtual void give_last_results(const std::vector<Choice>& last_choice) = 0;
    virtual Choice make_turn() = 0;
};
