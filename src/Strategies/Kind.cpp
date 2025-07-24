#include "Kind.hpp"


Strategy::Choice Kind::make_turn()
{
    return COOPERATE;
}

void Kind::give_last_results(std::vector<Strategy::Choice>& last_choice)
{
    
}