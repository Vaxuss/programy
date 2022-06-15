#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    srand(time(NULL));
    int ilosc, zakres_max, zakres_min, min, max;

    cout << "Wpisz ilosc liczb do wylosowania: ";
    cin >> ilosc;
    cout << endl << "Wybierz maksymalna liczbe do wylosowania: ";
    cin >> zakres_max;
    cout << endl << "Wybierz minimalna liczbe do wylosowania: ";
    cin >> zakres_min;

    int* liczby = new int[ilosc];

    for (int i = 0; i < ilosc; i++)
    {
        liczby[i] = rand() % (zakres_max - zakres_min + 1) + zakres_min;
    }

    for (int j = 0; j < ilosc - 1; j++)
    {
        for (int i = 0; i < ilosc - 1; i++)
        {
            if (liczby[i] > liczby[i + 1])
            {
                swap(liczby[i], liczby[i + 1]);                
            }
        }
    }

    for (int i = 0; i < ilosc; i++)
    {
        cout << liczby[i] << " ";
    }

    cout << endl << "Max: " << liczby[ilosc - 1] << endl;

    cout << "Min: " << liczby[0];


}


