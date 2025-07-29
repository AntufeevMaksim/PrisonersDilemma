#include "Traitor.hpp"
#include "StrategyFactory.hpp"
#include <memory>

IStrategy::Choice Traitor::make_turn()
{
    return BETRAY;
}

void Traitor::give_last_results(const std::vector<IStrategy::Choice>& last_choice)
{
    
}

struct TraitorRegister
{
    TraitorRegister()
    {
        StrategyFactory::instance().register_strategy("Traitor", []
                                                      { return std::make_unique<Traitor>(); });
    }
} traitorRegister;
