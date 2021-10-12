#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Prostokat {
public:
    int bok1, bok2;

    Prostokat() {
    }
    Prostokat(int, int);
    void oblicz();
    void pobierzBoki(double&, double&);
};

Prostokat::Prostokat(int pBok1, int pBok2) {
    bok1 = pBok1;
    bok2 = pBok2;
}

void Prostokat::oblicz() {
    int pole = bok1 * bok2;
    cout << "Pole to: " << pole << endl;
}

Prostokat& podajBoki(Prostokat& u) {
    cin >> u.bok1;
    cin >> u.bok2;
    return u;
}

Prostokat kopiujProstokat(Prostokat prostokat) {
    return prostokat;
}

void Prostokat::pobierzBoki(double& pBok1, double& pBok2) {
    pBok1 = bok1;
    pBok2 = bok2;
}

//Prostokat::Prostokat(const Prostokat& wzorzec) {
//    bok1 = wzorzec.bok1;
//    bok2 = wzorzec.bok2;
//}


class Prostopadloscian {
public:
    double krawedz1, krawedz2, krawedz3, pole, dlugosc, obj;

    Prostopadloscian() {
        krawedz1 = 1;
        krawedz2 = 2;
        krawedz3 = 3;
        pole = 0;
        dlugosc = 0;
        obj = 0;
    }
    Prostopadloscian(double, double, double);
    void polePowierzchniBocznej();
    void objetosc();
    void wszystkieKrawedzie();
};

Prostopadloscian::Prostopadloscian(double pKrawedz1, double pKrawedz2, double pKrawedz3) {
    krawedz1 = pKrawedz1;
    krawedz2 = pKrawedz2;
    krawedz3 = pKrawedz3;
}

Prostopadloscian& pobierzKrawedzie(Prostopadloscian& u) {
    cin >> u.krawedz1;
    cin >> u.krawedz2;
    cin >> u.krawedz3;

    return u;
}

void Prostopadloscian::objetosc() {
    obj = krawedz1 * krawedz2 * krawedz3;
    cout <<"Objetosc: " << obj << endl;
}

void Prostopadloscian::polePowierzchniBocznej() {
    pole = (krawedz1 * krawedz2) * 2 + (krawedz1 * krawedz3) * 2 + (krawedz2 * krawedz3) * 2;
    cout << "Pole: " << pole << endl;
}

void Prostopadloscian::wszystkieKrawedzie() {
    dlugosc = krawedz1 * 4 + krawedz2 * 4 + krawedz3 * 4;
    cout << "Wszystkie krawedzie: " << dlugosc << endl;

}

class Uczen {
public:
    string imie, nazwisko, klasa;
    int grupa, nr;

    Uczen();
    Uczen(string, string, string, int, int);
    void wyswietlDane();
};

Uczen::Uczen() {
    imie = "Podaj Imie";
    nazwisko = "Podaj Nazwisko";
    klasa = "1A";
    grupa = 1;
    nr = 0;
}

Uczen::Uczen(string pImie, string pNazwisko, string pKlasa, int pGrupa, int pNr) {
    imie = pImie;
    nazwisko = pNazwisko;
    klasa = pKlasa;
    grupa = pGrupa;
    nr = pNr;
}

void Uczen::wyswietlDane() {
    cout << klasa << " " << nr << " " << grupa << " " << imie << " " << nazwisko << " " << endl;
}

Uczen& PobierzDane(Uczen& u) {//fancy sposób na wprowadzanie danych
    cout << "Podaj klase: ";
    cin >> u.klasa;
    cout << endl << "Podaj Nr: ";
    cin >> u.nr;
    cout << endl << "Podaj Imie: ";
    cin >> u.imie;
    cout << endl << "Podaj Nazwisko: ";
    cin >> u.nazwisko;
    cout << endl << "Podaj grupe: ";
    cin >> u.grupa;

    return u;
}

class Przelicznaie_Dlugosci {
public:
    int miara;
    
    Przelicznaie_Dlugosci();
    Przelicznaie_Dlugosci(int);
    void przelicz();
};

Przelicznaie_Dlugosci::Przelicznaie_Dlugosci(int pMiara) {
    miara = pMiara;
}
Przelicznaie_Dlugosci& PobierzMiare(Przelicznaie_Dlugosci& u) {
    cin >> u.miara;
    return u;
}
void Przelicznaie_Dlugosci::przelicz() {
    miara /= 2.54;
    cout << miara << endl;
}

int main()
{
    //cin'y też tu można dać *działa*
    cout << "Zad1" << endl;
    Uczen u1;
    u1.wyswietlDane();

    /*Uczen u2;
    PobierzDane(u2);
    u2.wyswietlDane();*/

    cout << "Zad2" << endl;

    Prostopadloscian p1;
    p1.objetosc();
    p1.polePowierzchniBocznej();
    p1.wszystkieKrawedzie();

    cout << endl;

    //Prostopadloscian p2;
    //pobierzKrawedzie(p2);
    //p2.objetosc();
    //p2.polePowierzchniBocznej();
    //p2.wszystkieKrawedzie();

    cout << "Zad4" << endl;
    
    Przelicznaie_Dlugosci dlug;
    PobierzMiare(dlug);
    dlug.przelicz();
    

}

