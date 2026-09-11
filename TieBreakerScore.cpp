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
    /*std::cout << "TieBreakerScore::print begins\n"
              << "Player A score = " << player1Score() << '\n'
              << "Player B score = " << player2Score() << '\n'
              << "TieBreakerScore::print ends\n";*/
    std::cout << std::setw(16) << "(tue breaker "
              << player1Score() << '-' << player2Score() 
              << ')';
}
