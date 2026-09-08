#ifndef GAME_SCORE_HPP
#define GAME_SCORE_HPP

#include "Score.hpp"

/** A game requires at least four points and a lead of two points. */
class GameScore : public Score {
public:
    GameScore(Player *player1, Player *player2);

    bool haveAWinner() const override;
    void print() const override;
};

#endif
