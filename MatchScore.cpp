#include "MatchScore.hpp"

#include <iostream>

MatchScore::MatchScore(Player *player1, Player *player2)
    : Score(player1, player2), scores{}, setNumber(0)
{
}

MatchScore::~MatchScore()
{
    for (int i = 0; i < setNumber; ++i) {
        delete scores[i];
    }
}

bool MatchScore::haveAWinner() const
{
    // TODO: A match ends when either player has won three sets.
    return false;
}

void MatchScore::addSetScore(Score *score)
{
    // TODO: Validate score and capacity, record its winner, store score, and
    // transfer ownership to this MatchScore only after validation succeeds.
    (void)score;
}

void MatchScore::print() const
{
    // Diagnostic output: students will adapt this to the final transcript.
    std::cout << "MatchScore::print begins\n";
    for (int i = 0; i < setNumber; ++i) {
        scores[i]->print();
    }
    std::cout << "Player A sets = " << player1Score() << '\n'
              << "Player B sets = " << player2Score() << '\n'
              << "MatchScore::print ends\n";
}
