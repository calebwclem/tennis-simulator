#ifndef MATCH_SCORE_HPP
#define MATCH_SCORE_HPP

#include "Score.hpp"

/**
 * A match is won by the first player to win three sets. MatchScore owns each
 * subordinate set score passed to addSetScore().
 */
class MatchScore : public Score {
public:
    MatchScore(Player *player1, Player *player2);
    ~MatchScore() override;

    bool haveAWinner() const override;

    // Takes ownership of score.
    void addSetScore(Score *score);
    void print() const override;

private:
    static constexpr int maximumSets = 5;
    Score *scores[maximumSets];
    int setNumber;
};

#endif
