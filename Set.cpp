#include "Set.hpp"

Set::Set(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

Score *Set::play(Player *firstServer)
{
    // TODO: Repeatedly use Game, alternating the server after every game.
    // If the score reaches 6-6, use TieBreaker and transfer ownership of its
    // returned score to SetScore. Return an owning SetScore pointer.
    (void)firstServer;
    return nullptr;
}
