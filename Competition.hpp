#ifndef COMPETITION_HPP
#define COMPETITION_HPP

class Player;
class Score;

/**
 * Abstract base class for a competitive activity between two players.
 *
 * The Player pointers are non-owning: the players must remain alive while
 * the Competition is used. play() returns an owning Score pointer; the
 * caller must eventually delete it.
 */
class Competition {
public:
    Competition(Player *player1, Player *player2);
    virtual ~Competition() = default;

    Player *player1() const;
    Player *player2() const;

    virtual Score *play(Player *firstServer) = 0;

protected:
    Player *otherPlayer(Player *player) const;

private:
    Player *p1;
    Player *p2;
};

#endif
