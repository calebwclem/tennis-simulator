#include "GameScore.hpp"

#include <cstdlib>
#include <iostream>

GameScore::GameScore(Player *player1, Player *player2)
    : Score(player1, player2)
{
}

bool GameScore::haveAWinner() const
{
    return (p1Score >= 4 || p2Score >= 4)
        && std::abs(p1Score - p2Score) >= 2;
}

void GameScore::print() const
{
    std::cout << "GameScore::print begins\n"
              << "Player A score = " << player1Score() << '\n'
              << "Player B score = " << player2Score() << '\n'
              << "GameScore::print ends\n";
}
