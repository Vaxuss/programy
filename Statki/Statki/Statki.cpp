#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

int strzal(int x, int y, int plansza[7][7], vector <int> statki[3])
{
    int zat = 0, id;

    if ((plansza[x][y] <= 3) && (plansza[x][y]) > 0)
    {
        if (plansza[x][y] == 1) // zatopiony
        {
            plansza[x][y] = 0;
            zat = 2;
        }
        else
        {
            for (int i = 1; i < statki[2].size(); i++)
            {
                if ((statki[0][i] == x) && (statki[1][i] == y))
                {
                    id = statki[2][i];
                    statki[0][i] = 0;
                    statki[1][i] = 0;
                    statki[2][i] = 0;
                    plansza[x][y] = 0;
                }
            }
            for (int i = 1; i < statki[2].size(); i++)
            {
                if (statki[2][i] == id)
                    plansza[statki[0][i]][statki[1][i]]--;
            }
            zat = 1;
        }      
    }
    return zat;
}

void sort(int tab[][2], int n)
{
    int j = 1, k;
    while (j <= n) 
    {
        for (k = j; k > 0; k--)
        {
            if (tab[k][0] > tab[k - 1][0]) {
                swap(tab[k][0], tab[k - 1][0]);
                swap(tab[k][1], tab[k - 1][1]);
            }
            else break;
        }
        j++;
    }
}

void umiesc_statek_komputer(int a, int plansza[7][7], vector <int> statki[3]) {

    bool ok = false;
    int x, y, z, id;

    while (ok == false) {
        ok = true;
        x = rand() % 5 + 1;
        y = rand() % 5 + 1;
        z = rand() % 1;

        if (z == 0) { //poziomo
            if (x > 6 - a) {
                ok = false;
            }
            else
                for (int i = x; i < x + a; i++)
                    if (plansza[i][y] != 0) ok = false;
        }
        else if (z == 1) { //pionowo
            if (y > 6 - a) {
                ok = false;
            }
            else
                for (int i = y; i < y + a; i++)
                    if (plansza[x][i] != 0) ok = false;
        }
    }

    id = statki[2][statki->size() - 1];
    id++;
    if (z == 0) {
        for (int i = x; i < x + a; i++) {
            statki[0].push_back(i);
            statki[1].push_back(y);
            statki[2].push_back(id);
        }
    }
    else {
        for (int i = y; i < y + a; i++) {
            statki[0].push_back(x);
            statki[1].push_back(i);
            statki[2].push_back(id);
        }
    }
    for (int i = 1; i <= a; i++) {
        int xx, yy;
        xx = statki[0][statki->size() - i];
        yy = statki[1][statki->size() - i];
        for (int k = xx - 1; k <= xx + 1; k++)
            for (int l = yy - 1; l <= yy + 1; l++)
                plansza[k][l] = 9;
    }
    for (int i = 1; i <= a; i++)
        plansza[statki[0][statki->size() - i]][statki[1][statki->size() - i]] = a;

}

void umiesc_statek(int a, int plansza[7][7], vector <int> statki[3]) {

    bool ok = false;
    int x, y, z, id;

    while (ok == false) {
        ok = true;
        cout << "podaj " << a << " - masztowiec: ";
        cin >> x >> y >> z;
        if (z == 0) { //poziomo
            if (x > 6 - a) {
                cout << "podales zla lokalizacje dla wspolrzednej X" << "\n";
                ok = false;
            }
            else
                for (int i = x; i < x + a; i++)
                    if (plansza[i][y] != 0) ok = false;
        }
        else if (z == 1) { //pionowo
            if (y > 6 - a) {
                cout << "podales zla lokalizacje dla wspolrzednej Y" << "\n";
                ok = false;
            }
            else
                for (int i = y; i < y + a; i++)
                    if (plansza[x][i] != 0) ok = false;
        }
    }
    
    id = statki[2][statki->size() - 1];
    id++;
    if (z == 0) {
        for (int i = x; i < x + a; i++) {
            statki[0].push_back(i);
            statki[1].push_back(y);
            statki[2].push_back(id);
        }
    }
    else {
        for (int i = y; i < y + a; i++) {
            statki[0].push_back(x);
            statki[1].push_back(i);
            statki[2].push_back(id);
        }
    }
    for (int i = 1; i <= a; i++) {
        int xx, yy;
        xx = statki[0][statki->size() - i];
        yy = statki[1][statki->size() - i];
        for (int k = xx - 1; k <= xx + 1; k++)
            for (int l = yy - 1; l <= yy + 1; l++)
                plansza[k][l] = 9;
    }
    for (int i = 1; i <= a; i++)
        plansza[statki[0][statki->size() - i]][statki[1][statki->size() - i]] = a;
}

int main()
{
    srand(time(NULL));
    const int n = 7;
    int zatopione = 0, zatopionyk = 0, komputer[25][2] = {0}, licznik = 0; 
    vector <int> statki1[3], statki2[3];
    string plansza2[n][n];
    //zerowania tablic
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {          
            plansza2[i][j] = "*";         
        }   

    for(int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
        {
            komputer[licznik][0] = i;
            komputer[licznik][1] = j;
            licznik++;
        }

    int plansza1[n][n] = { 0 }, plansza_komp[n][n] = { 0 };

    for (int i = 0; i < 3; i++) {
        statki1[i].push_back(0);
        statki2[i].push_back(0);
    }
    //wstawienie statków przez gracza
    umiesc_statek(3, plansza1, statki1);
    umiesc_statek(2, plansza1, statki1);
    umiesc_statek(1, plansza1, statki1);
    umiesc_statek(1, plansza1, statki1);

    //wstawianie komputera
    umiesc_statek_komputer(3, plansza_komp, statki2);
    umiesc_statek_komputer(2, plansza_komp, statki2);
    umiesc_statek_komputer(1, plansza_komp, statki2);
    umiesc_statek_komputer(1, plansza_komp, statki2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << plansza_komp[j][i] << " ";
        cout << endl;
    }
    bool a = true;

    while ((zatopione < 4)or(zatopionyk < 4))
    {
        int x, y, z, los;
        
        if (a == true) {
            cin >> x >> y;

            z = strzal(x, y, plansza_komp, statki2);

            if (z == 2)
            {
                cout << "Zatopiony" << endl;
                plansza2[x][y] = "X";
                zatopione++;
                a = true;
            }
            else if (z == 1)
            {
                cout << "Trafiony" << endl;
                plansza2[x][y] = "X";
                a = true;
            }
            else {
                plansza2[x][y] = "O";
                a = false;
            }

            for (int i = 1; i <= 5; i++) {
                for (int j = 1; j <= 5; j++)
                {
                    cout << plansza2[j][i] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            los = rand() % licznik;
            x = komputer[los][0];
            y = komputer[los][1];
            z = strzal(x, y, plansza1, statki1);

            komputer[los][0] = 9;
            komputer[los][1] = 9;
            cout << endl << "K:" << x << " " << y << endl;
            if (z == 2) {
                cout << endl << "Zatopiony nasz" << endl;
                zatopionyk++;
                a == false;
            }
            else if (z == 1) {
                cout << endl << "Trafiony nasz" << endl;
                a == false;
            }
            else {
                cout << endl << "pudlo" << endl;
                a = true;
            }

            sort(komputer, 25);
            licznik--;
        }
    }

    if (zatopione == 4) cout << "Wygral gracz";
    else cout << "Wygral komputer";
}

