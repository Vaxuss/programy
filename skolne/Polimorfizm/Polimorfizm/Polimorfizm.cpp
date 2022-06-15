#include <iostream>

using namespace std;

//class Pracownik {
//public:
//	string imie, nazwisko;
//	virtual void zwrocDane() {
//	};
//};
//
//class Lekarz : public Pracownik {
//public:
//	string specjalizacja;
//	void zwrocDane() override;
//};
//
//class Ordynador : public Lekarz {
//public:
//	string oddzial;
//	void zwrocDane();
//};
//
//void Lekarz::zwrocDane()
//{
//	cout << "Lekarz: " << imie << " " << nazwisko << " " << specjalizacja << endl;
//}
//
//void Ordynador::zwrocDane()
//{
//	cout << "Ordynador: " << imie << " " << nazwisko << " " << specjalizacja << " " << oddzial << endl;
//}
//
//int main() {
//	//zad 3
//	Lekarz l;
//	l.imie = "A";
//	l.nazwisko = "B";
//	l.specjalizacja = "Kardiolog";
//	l.zwrocDane();
//
//	Ordynador o;
//	o.imie = "A";
//	o.nazwisko = "B";
//	o.specjalizacja = "Kardiolog";
//	o.oddzial = "Dzieciecy";
//	o.zwrocDane();
//
//	//zad 4
//	Pracownik p1;
//	Pracownik* wp;
//	wp = &p1;
//	wp->imie = "Jan";
//	wp->nazwisko = "Kowal";
//	wp->zwrocDane();
//
//
//}

class Pracownik {
public:
    string imie, nazwisko;
    virtual void zwrocDane();
};

class Nauczyciel : public Pracownik {
public:
    string przedmiot;
    void zwrocDane() override;
};

class Wychowawca : public Nauczyciel {
public:
    string klasa;
    void zwrocDane();
};

int main()//nie da sie wywoływać od tyłu
{
    Pracownik* w_p;
    Pracownik p1;
    w_p = &p1;
    w_p->imie = "Jan";
    w_p->nazwisko = "Kowal";
    w_p->zwrocDane();

    Nauczyciel p2;
    w_p = &p2;
    w_p->imie = "Adam";
    w_p->nazwisko = "Nowak";
    p2.przedmiot = "Biologia";
    w_p->zwrocDane();

    Wychowawca p3;
    w_p = &p3;
    w_p->imie = "Dawid";
    w_p->nazwisko = "Malinowski";
    p3.przedmiot = "Geo";
    p3.klasa = "3B";
    w_p->zwrocDane();

}

void Pracownik::zwrocDane()
{
    cout << "PRACWONIK: " << imie << " " << nazwisko << endl;
}

void Nauczyciel::zwrocDane()
{
    cout << "NAUCZYCIEL: " << imie << " " << nazwisko << " " << przedmiot << endl;
}

void Wychowawca::zwrocDane()
{
    cout << "WYCHOWAWCA: " << imie << " " << nazwisko << " " << przedmiot << " " << klasa << endl;
}
