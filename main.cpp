#include <cstdlib>
#include <iostream>
#include <limits>

#include "Game.hpp"
#include "Player.hpp"
#include "Score.hpp"

namespace {

bool readSeed(unsigned int &seed)
{
    long long input = 0;
    std::cout << "Enter the seed value for the random number generator? ";
    if (!(std::cin >> input) || input < 0
        || input > std::numeric_limits<unsigned int>::max()) {
        return false;
    }
    seed = static_cast<unsigned int>(input);
    return true;
}

bool readProbability(const char *playerName, int &probability)
{
    std::cout << "Enter " << playerName
              << "'s probability of winning a served point (1-99): ";
    return static_cast<bool>(std::cin >> probability)
        && probability >= 1 && probability <= 99;
}

} // namespace

int main()
{
    unsigned int seed = 0;
    int playerAProbability = 0;
    int playerBProbability = 0;

    if (!readSeed(seed)) {
        std::cerr << "Error: the seed must be a nonnegative integer.\n";
        return 1;
    }
    if (!readProbability("Player A", playerAProbability)) {
        std::cerr << "Error: Player A's probability must be from 1 through 99.\n";
        return 1;
    }
    if (!readProbability("Player B", playerBProbability)) {
        std::cerr << "Error: Player B's probability must be from 1 through 99.\n";
        return 1;
    }

    std::srand(seed);
    Player playerA(playerAProbability);
    Player playerB(playerBProbability);

    // Diagnostic starter: this completed vertical slice shows how a
    // Competition returns a polymorphic Score and how ownership is released.
    std::cout << "\nDiagnostic run: Game::play followed by GameScore::print\n";
    Game game(&playerA, &playerB);
    Score *score = game.play(&playerA);
    score->print();
    delete score;

    // TODO: Replace the diagnostic Game with a Match, play the entire match,
    // and print the transcript required by the project specification.

    return 0;
}
