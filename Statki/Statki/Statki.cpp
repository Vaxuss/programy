#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

void umiesc_statek(int a, int plansza[7][7], vector <int> statki[3]) {

    bool ok = false;
    int x, y, z, id;

    while (ok == false) {
        ok = true;
        cout << "podaj " << a << " - masztowiec: ";
        cin >> x >> y >> z;

        if (z == 0) { //poziomo
            if (x > 6 - a) {
                cout << "podales zla lokalizacje dla wspolrzednej X";
                ok = false;
            }
            else
                for (int i = x; i < x + a; i++)
                    if (plansza[i][y] != 0) ok = false;
        }
        else if (z == 1) { //pionowo
            if (y > 6 - a) {
                cout << "podales zla lokalizacje dla wspolrzednej Y";
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

void umiesc_statek_k(int a, int plansza[7][7], vector <int> statki[3]) {

    bool ok = false;
    int x, y, z, id;

    while (ok == false) {
        ok = true;
        x = rand() % 5 + 1;
        y = rand() % 5 + 1;
        z = rand() % 2;
        /*cout << x << " " << y << " " << z << " " << a << endl;*/
        if (z == 0) { //poziomo
            if (x > 6 - a) ok = false;
            else
                for (int i = x; i < x + a; i++)
                    if (plansza[i][y] != 0) ok = false;
        }
        else if (z == 1) { //pionowo
            if (y > 6 - a) ok = false;
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

int strzal(int x, int y, int plansza[7][7], vector <int> statki[3]) {
    int zat = 0, id;
    if ((plansza[x][y] <= 3) && (plansza[x][y] >= 1)) {
        if (plansza[x][y] == 1) { // zatopiony
            plansza[x][y] = 0;
            zat = 2;
        }
        else {
            for (int i = 1; i < statki[2].size(); i++)
                if ((statki[0][i] == x) && (statki[1][i] == y)) {
                    id = statki[2][i];
                    statki[0][i] = 0;
                    statki[1][i] = 0;
                    statki[2][i] = 0;
                    plansza[x][y] = 0;
                }
            for (int i = 1; i < statki[2].size(); i++)
                if (statki[2][i] == id)
                    plansza[statki[0][i]][statki[1][i]]--;
            zat = 1;
        }
    }
    return zat;
}

void sortowanie_przez_wstawianie(int tab[][2], int n) {
    int j = 1, k;
    while (j <= n) {
        for (k = j; k > 0; k--)
            if (tab[k][0] > tab[k - 1][0]) {
                swap(tab[k][0], tab[k - 1][0]);
                swap(tab[k][1], tab[k - 1][1]);
            }
            else break;
        j++;
    }
}

void tablica_traf(int a, int b, int komp[25][2], int tr[4][2],int ii, int m)
{
    if ((komp[m][0] == a) && (komp[m][1] == b)) {
        tr[ii][0] = a;
        tr[ii++][1] = b;
    }
}

int main()
{
    srand(time(NULL));
    const int n = 7;
    int komputer[25][2];
    string plansza11[n][n];
    vector <int> statki1[3], statki2[3];
    int zatopiony = 0, zatopionyk = 0, licznik = 0;

    //zerowania tablic
    for (int i = 0; i < 3; i++) {
        statki1[i].push_back(0);
        statki2[i].push_back(0);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            plansza11[i][j] = '*'; //Y X

        }
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++) {
            komputer[licznik][0] = i;
            komputer[licznik][1] = j;
            licznik++;
        }

    int plansza1[n][n] = { 0 }, plansza2[n][n] = { 0 };

    umiesc_statek(3, plansza1, statki1);
    umiesc_statek(2, plansza1, statki1);
    umiesc_statek(1, plansza1, statki1);
    umiesc_statek(1, plansza1, statki1);
    umiesc_statek_k(3, plansza2, statki2);
    umiesc_statek_k(2, plansza2, statki2);
    umiesc_statek_k(1, plansza2, statki2);
    umiesc_statek_k(1, plansza2, statki2);

    bool a = true;
    int temp[3][2] = { 0 };
    int traf[4][2] = { 0 };
    while ((zatopiony < 4) && (zatopionyk < 4)) {
        int x, y, z, los, t, licz = 0;

        if (a) {
            cout << "u: ";
            cin >> x >> y;
            z = strzal(x, y, plansza2, statki2);
            if (z == 2) {
                cout << "zatopiony" << endl;
                plansza11[x][y] = 'X';
                zatopiony++;
                a = true;
            }
            else if (z == 1) {
                cout << "trafiony" << endl;
                plansza11[x][y] = 'X';
                a = true;
            }
            else {
                plansza11[x][y] = 'O';
                a = false;
            }

            for (int i = 1; i <= 5; i++) {
                for (int j = 1; j <= 5; j++)
                    cout << plansza11[j][i] << " ";
                cout << endl;
            }
        }
        else {
            sortowanie_przez_wstawianie(traf, 4);
            if (traf[0][0] == 0) {
                los = rand() % licznik;
                x = komputer[los][0];
                y = komputer[los][1];
                komputer[los][0] = 0;
                komputer[los][1] = 0;
            }
            else {
                for (int i = 0; i < 4; i++)
                    cout << traf[i][0] << " " << traf[i][1] << endl;
                x = traf[0][0];
                y = traf[0][1];
                traf[0][0] = 0;
                traf[0][1] = 0;
                for (int m = 0; m < licznik; m++)
                    if ((komputer[m][0] == x) && (komputer[m][1] == y)) {
                        komputer[m][0] = 0;
                        komputer[m][1] = 0;
                    }
            }
            cout << endl << "K: " << x << " " << y;
            z = strzal(x, y, plansza1, statki1);
            if (z == 2) {
                cout << " zatopiony" << endl;
                zatopionyk++;
                a = false;
                for (int i = 0; i < 3; i++)
                    if (temp[i][0] == 0) {
                        t = i;
                        temp[i][0] = x;
                        temp[i][1] = y;
                        break;
                    }
                for (int i = 0; i <= t; i++)
                    for (int j = temp[i][0] - 1; j <= temp[i][0] + 1; j++)
                        for (int k = temp[i][1] - 1; k <= temp[i][1] + 1; k++)
                            for (int m = 0; m < licznik; m++)
                                if ((komputer[m][0] == j) && (komputer[m][1] == k)) {
                                    komputer[m][0] = 0;
                                    komputer[m][1] = 0;
                                    licz++;
                                    break;
                                }
                for (int i = 0; i < 3; i++) {
                    temp[i][0] = 0;
                    temp[i][1] = 0;
                }
                for (int m = 0; m < 25; m++) cout << komputer[m][0] << " " << komputer[m][1] << endl;
            }
            else if (z == 1) {
                cout << " trafiony" << endl;
                a = false;
                for (int i = 0; i < 3; i++)
                    if (temp[i][0] == 0) {
                        t = i;
                        temp[i][0] = x;
                        temp[i][1] = y;
                        break;
                    }
                if (t == 0) {
                    int ii = 0;
                    for (int m = 0; m < licznik; m++) {
                        tablica_traf(x - 1, y, komputer, traf, ii, m);
                        tablica_traf(x, y - 1, komputer, traf, ii, m);
                        tablica_traf(x + 1, y, komputer, traf, ii, m);
                        tablica_traf(x, y + 1, komputer, traf, ii, m);                    
                    }
                }
                else {
                    cout << "-------------------------------";
                    for (int i = 0; i < 4; i++) {
                        traf[i][0] = 0;
                        traf[i][1] = 0;
                    }
                    int ii = 0;
                    if (temp[0][0] != temp[1][0])
                        if (temp[0][0] > temp[1][0])
                            for (int m = 0; m < licznik; m++) {
                                tablica_traf(temp[0][0] - 1, temp[0][1], komputer, traf, ii, m);
                                tablica_traf(temp[1][0] + 1, temp[1][1], komputer, traf, ii, m);
                            }
                        else
                            for (int m = 0; m < licznik; m++) {
                                tablica_traf(temp[0][0] - 1, temp[0][1], komputer, traf, ii, m);
                                tablica_traf(temp[1][0] + 1, temp[1][1], komputer, traf, ii, m);
                            }

                    else
                        if (temp[0][1] > temp[1][1])
                            for (int m = 0; m < licznik; m++) {
                                tablica_traf(temp[0][0], temp[0][1] - 1, komputer, traf, ii, m);
                                tablica_traf(temp[1][0], temp[1][1] + 1, komputer, traf, ii, m);                              
                            }
                        else
                            for (int m = 0; m < licznik; m++) {
                                if ((komputer[m][0] == temp[0][0]) && (komputer[m][1] == temp[0][1] - 1)) {
                                    traf[ii][0] = temp[0][0];
                                    traf[ii++][1] = temp[0][1] - 1;
                                }
                                if ((komputer[m][0] == temp[1][0]) && (komputer[m][1] == temp[1][1] + 1)) {
                                    traf[ii][0] = temp[1][0];
                                    traf[ii++][1] = temp[1][1] + 1;
                                }
                            }

                }
            }
            else {
                cout << " pudlo" << endl;
                a = true;
            }
            sortowanie_przez_wstawianie(komputer, 25);
            if (licz != 0) licznik -= licz;
            else licznik--;
            cout << "--licznik: " << licznik << endl;
        }
    }
    if (zatopiony == 4) cout << "wygral gracz";
    else cout << "wygral komputer";
}

