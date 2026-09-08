#ifndef PLAYER_HPP
#define PLAYER_HPP

/** A player is described by the probability of winning a served point. */
class Player {
public:
    explicit Player(int probabilityOfWinningServe);

    void setProbabilityOfWinningAServe(int probability);
    int getProbabilityOfWinningAServe() const;

    // Returns a non-owning pointer to the player who won the point.
    Player *serveAPoint(Player *opponent);

private:
    int probOfWinningAServe;

    static int getARandomNumber(int low, int high);
    static bool isValidProbability(int probability);
};

#endif
