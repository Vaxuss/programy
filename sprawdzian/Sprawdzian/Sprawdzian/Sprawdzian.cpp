#include <iostream>

using namespace std;

bool wejscieFormat(string sDana) {
    if (sDana == "kwadrat" || sDana == "prostokat" || sDana == "romb") {
        return true;
    }
    else return false;
}

bool wejscieZakres(int iDana) {
    if ((iDana >= 1) && (iDana <= 100)) return true;
    else return false;
}

class Kwadrat {
public:
    int a, h, pole, suma_pol;

    Kwadrat() {};
    Kwadrat(int _a, int _h) {
        a = _a;
        h = _h;
    }

    void oblicz_kwadrat() {
        pole = a * a;
        //suma_pol += pole;
    }

    virtual void zwrocDane();
};

class Prostokat : Kwadrat {
public:
    int a, h, grubosc_lini, pole = 0, suma_pol = 0;

    Prostokat() {};
    Prostokat(int _a, int _h, int _grubosc_lini) : Kwadrat(a,h) {
        grubosc_lini = _grubosc_lini;
    }

    void oblicz_prostokat() {
        pole = a * h;
        //suma_pol += pole;
    }

    void zwrocDane() override;
};

class Romb : Prostokat{
public:
    int a, h, kat_ostry;

    Romb() {};
    Romb(int _a, int _h, int _kat_ostry) : Prostokat(a, h, grubosc_lini) {
        kat_ostry = _kat_ostry;
    }

    Romb(const Romb&);

    void oblicz_romb() {
        pole = a * h;
        //suma_pol += pole;
    }

    void zwrocDane() override;
};

template <typename T>
T sumaPol(T suma_pol){
}

int main()
{
    srand(time(NULL));
    int ilosc, a, h, grubosc_lini, kat_ostry;
    string figura;

    cout << "Prosze wpisac liczbe od 1 do 100" << endl;
    cin >> ilosc;
    cout << endl << "Prosze wpisac 'kwadrat', lub, 'prostokat', lub, 'romb'" << endl;
    cin >> figura;

    a = rand() % 9 + 1;
    h = rand() % 9 + 1;

    try {    
        if (wejscieZakres(ilosc) == false)
            throw ilosc;
        if (wejscieFormat(figura) == false)
            throw figura;

        if (figura == "kwadrat") {
            for (int i = 0; i < ilosc; i++) {
                Kwadrat k1(a, h);
                k1.oblicz_kwadrat();
                k1.zwrocDane();
            }
        }
        else if (figura == "prostokat") {
            grubosc_lini = rand() % 5 + 1;
            for (int i = 0; i < ilosc; i++) {
                Prostokat p1(a, h, grubosc_lini);
                p1.oblicz_prostokat();
                p1.zwrocDane();
            }
        }
        else if (figura == "romb") {
            kat_ostry = rand() % 88 + 1;
            for (int i = 0; i < ilosc; i++) {
                Romb r1(a, h, kat_ostry);
                r1.oblicz_romb();
                r1.zwrocDane();
            }
        }
    }

    

    catch (string figura) {
        cout << endl << "Format wejsciowy: '" << figura << "' nie jest jedna z obslugiwanych figur";
    }
    catch (int a) {
        cout << endl << "Wartosc liczby wejsciowej: '" << a << "' nie miesci sie w zakresie";
    }
}

void Kwadrat::zwrocDane()
{
    cout << a << "," << pole;
}

void Prostokat::zwrocDane()
{
    cout << a << "," << h << "," << grubosc_lini << "," << pole;
}

Romb::Romb(const Romb& wzor) {
    kat_ostry = wzor.kat_ostry;
}

void Romb::zwrocDane()
{
    cout << a << "," << h << "," << kat_ostry << "," << pole;
}

