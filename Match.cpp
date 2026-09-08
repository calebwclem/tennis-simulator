#include "Match.hpp"

Match::Match(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

Score *Match::play(Player *firstServer)
{
    // TODO: Repeatedly use Set until MatchScore reports a winner. Alternate
    // the first server between sets and return an owning MatchScore pointer.
    (void)firstServer;
    return nullptr;
}
