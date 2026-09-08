#ifndef SCORE_HPP
#define SCORE_HPP

class Player;

/**
 * Abstract base class for scores at every level of the match.
 *
 * Score does not own its Player pointers. Derived score classes may own
 * subordinate scores; those ownership rules are documented in those classes.
 */
class Score {
public:
    Score(Player *player1, Player *player2);
    virtual ~Score() = default;

    Player *player1() const;
    Player *player2() const;
    int player1Score() const;
    int player2Score() const;

    Player *getWinner() const;
    bool areTied() const;
    void addScore(Player *player);

    virtual bool haveAWinner() const = 0;
    virtual void print() const = 0;

protected:
    int p1Score;
    int p2Score;

private:
    Player *p1;
    Player *p2;
};

#endif
