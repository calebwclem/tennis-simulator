#include "PointScore.hpp"

#include <iostream>

PointScore::PointScore(Player *player1, Player *player2)
    : Score(player1, player2)
{
}

bool PointScore::haveAWinner() const
{
    return p1Score == 1 || p2Score == 1;
}

void PointScore::print() const
{
    std::cout << "PointScore::print begins\n"
              << "Player A score = " << player1Score() << '\n'
              << "Player B score = " << player2Score() << '\n'
              << "PointScore::print ends\n";
}
