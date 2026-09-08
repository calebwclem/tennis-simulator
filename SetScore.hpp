#ifndef SET_SCORE_HPP
#define SET_SCORE_HPP

#include "Score.hpp"

/**
 * A set is won with at least six games and a two-game lead. At 6-6, a
 * tie-break determines the winner. SetScore owns its tie-break score.
 */
class SetScore : public Score {
public:
    SetScore(Player *player1, Player *player2);
    ~SetScore() override;

    bool haveAWinner() const override;
    bool shouldPlayATieBreaker() const;

    // Takes ownership of score.
    void addTieScore(Score *score);
    void print() const override;

private:
    Score *tieScore;
};

#endif
