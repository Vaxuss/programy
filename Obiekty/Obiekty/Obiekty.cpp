#include <iostream>
#include <string>
#include <vector>

using namespace std;

//union Oceny {
//	short ocena_c;
//	float ocena_r;
//};
//
//struct Statki {
//	int maszty;
//	int x;
//	int y;
//	int z;
//};


//struct Pracownik {
//	string imie;
//	string nazwisko;
//	int nr_ewid;
//};

class Prostokont {
public:
	int bok1;
	int bok2;

	void ustawBok1(int);
	void ustawBok2(int);

	int pole(){
		int pole = bok1 * bok2;
		cout << "Pole to: " << pole << endl;
		return pole;
	}

	int obwod() {
		int obwod = (bok1 * 2) + (bok2 * 2);
		cout << "Obowod to: " << obwod << endl;
		return obwod;
	}
};
void Prostokont::ustawBok1(int bok1) {
	this->bok1 = bok1;
}

void Prostokont::ustawBok2(int bok2) {
	this->bok2 = bok2;
}

class Pracownik {
	public:
		string imie;
		string nazwisko;

		void wyswietlDane() {
			cout << imie << " " << nazwisko << endl;
		}
};

Pracownik& pobierzDane(Pracownik&);
void wyswietlDane(const Pracownik&);

int main()
{
	/*Prostokont prostokont;
	cin >> prostokont.bok1;
	cin >> prostokont.bok2;

	prostokont.pole();
	cout << endl;
	prostokont.obwod();*/

	Pracownik pracownik;
	pracownik = pobierzDane(pracownik);
	wyswietlDane(pracownik);


	/*Pracownik *w_pracownik = &pracownik;
	
	w_pracownik->imie = "Jan";
	w_pracownik->nazwisko = "Kowalski";
	w_pracownik->wyswietlDane();

	delete w_pracownik;*/


	/*Statki trzy_maszt{ 3, 3, 3, 0 };
	Statki dwu_maszt{ 2, 1, 1, 1 };
	Statki jedno_maszt1{ 1, 5, 1, 1 };
	Statki jedno_maszt2{ 5, 1, 1, 0 };

	cout << trzy_maszt.maszty << "-masztowiec" << endl;
	cout << "X: " << trzy_maszt.x << endl;
	cout << "y: " << trzy_maszt.y << endl;
	if (trzy_maszt.z == 0) {
		cout << "Pion: " << trzy_maszt.z << endl;
	}
	else {
		cout << "Poziom: " << trzy_maszt.z << endl;
	}*/

	/*Oceny oceny1 = { oceny1.ocena_c = 4 };
	cout << sizeof(oceny1) << endl;
	cout << sizeof(oceny1.ocena_c) << endl;

	cout << oceny1.ocena_c << endl;
	oceny1.ocena_r = 3.5;

	cout << oceny1.ocena_r << endl;
	
	oceny1.ocena_c = 5;*/

	/*Pracownik* wsk = new Pracownik;
	cin >> wsk->imie;
	cout << endl;
	cin >> wsk->nazwisko;

	cout << wsk->imie << " " << wsk->nazwisko;

	delete wsk;*/

	/*Pracownik prac1 = { "Jan", "Kowalski", 1234 };

	Pracownik* wsk = &prac1;

	cout << wsk->nazwisko;*/


	/*cout << prac1.imie << endl;
	cout << prac1.nazwisko << endl;
	cout << prac1.nr_ewid << endl;



	Pracownik prac2 {};
	
	prac2.imie = "Adam";

	cout << prac2.imie << endl;
	cout << prac2.nazwisko << endl;
	cout << prac2.nr_ewid << endl;*/
}
Pracownik& pobierzDane(Pracownik& p) {
	cin >> p.imie;
	cin >> p.nazwisko;
	return p;
}

void wyswietlDane(const Pracownik& p) {
	cout << p.imie << " " << p.nazwisko;
}