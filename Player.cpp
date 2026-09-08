#include "Player.hpp"

#include <cstdlib>
#include <stdexcept>

Player::Player(int probabilityOfWinningServe)
    : probOfWinningAServe(0)
{
    setProbabilityOfWinningAServe(probabilityOfWinningServe);
}

void Player::setProbabilityOfWinningAServe(int probability)
{
    if (!isValidProbability(probability)) {
        throw std::invalid_argument(
            "A service probability must be from 1 through 99.");
    }
    probOfWinningAServe = probability;
}

int Player::getProbabilityOfWinningAServe() const
{
    return probOfWinningAServe;
}

Player *Player::serveAPoint(Player *opponent)
{
    if (opponent == nullptr || opponent == this) {
        throw std::invalid_argument(
            "A point requires a distinct, non-null opponent.");
    }

    const int draw = getARandomNumber(1, 100);
    return draw <= probOfWinningAServe ? this : opponent;
}

int Player::getARandomNumber(int low, int high)
{
    return std::rand() % (high - low + 1) + low;
}

bool Player::isValidProbability(int probability)
{
    return probability >= 1 && probability <= 99;
}
