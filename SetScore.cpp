#include "SetScore.hpp"

#include <iostream>
#include <stdexcept>

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
    // TODO: Implement the ordinary set rule and the completed tie-break case.
    return false;
}

bool SetScore::shouldPlayATieBreaker() const
{
    // TODO: A tie-break is played when both players have won six games.
    return false;
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
    // Diagnostic output: useful while tracing the starter's call sequence.
    std::cout << "SetScore::print begins\n"
              << "Player A games = " << player1Score() << '\n'
              << "Player B games = " << player2Score() << '\n';
    if (tieScore != nullptr) {
        tieScore->print();
    }
    std::cout << "SetScore::print ends\n";
}
