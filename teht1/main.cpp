#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum);


int main(){


    //Pelin suurin arvattava numero
    int x = 42;

    //Talletetaan pelin palauttama arvausten määrä muuttujaan
    int tulos = game(x);

    cout << "Arvausten määrä: " << tulos << endl;

    return 0;
}


//Funktiot

int game(int maxnum){

    //Siemen
    time_t seed = time(nullptr);
    srand(seed);
    //Arvotaan numero
    int arvottunro = rand() % maxnum + 1;

    //Testi tulostus
    cout << "Testi tulostus. Oikea arvo=" << arvottunro
         << endl;

    int arvaukset = 0;

    //Luupataan kunnes numero on arvattu oikein.
    while(1){

        cout << "Arvaa numero väliltä 1-" << maxnum << ": ";

        int arvaus = 0;
        cin >> arvaus;

        if(arvaus==arvottunro){

            cout << "Oikea vastaus!" << endl;
            arvaukset += 1;
            //Palautetaan funktion arvoksi arvatut kerrat.
            return arvaukset;
        }

        if(arvaus>arvottunro){

            //Peli ei laske arvausta, jos arvo on suurempi kuin mahdollinen maksimi arvo
            if(arvaus>maxnum)
            {
                cout << "Luku ei voi olla suurempi kuin "
                     << maxnum << endl;
            }

            else
            {
                cout << "Luku on pienempi" << endl;
                arvaukset += 1;
            }

        }

        if(arvaus<arvottunro){
            cout << "Luku on suurempi" << endl;
            arvaukset += 1;
        }

    }

}
