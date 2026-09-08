#include "Score.hpp"

#include <stdexcept>

#include "Player.hpp"

Score::Score(Player *player1, Player *player2)
    : p1Score(0), p2Score(0), p1(player1), p2(player2)
{
    if (p1 == nullptr || p2 == nullptr || p1 == p2) {
        throw std::invalid_argument(
            "A score requires two distinct, non-null players.");
    }
}

Player *Score::player1() const
{
    return p1;
}

Player *Score::player2() const
{
    return p2;
}

int Score::player1Score() const
{
    return p1Score;
}

int Score::player2Score() const
{
    return p2Score;
}

Player *Score::getWinner() const
{
    if (!haveAWinner()) {
        throw std::logic_error("A winner was requested before the score ended.");
    }
    return p1Score > p2Score ? p1 : p2;
}

bool Score::areTied() const
{
    return p1Score == p2Score;
}

void Score::addScore(Player *player)
{
    if (player == p1) {
        ++p1Score;
    } else if (player == p2) {
        ++p2Score;
    } else {
        throw std::invalid_argument("The scoring player is not in this score.");
    }
}
