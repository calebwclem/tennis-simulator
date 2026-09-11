#include "TieBreakerScore.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>

TieBreakerScore::TieBreakerScore(Player *player1, Player *player2)
    : Score(player1, player2)
{
}


bool TieBreakerScore::haveAWinner() const{

    //A tiebreaker is won at 7 pts minimum, winning by 2.
    return (p1Score >= 7 || p2Score >= 7) 
            && std::abs(p1Score - p2Score) >=2;
}

void TieBreakerScore::print() const{
    std::cout << std::setw(16) << "(tie breaker  "
              << player1Score() << '-' << player2Score() 
              << ')';
}