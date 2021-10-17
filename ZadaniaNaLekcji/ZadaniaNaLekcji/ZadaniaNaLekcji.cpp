#include <iostream>
#include <math.h>

using namespace std;

class Uczen {
public:
	string imie;
	string nazwisko;
	string klasa;
	string grupa;
	int nr;
	Uczen() {
		imie = "domyslne imie";
		nazwisko = "domyslne nazwisko";
		klasa = "domyslna klasa";
		nr = -1;
	}
	Uczen(string pImie, string pNazwisko, string pKlasa, int pNr) {
		imie = pImie;
		nazwisko = pNazwisko;
		klasa = pKlasa;
		nr = pNr;
	}
	void wyswietlDane() {
		cout << imie << " " << nazwisko << " " << klasa << " " << nr << endl;
	}
};

class Prostopadloscian {
public:
	int bok1;
	int bok2;
	int bok3;
	int p;
	int dlug;
	int v;
	Prostopadloscian() {
		bok1 = 1;
		bok2 = 2;
		bok3 = 3;
		przypisz();
	}
	int pole();
	int objetosc();
	int dlugosc();
	void wyswietlDane();
	void przypisz();
};

void Prostopadloscian::wyswietlDane() {
	cout << bok1 << " " << bok2 << " " << bok3 << " " << p << " " << dlug << " " << v << endl;
}

int Prostopadloscian::dlugosc() {
	return 4 * bok1 + 4 * bok2 + 4 * bok3;
}

int Prostopadloscian::pole() {
	return 2 * (bok1 * bok3) + 2 * (bok2 * bok3);
}

void Prostopadloscian::przypisz() {
	p = pole();
	v = objetosc();
	dlug = dlugosc();


}

int Prostopadloscian::objetosc() {
	int v;
	v = bok1 * bok2 * bok3;
	return v;
}

Prostopadloscian& pobierzDane(Prostopadloscian& u)
{
	cin >> u.bok1;
	cin >> u.bok2;
	cin >> u.bok3;
	u.przypisz();

	return u;
}

class Prostokat {
public:
	int a;
	int b;
	Prostokat() {
		a = 1;
		b = 2;

	};
	Prostokat(int a, int b) {
		this->a = a;
		this->b = b;
	}
	Prostokat(const Prostokat& p) {
		a = p.a;
		b = p.b;
	}
	void Obwod() {
		cout << "Obwod: " << 2 * a + 2 * b << endl;
	}
	void Pole() {
		cout << "Pole: " << a * b << endl;
	}
};

class Przeliczenie_Dlugosci {
public:
	int miara;
	Przeliczenie_Dlugosci() {
		miara = 0;
		cout << "Cale na cm" << endl;
	}
	Przeliczenie_Dlugosci(int miara) : Przeliczenie_Dlugosci() {
		this->miara = miara;
	}
	void Oblicz() {
		cout << miara * 2.54 << endl;
	}

};

struct Data {
	int dd;
	int mm;
	int rr;
};
class Samochod {
private:
	string marka;
	string model;
	string rejestracja;
	int rokP;
	int cena;
	Data data;

public:
	Samochod() {
		marka = "";
		model = "";
		rejestracja = "";
		cena = 0;
		rokP = 0;
		data.dd = 0;
		data.mm = 0;
		data.rr = 0;
	}
	Samochod(string marka, string model, string rejestracja, Data data, int rokP, int cena) {
		this->marka = marka;
		this->model = model;
		this->rejestracja = rejestracja;
		this->data.dd = data.dd;
		this->data.mm = data.mm;
		this->data.rr = data.rr;
		this->cena = cena;
		this->rokP = rokP;
	}
	~Samochod() {
		cout << "---DESTRUKTOR---" << endl;
	};
	void wyswietlDane() {
		cout << model << " " << marka << " " << rejestracja << " " << data.dd << " " << data.mm << " " << data.rr << " " << cena << " " << rokP << endl;
	}
};

class Odleglosc {
private:
	int x;
	int y;
	int x1;
	int y1;
	int odleglosc;
public:
	Odleglosc() {
		x = 0;
		y = 0;
		x1 = 0;
		y1 = 0;
	}
	Odleglosc(int x, int y, int x1, int y1)
	{
		this->x = x;
		this->y = y;
		this->x1 = x1;
		this->y1 = y1;
	}


	~Odleglosc() {
		cout << "DESTRUKTOR" << endl;
	}
	void oblicz() {
		odleglosc = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
	}
	void wyswietlDane()
	{
		cout << "(" << x << " , " << y << ")" << " " << "(" << x1 << " , " << y1 << ")" << "Odleglosc: " << odleglosc << endl;
	}
};

int main()
{
	string imie;
	string nazwisko;
	string klasa;
	int nr;

	cout << "Zad1" << endl;
	cout << "Podaj: Imie, Nazwisko, klase, nr w dzienniku: " << endl;
	cout << endl;

	cin >> imie >> nazwisko >> klasa >> nr;
	Uczen uczen;
	uczen.wyswietlDane();
	Uczen uczen1(imie, nazwisko, klasa, nr);
	uczen1.wyswietlDane();


	cout << "Zad2" << endl;
	cout << "Podaj boki: " << endl;
	cout << endl;

	Prostopadloscian p1;

	pobierzDane(p1);

	p1.wyswietlDane();

	Prostopadloscian p2;
	p2.wyswietlDane();

	cout << endl;
	cout << "Zad3" << endl;
	cout << endl;

	Prostokat pokoj;
	Prostokat kuchnia = pokoj;
	Prostokat salon = kuchnia;

	kuchnia.Obwod();
	kuchnia.Pole();

	Przeliczenie_Dlugosci n;

	n.Oblicz();

	Przeliczenie_Dlugosci k(70);
	k.Oblicz();

	cout << "Zad4" << endl;
	cout << "Podaj: marke, model, rejestracja, dzien, miesiac, rok, cene i rok produkcji: " << endl;
	cout << endl;

	string marka, model, rejestracja;
	int dd, mm, rr, cena, rokP;

	cin >> marka >> model >> rejestracja >> dd >> mm >> rr >> cena >> rokP;

	Samochod samochod(marka, model, rejestracja, { dd,mm,rr }, cena, rokP);


	samochod.wyswietlDane();

	cout << "Zad5" << endl;
	cout << endl;

	Odleglosc odleglosc(17, 3, 57, 5);
	odleglosc.oblicz();
	odleglosc.wyswietlDane();
}
