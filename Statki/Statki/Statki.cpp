#include <iostream>
#include <vector>
#include <string>
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

    if (ok == true) {
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
}
int main()
{
    const int n = 7;
    int plansza1[n][n], zatopione = 0;
    vector <int> statki1[3];
    string plansza2[n][n];
    //zerowania tablic
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            plansza1[i][j] = 0; //Y X
            plansza2[i][j] = "*";
        }           
    for (int i = 0; i < 3; i++) statki1[i].push_back(0);

    umiesc_statek(3, plansza1, statki1);
    umiesc_statek(2, plansza1, statki1);
    umiesc_statek(1, plansza1, statki1);
    umiesc_statek(1, plansza1, statki1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << plansza2[j][i] << " ";
        cout << endl;
    }

    while (zatopione < 4)
    {
        int x, y, id;
        cin >> x >> y;
        if ((plansza1[x][y] <= 3) && (plansza1[x][y]) > 0)
        {
            if (plansza1[x][y] == 1) // zatopiony
            {
                plansza1[x][y] = 0;
                zatopione++;
                cout << "\n" << "Zatopiony" << endl;
            }
            else
            {
                for (int i = 1; i < statki1[2].size(); i++)
                {
                    if ((statki1[0][i] == x) && (statki1[1][i] == y))
                    {
                        id = statki1[2][i];
                        statki1[0][i] = 0;
                        statki1[1][i] = 0;
                        statki1[2][i] = 0;
                        plansza1[x][y] = 0;
                    }
                }
                for (int i = 1; i < statki1[2].size(); i++)
                {
                    if (statki1[2][i] == id)
                        plansza1[statki1[0][i]][statki1[1][i]]--;
                }
                cout << "\n" << "Trafiony" << endl;
            }
            plansza2[x][y] = "X";
        }
        else plansza2[x][y] = "O";

        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++)
            {
                cout << plansza2[j][i] << " ";
            }
            cout << endl;
        }
    }
}

