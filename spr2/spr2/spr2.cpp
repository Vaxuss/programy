#include <iostream>
#include <ctime>

using namespace std;

class Kwadrat {
public:
    int a, h;
    Kwadrat() {
        a = 1;
        h = 1;
    }
    Kwadrat(int a, int h) {
        this->a = a;
        this->h = h;
    }

    virtual int Pole() {
        return a * h;
    }

    virtual void wypisz() {
        cout << a << " " << h << " " << Pole() << "\n";
    }
};

class Prostokat : public Kwadrat {
public:
    int grubosc_linii;


    Prostokat(int a, int h, int grubosc_linii) {
        this->a = a;
        this->h = h;
        this->grubosc_linii = grubosc_linii;
    }

    int Pole() {
        return a * h;
    }

    void wypisz() {
        cout << a << " " << h << " " << grubosc_linii << " " << Pole() << "\n";
    }
};

class Romb : public Kwadrat {
public:
    int kat_ostry;

    Romb(int a, int h, int kat_ostry) {
        this->a = a;
        this->h = h;
        this->kat_ostry = kat_ostry;
    }

    Romb(Romb& romb) {
        this->a = romb.a;
        this->h = romb.h;
    };


    int Pole() {
        return a * h;
    }

    void wypisz() {
        cout << a << " " << h << " " << kat_ostry << " " << Pole() << "\n";
    }
};


template <typename T>
T sumaWszystkich(T suma, T pole) {
    return suma + pole;
}



int main()
{
    srand(time(NULL));

    int x = 0, suma = 0;
    string rodzajString = "";
    int rodzaj = 0;

    while (x < 1 || x > 100) {
        try {
            cout << "Podaj liczbe od 1 do 100: ";
            cin >> x;
            if (x > 100 || x < 1)
                throw x;
        }
        catch (int x) {
            cout << "Liczba nie zmiescila sie w przedziale 1-100\n";
        }
    }

    while (rodzaj > 3 || rodzaj < 1) {
        try {
            cout << "Podaj rodzaj figury: kwadrat, romb lub prostokat: ";
            cin >> rodzajString;

            if (rodzajString == "kwadrat")
                rodzaj = 1;
            else if (rodzajString == "romb")
                rodzaj = 2;
            else if (rodzajString == "prostokat")
                rodzaj = 3;
            else
                throw rodzaj;
        }
        catch (int rodzaj) {
            cout << "Wpisales zla nazwe figury\n";
        }
    }


    for (int i = 0; i < x; i++)
    {
        int a = rand() % 10 + 1;
        int h = rand() % 10 + 1;
        int kat_ostry = rand() % 89 + 1;
        int grubosc_linii = rand() % 5 + 1;

        Kwadrat kw(a, h);
        Romb romb(a, h, kat_ostry);
        Prostokat pros(a, h, grubosc_linii);

        switch (rodzaj) {
        case 1:
            kw.wypisz();
            suma = sumaWszystkich<int>(suma, kw.Pole());
            break;
        case 2:
            romb.wypisz();
            suma = sumaWszystkich<int>(suma, romb.Pole());
            break;
        case 3:
            pros.wypisz();
            suma = sumaWszystkich<int>(suma, pros.Pole());
            break;
        }
    }
    cout << "\nSuma pol: " << suma;
}