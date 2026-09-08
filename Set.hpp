#ifndef SET_HPP
#define SET_HPP

#include "Competition.hpp"

/**
 * A Set plays games until a player wins the set or the score reaches 6-6.
 * At 6-6, it plays a TieBreaker. The server changes after each game.
 */
class Set : public Competition {
public:
    Set(Player *player1, Player *player2);

    Score *play(Player *firstServer) override;
};

#endif
