#include "Traitor.hpp"


Strategy::Choice Traitor::make_turn()
{
    return BETRAY;
}

void Traitor::give_last_results(std::vector<Strategy::Choice>& last_choice)
{
    
}