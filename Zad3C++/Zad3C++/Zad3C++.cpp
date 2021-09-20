#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <sstream>

using namespace std;

void sort(int tab[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (tab[j - 1][1] > tab[j][1])
            {
                swap(tab[j - 1][0], tab[j][0]);
                swap(tab[j - 1][1], tab[j][1]);
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int a, b, c, d;
    int liczba = 0, max = 0, tab[101][2], lider = 0;

    string linia;
    fstream plik;
    cin >> a;
    cout << endl << " Od ";
    cin >> b;
    cout << endl << " Do ";
    cin >> c;  
    cout << endl << "lider: ";
    cin >> d;

    if (b > c) swap(b, c);
    if (c > 100 or b < 0) cin >> b >> c;
    if (a > 100) cin >> a;

    plik.open("plik.txt", ios::out | ios::trunc);
    if (plik.good() == true)
    {
        for (int i = 0; i < a; i++)
        {
            plik << rand() % (c - b) + b;
            plik.close();
        }      
    }

    for (int i = 0; i < 101; i++)
    {
        tab[i][0] = i;
        tab[i][1] = 0;
    }

    if (plik.good() == true)
    {
        while (!plik.eof())
        {
            getline(plik, linia);
            if (linia.size() > 0)
            {
                istringstream(linia) >> liczba;
            }
            else break;
            
            cout << liczba << "<-";
            tab[liczba][1]++;
        }
    }

    sort(tab, 101);

    for (int i = 1; i < 101; i++)
    {
        cout << tab[i][0] << " " << tab[i][1] << endl;
    }
    lider = 100 - d + 1;

    cout << tab[lider][0] << " " << tab[lider][1];
    
}

