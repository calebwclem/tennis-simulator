#include "SetScore.hpp"

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>

SetScore::SetScore(Player *player1, Player *player2)
    : Score(player1, player2), tieScore(nullptr)
{
}

SetScore::~SetScore()
{
    delete tieScore;
}

bool SetScore::haveAWinner() const
{
    int p1 = player1Score();
    int p2 = player2Score();

    //If a tie breaker has been played, the winner won:
    if(tieScore != nullptr)
    {
        return tieScore->haveAWinner();
    }

    //Otherwise, we play the game as normal, and if both players have 6 games, we play a tie breaker:
    if((p1 >= 6 || p2 >=6) && std::abs(p1 - p2) >= 2)
    {
        return true;
    }

    return false;
}

bool SetScore::shouldPlayATieBreaker() const
{
    //We only play a tie breaker if both players have 6 games, and we haven't played a tie breaker yet:
    return player1Score() == 6 && player2Score() == 6;
}

void SetScore::addTieScore(Score *score)
{
    if (score == nullptr) {
        throw std::invalid_argument("The tie-break score must not be null.");
    }
    if (tieScore != nullptr) {
        throw std::logic_error("This set already has a tie-break score.");
    }

    // Ownership transfers only after all validation succeeds.
    addScore(score->getWinner());
    tieScore = score;
}

void SetScore::print() const
{
   std::cout << std::setw(10) << player1Score()
             << std::setw(18) << player2Score();
    if(tieScore!= nullptr){
        tieScore->print();
    }
    std::cout << '\n';
}
