#include "Game.hpp"

#include "GameScore.hpp"
#include "Player.hpp"
#include "PointScore.hpp"

Game::Game(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

Score *Game::play(Player *server)
{
    // The returned pointer transfers ownership to the caller.
    GameScore *gameScore = new GameScore(player1(), player2());
    Player *opponent = otherPlayer(server);

    while (!gameScore->haveAWinner()) {
        // A point score is small and temporary, so it can live on the stack.
        PointScore pointScore(player1(), player2());
        pointScore.addScore(server->serveAPoint(opponent));
        gameScore->addScore(pointScore.getWinner());
    }

    return gameScore;
}
