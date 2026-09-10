#include "Set.hpp"
#include "Game.hpp"
#include "SetScore.hpp"
#include "TieBreaker.hpp"

Set::Set(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

Score *Set::play(Player *firstServer)
{
    // TODO: Repeatedly use Game, alternating the server after every game.
    // If the score reaches 6-6, use TieBreaker and transfer ownership of its
    // returned score to SetScore. Return an owning SetScore pointer.

    SetScore *setScore = new SetScore(player1(), player2());
    Game game(player1(), player2());
    Player *server = firstServer;

    while(!setScore->haveAWinner()){
        //If a tie breaker is necessary, play a tie breaker!
        if(setScore->shouldPlayATieBreaker()){
           TieBreaker tieBreaker(player1(), player2());
           setScore->addTieScore(tieBreaker.play(server));
        }//Once a tie breaker has been played, we have a winner
        // so haveAWinner is now true!

        // Othwerise, play the set as normal!
        else{
            //Play a game
            Score *gameScore = game.play(server);
            setScore->addScore(gameScore->getWinner());
            //delete gameScore pointer
            delete gameScore;

            //swap server to play the next game
            server = otherPlayer(server);
        }
    }

    (void)firstServer;
    return nullptr;
}
