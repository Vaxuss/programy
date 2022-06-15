#include <iostream>
#include <string>
#include <vector>

using namespace std;

//struct Data {
//	int dd, mm, rr;
//};
//
//class Uczen {
//private:
//	string Imie, nazwisko, klasa;
//	Data data_urodzenia;
//public:
//	Uczen();
//	Uczen(string, string, string, Data);
//	void wyswietlDane();
//	Uczen& PobierzDane(Uczen& u) {
//		cin >> u.Imie;
//		cin >> u.nazwisko;
//		cin >> u.klasa;
//		cin >> u.data_urodzenia.dd;
//		cin >> u.data_urodzenia.mm;
//		cin >> u.data_urodzenia.rr;
//		return u;
//	}	
//};
//
//Uczen::Uczen()
//{
//}
//
//Uczen::Uczen(string pImie, string pNazwisko, string pKlasa, Data pData_ur)
//{
//	Imie = pImie;
//	nazwisko = pNazwisko;
//	klasa = pKlasa;
//	data_urodzenia = pData_ur;
//
//}
//
//void Uczen::wyswietlDane()
//{
//	cout << Imie << " " << nazwisko << " " << klasa << " " << data_urodzenia.dd << "." << data_urodzenia.mm << "." << data_urodzenia.rr;
//}
//
//
//int main(){
//	string imie, naz, kl;
//	int dd, mm, rr;
//	cout << "Podaj imie, nazwisko i klase: ";
//	cin >> imie >> naz >> kl;
//	cout << endl << "Podaj date urodzenia: ";
//	cin >> dd >> mm >> rr;
//
//	Uczen u(imie, naz, kl, { dd, mm, rr });
//
//	/*Uczen u;
//	u.PobierzDane(u);*/
//
//	u.wyswietlDane();
//
//}
//

// -----------------------------------------


class Prostokat {
public:
    Prostokat();
    Prostokat(double, double);
    void wyswietlBoki();
    void setBok(double, double);
    double getBok1();
    double getBok2();
    void pobierzBoki(double&, double&);
private:
    double bok1{ 0 };
    double bok2{ 0 };
};

Prostokat::Prostokat() {

}

Prostokat::Prostokat(double pBok1, double pBok2) {
    bok1 = pBok1;
    bok2 = pBok2;
}

void Prostokat::wyswietlBoki()
{
    cout << bok1 << " " << bok2 << endl;
}

void Prostokat::setBok(double pBok1, double pBok2)
{
    bok1 = pBok1;
    bok2 = pBok2;
}

double Prostokat::getBok1()
{
    return bok1;
}

double Prostokat::getBok2()
{
    return bok2;
}

void Prostokat::pobierzBoki(double& pBok1, double& pBok2)
{
    pBok1 = bok1;
    pBok2 = bok2;
}

void wyswietlBoki(double b1, double b2) {
    cout << b1 << " " << b2 << endl;
}

int main()
{
    int b1, b2;
    cin >> b1;
    cout << endl;
    cin >> b2;
    cout << endl;
    double dlugosc, szerokosc;
    
    Prostokat p1(b1, b2);
    p1.wyswietlBoki();

    dlugosc = p1.getBok1();
    szerokosc = p1.getBok2();

    dlugosc += 5;
    szerokosc += 7;

    cout << endl;

    p1.setBok(dlugosc, szerokosc);
    p1.wyswietlBoki();
    
    p1.pobierzBoki(dlugosc, szerokosc);

    cout << endl;

    wyswietlBoki(dlugosc, szerokosc);

    cout << endl;

    p1.wyswietlBoki();
}


