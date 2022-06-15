#include <iostream>

using namespace std;

class Pracownik {
public:
    string imie, nazwisko;
    virtual void zwrocDane() {
        cout << imie + " " + nazwisko;
    };
};

class Policjant : public Pracownik {
public:
    string stopien;
    void zwrocDane() override;
};

class Naczelnik : public Policjant {
public:
    string wydzial;
    void zwrocDane();
};

int main()
{
    //zad5
    Policjant p;
    p.imie = "a";
    p.nazwisko = "b";
    p.stopien = "komisarz";
    p.zwrocDane();
    
    Naczelnik n;
    n.imie = "a";
    n.nazwisko = "b";
    n.stopien = "komisarz";
    n.wydzial = "Drogowka";
    n.zwrocDane();
     
    //zad6

    Pracownik* wp;
    wp = &p;
    wp->imie = "Jan";
    wp->nazwisko = "Kowal";
    wp->zwrocDane();
}

void Policjant::zwrocDane()
{
    cout << "Policjant: " << imie << " " << nazwisko << " " << stopien << endl;
}

void Naczelnik::zwrocDane()
{
    cout << "Naczelnik: " << imie << " " << nazwisko << " " << stopien << " " << wydzial << endl;
}
