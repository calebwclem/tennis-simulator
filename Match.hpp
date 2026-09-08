#ifndef MATCH_HPP
#define MATCH_HPP

#include "Competition.hpp"

/**
 * A Match plays sets until one player has won three. Under the assignment's
 * simplified rule, the first server alternates between sets.
 */
class Match : public Competition {
public:
    Match(Player *player1, Player *player2);

    Score *play(Player *firstServer) override;
};

#endif
