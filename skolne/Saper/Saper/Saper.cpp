#include <iostream>
#include <ctime>

using namespace std;

class Pole {
public:
    int wartosc;
    bool klik;
    bool flaga;

    Pole() {
        wartosc = 0;
        klik = false;
        flaga = false;
    }
    bool wpiszBombe();
    void dodaj();
};

class Metody : public Pole {
public:
    bool czyTrafilBombe(int);
    void wyswietlBomby();
    void wyswietl();

};

Metody tab[7][7];

bool calaPlansza() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (tab[i][j].klik == false) return true;
        }
    }
    return false;
}

int main()
{
    srand(time(NULL));

    int x, y, z, licznik = 0;
    bool bomba;

    while (licznik < 5) {
        x = rand() % 5 + 1;
        y = rand() % 5 + 1;
        bomba = tab[x][y].wpiszBombe();
        if (bomba) {
            licznik++;
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    tab[i][j].dodaj();
                }
            }
        }
    }
    bomba = false;
    while (calaPlansza() && (!bomba)) {
        cin >> y >> x >> z;
        bomba = tab[x][y].czyTrafilBombe(z);
        if (bomba) {
            for (int i = 1; i <= 5; i++, cout << endl) {
                for (int j = 1; j <= 5; j++) {
                    tab[i][j].wyswietlBomby();
                }
            }
        }
        else {
            for (int i = 1; i <= 5; i++, cout << endl) {
                for (int j = 1; j <= 5; j++) {
                    tab[i][j].wyswietl();
                }
            }
        }
    }
}

bool Pole::wpiszBombe()
{
    if (wartosc == 9) return false;
    else {
        wartosc = 9;
        return true;
    }
}

void Pole::dodaj()
{
    if (wartosc != 9) wartosc++;
}

bool Metody::czyTrafilBombe(int z)
{
    if (z == 0) {
        if (wartosc == 9) return true;
        else {
            klik = true;
            return false;
        }
    }
    else {
        if (flaga) {
            flaga = false;
            klik = false;    
        }
        else {
            klik = true;
            flaga = true;
        }
        return false;
    }
    
}

void Metody::wyswietlBomby()
{
    if (wartosc == 9) {
        if (flaga) cout << "!";
        else cout << "X";
    }
    else {
        if (flaga)cout << "P";
        else cout << wartosc;
    }
}

void Metody::wyswietl()
{
    if (klik) {
        if (flaga) cout << "P";
        else cout << wartosc;
    }
    else
        cout << "_";
}
