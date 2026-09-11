#include "Match.hpp"
#include "MatchScore.hpp"
#include "Set.hpp"

Match::Match(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

Score *Match::play(Player *firstServer)
{
    // TODO: Repeatedly use Set until MatchScore reports a winner. Alternate
    // the first server between sets and return an owning MatchScore pointer.
    MatchScore *matchScore = new MatchScore(player1(), player2());
    Player *server = firstServer;

    while(!matchScore->haveAWinner()){
        //Play a set
        Set set(player1(), player2());
        Score *setScore = set.play(server);
        matchScore->addSetScore(setScore);

        //Swap the server after every set
        server = otherPlayer(server);
    }
    return matchScore;
}
