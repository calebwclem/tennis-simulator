#ifndef TIE_BREAKER_SCORE_HPP
#define TIE_BREAKER_SCORE_HPP

#include "Score.hpp"

/** A tie-break requires at least seven points and a lead of two points. */
class TieBreakerScore : public Score {
public:
    TieBreakerScore(Player *player1, Player *player2);
    //~TieBreakerScore() override;

    // TODO (intentional abstract-class exercise): Score declares two pure
    // virtual functions. Declare and then define the overrides that make
    // TieBreakerScore concrete.

    bool haveAWinner() const override;
    void print() const override;
};

#endif