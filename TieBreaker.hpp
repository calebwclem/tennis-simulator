#ifndef TIE_BREAKER_HPP
#define TIE_BREAKER_HPP

#include "Competition.hpp"

/**
 * A TieBreaker has different winning and service-order rules from Game.
 * The first server serves once; the players then alternate two serves each.
 */
class TieBreaker : public Competition {
public:
    TieBreaker(Player *player1, Player *player2);

    Score *play(Player *firstServer) override;
};

#endif
