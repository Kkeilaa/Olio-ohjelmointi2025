#include <iostream>
#include "Game.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int maxNumber) {

    cout<<"CONSTRUCTOR"<<endl;
    cout<<"Maximum number is = "<<maxNumber<<endl;
    play();

}

Game::~Game()
{

    cout<<"DESTRUCTOR"<<endl;
}

void Game::play(){

    cout<<"GAME STARTS"<<endl;

    time_t seed = time(nullptr);
    srand(seed);
    randomNumber = rand() % maxNumber + 1;

    //Printti missä näkyy oikea nro.
    cout<<"Test print for the correct number: "<<randomNumber<<endl;



    while(1){

        cout << "Give a guess between 1-" << maxNumber<< ": ";
        cin >> playerGuess;

        if(playerGuess==randomNumber){

            cout << "Correct answer!" << endl;

            numOfGuesses += 1;

            cout<<"GAME ENDS"<<endl;

            break;

        }

        if(playerGuess>randomNumber){

            //Peli ei laske arvausta, jos arvo on suurempi kuin mahdollinen maksimiarvo
            if(playerGuess>maxNumber)
            {
                cout << "The guess cannot be bigger than "
                     << maxNumber << endl;
            }

            else
            {
                cout << "Your guess is too big." << endl;
                numOfGuesses += 1;
            }

        }

        if(playerGuess<randomNumber){
            cout << "Your guess is too small." << endl;
            numOfGuesses += 1;

        }
    }

    printGameResult();

}


void Game::printGameResult()
{

    cout << "You guessed the right answer " << randomNumber
         << " after " << numOfGuesses << " guesses." << endl;

}
