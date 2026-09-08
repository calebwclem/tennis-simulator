#include "Competition.hpp"

#include <stdexcept>

#include "Player.hpp"

Competition::Competition(Player *player1, Player *player2)
    : p1(player1), p2(player2)
{
    if (p1 == nullptr || p2 == nullptr || p1 == p2) {
        throw std::invalid_argument(
            "A competition requires two distinct, non-null players.");
    }
}

Player *Competition::player1() const
{
    return p1;
}

Player *Competition::player2() const
{
    return p2;
}

Player *Competition::otherPlayer(Player *player) const
{
    return player == p1 ? p2 : p1;

    throw std::invalid_argument("The server is not in this competition.");
}
