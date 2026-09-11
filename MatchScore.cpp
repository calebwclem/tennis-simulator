#include "MatchScore.hpp"

#include <iostream>
#include <iomanip>

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
    //A match ends when one player has won at least 3 sets
    return player1Score() >= 3 || player2Score() >= 3;
}

void MatchScore::addSetScore(Score *score)
{
    if(score == nullptr){
        throw std::invalid_argument("The set score must not be null.");
    }
    if(setNumber >= maximumSets){
        throw std::logic_error("This match already has the maximum number of sets:");
    }

    addScore(score->getWinner());
    scores[setNumber] = score;
    ++setNumber;
}

void MatchScore::print() const
{
    for(int i = 0; i < setNumber; ++i){
        std::cout << std::setw(7) << (i + 1);
        scores[i]->print();
    }

    if(getWinner() == player1()){
        std::cout << "\nPlayer A wins the match " 
                  << player1Score() << " sets to "
                  << player2Score() << '\n';
    }
    else{
        std::cout << "\nPlayer B wins the match "
                  << player2Score() << " sets to "
                  << player1Score() << '\n';
    }

}