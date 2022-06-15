#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <sstream>

using namespace std;

int main()
{
    srand(time(NULL));
    int liczba[100];
    int naj = 0;
    int b;
    int liczba_max = 0;
    int ilosc_pow = 0;
    string linia;
    fstream plik;

    plik.open("plik.txt", ios::out | ios::trunc);
    if (plik.good() == true)
    {
        for (int i = 0; i < 100; i++)
        {
            liczba[i] = rand() % 100 + 1;
            plik << liczba << "\n";
            linia += liczba[i];
        }      
        plik.close();
    }

    plik.open("plik.txt", ios::in);
    if (plik.good() == true)
    {     
        while (!plik.eof())
        {
            getline(plik, linia);
            cout << linia << endl;
            istringstream(linia) >> b;
            if (naj < b) naj = b;
        }     
        
        for (int i = 0; i < 100; i++)
        {
            if (liczba[i] > liczba_max)
            {
                liczba_max = liczba;
            }
        }

        cout << "Najczestsza liczba: " << liczba_max << " liczba powtorzen tej liczby: " << ilosc_pow << endl;
        cout << "Największa liczba to: " << naj << endl;
        plik.close();
    }
}

