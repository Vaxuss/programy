#include <iostream>
#include <cmath>

using namespace std;

class Pracownik;
class Uczen;

class Osoba {
	string imie, nazwisko;
public:
	void setDane(string qImie, string qNazwisko) {
		imie = qImie;
		nazwisko = qNazwisko;
	}
	string getImie() {
		return imie;
	}
	string getNazwisko() {
		return nazwisko;
	}
	
};

class Pracownik : private Osoba{
	string stanowisko;
public:

	void setStanowisko(string qStanowisko) {
		stanowisko = qStanowisko;
	}
	void zwrocDanePracownik(Osoba qO) {
		cout << qO.getImie() << " " << qO.getNazwisko() << " " << stanowisko;
	}

	friend class Uczen;
};

class Uczen : private Osoba {
	string klasa;
public:
	void setKlasa(string qKlasa) {
		klasa = qKlasa;
	}
	void zwrocDaneUczen(Osoba& qO) {
		cout << qO.getImie() << " " << qO.getNazwisko() << " " << klasa;
	}
	friend class Pracownik;
};



int main()
{
	Osoba p;
	p.setDane("Adam", "Nowak");
	Pracownik pracownik;
	pracownik.setStanowisko("Nauczyciel");
	pracownik.zwrocDanePracownik(p);
	cout << endl;
	Osoba u;
	u.setDane("Janek", "Nowak");
	Uczen uczen;
	uczen.setKlasa("3B");
	uczen.zwrocDaneUczen(u);
}
















//class Promien {
//    double _r;
//public:
//    void setPromien(double r) {
//        _r = r;
//    }
//    double getPromien() {
//        return _r;
//    }
//
//    friend class Kolo;
//    friend class Kula;
//};
//
//class Kolo {
//public:
//    double pole(Promien promien) {
//        return 3.14 * promien._r * promien._r;
//    }
//    double obwod(Promien promien) {
//        2 * 3.14 * promien._r;
//    }
//
//};
//
//class Kula {
//public:
//    double objetosc(Promien promien) {
//        return 4.0/3.0 * 3.14 * pow(promien._r, 3);//return double(4) / double(3) * 3.14 * pow(promien._r, 3)
//    }
//    double pole(Promien promien) {
//        return 4 * 3.14 * pow(promien._r, 2);
//    }
//};
//
//int main()
//{
//    Promien promien;
//    Kolo kolo;
//    promien.setPromien(5);
//    cout << kolo.pole(promien) << endl;
//    cout << kolo.obwod(promien) << endl;
//
//    Kula kula;
//    promien.setPromien(2);
//    cout << kula.objetosc(promien) << endl;
//    cout << kula.pole(promien) << endl;
//}

