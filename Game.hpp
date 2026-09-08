#ifndef GAME_HPP
#define GAME_HPP

#include "Competition.hpp"

/**
 * A Game repeatedly plays points with the same server until GameScore
 * reports a winner. This completed class is a model for the TODO classes.
 */
class Game : public Competition {
public:
    Game(Player *player1, Player *player2);

    Score *play(Player *server) override;
};

#endif
