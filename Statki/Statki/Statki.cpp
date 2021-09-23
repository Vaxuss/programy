//tablicza dwu 5 na 5
// 3-masztowce -> id: 3
// 2-masztowce -> id: 2
// 1-masztowce -> id: 1
// losowe pozycje statków

// 9 - pola przystające do statku
// 8 - strzał gracza

//druga tablica ilosc slotów zajmujących przez statki, na 3 wartośći(x,y,id statku)

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
    int plansza1[5][5], x, y, z, id;//z -> rodzaj statku
    vector <int> statki1[3];
    bool ok = false;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            plansza1[i][j] == 0;
        }
    }

    for (int i = 0; i < 3; i++) statki1[i].push_back(0);

    while (ok == false)
    {
        ok == true;
        cout << "podaj 3-masztowiec: ";
        cin >> x >> y >> z;

        if (z == 0) {
            if (x > 3)
            {
                cout << "Podales zla lokalizacje dla X";
                ok = false;
            }
            else
            {
                for (int i = x - 1; i <= x + 2; i++)
                {
                    if (plansza1[i][y - 1] != 0) ok = false;
                }
            }
        }
        else if (z == 1)
        {
            if (x > 3)
            {
                cout << "Podales zla lokalizacje dla Y";
                ok = false;
            }
            else
            {
                for (int i = y - 1; i <= y + 2; i++)
                {
                    if (plansza1[x-1][i] != 0) ok = false;
                }
            }
        }

    }
    if (ok == true)
    {
        id = statki1[2][statki1->size() - 1];
        id++;
        if (z == 0)
        {         
            for (int i = x - 1; i <= x + 2; i++)
            {
                statki1[0].push_back(i);
                statki1[1].push_back(y);
                statki1[2].push_back(id);
            }
        }
        else
        {
            id = statki1[2][statki1->size() - 1];
            id++;
            for (int i = x - 1; i <= y + 2; i++)
            {
                statki1[0].push_back(x);
                statki1[1].push_back(i);
                statki1[2].push_back(id);
            }
        }
    }
}


