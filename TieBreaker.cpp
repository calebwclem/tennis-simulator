#include "TieBreaker.hpp"
#include "TieBreakerScore.hpp"
#include "PointScore.hpp"
#include "Player.hpp"

TieBreaker::TieBreaker(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

Score *TieBreaker::play(Player *firstServer)
{
    // TODO: Play points in the required service order until TieBreakerScore
    // reports a winner. Return an owning pointer to that score.
    //(void)firstServer;
    Player *opponent = otherPlayer(firstServer);
    TieBreakerScore *tbScore = new TieBreakerScore(player1(), player2());

    //Play 1 point with first server:
    PointScore pointScore(firstServer, opponent);
    pointScore.addScore(firstServer->serveAPoint(opponent));
    tbScore->addScore(pointScore.getWinner());

    //Alternate to other server
    Player *server = opponent;
    opponent = otherPlayer(server);


    int serveCount = 1;
    //Play until winner alternating server every 2 points
    while(!tbScore->haveAWinner()){

        //Play a point
        PointScore ptScore(server, opponent);
        ptScore.addScore(server->serveAPoint(opponent));
        tbScore->addScore(ptScore.getWinner());

        //If this is the second point served, swap servers
        if(serveCount % 2 == 0){
            server = opponent;
            opponent = otherPlayer(server);
        }

        //Iterate serve number
        ++serveCount;
    }

    return tbScore;
}
