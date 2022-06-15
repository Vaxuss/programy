#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pracownik {
public:
	string imie;
	string nazwisko;

	Pracownik() {
		imie = "A";
		nazwisko = "B";
	}
	Pracownik(string pImie, string pNazwisko) {
		imie = pImie;
		nazwisko = pNazwisko;
	}
	~Pracownik() {//destruktor
		cout << "----DESTRUKTOR----" << endl;//Może być pusty to tylko dla demonstracji działania
	}

	void wyswietlDane() {
		cout << imie << " " << nazwisko << endl;
	}
};

void funkcjaPomoc() {
	Pracownik pracownik;
	pracownik.wyswietlDane();
}

int main()
{
	{//Bez klamr też działa 
		Pracownik pracownik1;
		pracownik1.wyswietlDane();
	}

	Pracownik pracownik2;
	pracownik2.wyswietlDane();

	Pracownik* w_pracownik3 = new Pracownik("Jan", "Kowalski");
	w_pracownik3->wyswietlDane();
	delete w_pracownik3;

	funkcjaPomoc();

	cout << endl;
	cout << "koniec" << endl;
}

//delegowanie konstruktorow
//class Prostokat {
//private:
//	double bok1;
//	double bok2;
//	string kolor;
//public:
//	Prostokat();
//	Prostokat(double, double);
//	void ustawKolor(string);
//	void wyswietlDane();
//};
//
//Prostokat::Prostokat() {
//	kolor = "Bialy";
//}
//
//Prostokat::Prostokat(double pBok1, double pBok2) : Prostokat::Prostokat() {// delegowanie konstruktorow
//	bok1 = pBok1;
//	bok2 = pBok2;
//}
//
//void Prostokat::ustawKolor(string pKolor) {
//	kolor = pKolor;
//}
//
//void Prostokat::wyswietlDane() {
//	cout << bok1 << " " << bok2 << " " << kolor << endl;
//}
//
//int main() 
//{
//	Prostokat p1;
//	p1.wyswietlDane();
//	cout << endl;
//
//	Prostokat p2(1,2);
//	p2.ustawKolor("Czarny");
//	p2.wyswietlDane();
//	cout << endl;
//}