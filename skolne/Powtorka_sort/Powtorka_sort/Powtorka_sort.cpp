#include <iostream>

using namespace std;

class Tablica {
public:
    int tab[10];
    int wprowadzone;
    int max = 0;

    Tablica() {   
    }

    void wprowadzDane();
    /*
    nazwa funkcji: wprowadzDane

    parametry wejściowe: brak

    wartość zwracana: funkcja przypisuje wartości wpisane z klawiatury do tablicy.
    */
    void Max();
    /*
    nazwa funkcji: Max

    parametry wejściowe: brak

    wartość zwracana: funkcja znajduje największą liczbe w tablicy
    */
    void Sort();
    /*
    nazwa funkcji: Max

    parametry wejściowe: brak

    wartość zwracana: funkcja sortuje tablicę z wykorzystaniem liczby maksymalnej
    */

};

int main()
{
    Tablica tab;
    tab.wprowadzDane();


    for (int i = 0; i < 10; i++) {
        cout << tab.tab[i] << " ";
    }

    tab.Max();

    cout << endl;

    tab.Sort();

    for (int i = 0; i < 10; i++) {
        cout << tab.tab[i] << " ";
    }

    cout << endl << "Najwieksza liczba to: " << tab.max << endl;

}

void Tablica::wprowadzDane()
{
    for (int i = 0; i < 10; i++) {
        cout << "podaj liczbe: " << i+1 << endl;
        cin >> wprowadzone;
        tab[i] = wprowadzone;
    }
}

void Tablica::Sort()
{
    int i = 0;
    int a;

    for (int j = 1; j < 10; j++) {
        if (max >= tab[j]) {
            swap(tab[j], tab[9]);
        }
    }
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (tab[i] > tab[j]) {
                swap(tab[i], tab[j]);
            }
        }
    }
}

void Tablica::Max()
{
    int a;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tab[j] > max) {
                max = tab[j];
                a = j;
            }
        }
    }
    swap(tab[0], tab[a]);
}

