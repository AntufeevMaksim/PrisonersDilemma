#include "Kind.hpp"
#include "StrategyFactory.hpp"
#include <memory>

IStrategy::Choice Kind::make_turn()
{
    return COOPERATE;
}

void Kind::give_last_results(const std::vector<IStrategy::Choice> &last_choice)
{
}

struct KindRegister
{
    KindRegister()
    {
        StrategyFactory::instance().register_strategy("Kind", []
                                                      { return std::make_unique<Kind>(); });
    }
} kindRegister;
