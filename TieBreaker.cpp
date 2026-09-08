#include "TieBreaker.hpp"

TieBreaker::TieBreaker(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

Score *TieBreaker::play(Player *firstServer)
{
    // TODO: Play points in the required service order until TieBreakerScore
    // reports a winner. Return an owning pointer to that score.
    (void)firstServer;
    return nullptr;
}
