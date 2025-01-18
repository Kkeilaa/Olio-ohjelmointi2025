#ifndef GAME_H
#define GAME_H

class Game
{

public:

    Game(int maxNumber = 42);
    ~Game();
    void play();


private:

    int maxNumber = 42;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

    void printGameResult();

};

#endif // GAME_H
