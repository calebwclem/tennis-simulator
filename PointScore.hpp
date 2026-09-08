#ifndef POINT_SCORE_HPP
#define POINT_SCORE_HPP

#include "Score.hpp"

/** A point has a winner as soon as either player has scored once. */
class PointScore : public Score {
public:
    PointScore(Player *player1, Player *player2);

    bool haveAWinner() const override;
    void print() const override;
};

#endif
