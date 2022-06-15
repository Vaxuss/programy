#include <iostream>
#include <string>

using namespace std;

class Pokoj {
private:
	int a, b;
public:
	Pokoj() {

	}
	int metraz();
	Pokoj& pobierzDane(Pokoj& u) {
		cin >> u.a;
		cin >> u.b;
		return u;
	}
};

int Pokoj::metraz() {
	return a * b;
}

int main() {
	Pokoj u;
	int temp = 0;
	for (int i = 0; i < 3; i++) {
		Pokoj* pokoje = new Pokoj;
		pokoje->pobierzDane(u);
		temp += u.metraz();
		delete[] pokoje;
	}

	cout << endl << temp;

}



//----------------------------------------------------------

//struct Data {
//	int dd, mm, rr;
//};
////obliczenia w uczniu;	
//class Uczen {
//public:
//	Uczen() {
//
//	}
//	Uczen& pobierzDane(Uczen& u) {
//		int TN;
//		cout << "Czy uczeni jest po podstawowce? (1)TAK, (2)NIE ";
//		cin >> TN;
//		if (TN == 1) {
//			u.czyPodstawowka == true;
//		}
//		else {
//			u.czyPodstawowka == false;
//		}
//		u.data_przyjecia.dd = 1;
//		u.data_przyjecia.mm = 9;
//		u.data_przyjecia.rr = 2017;
//		cout << endl << "Podaj imie:";
//		cin >> u.imie;
//		cout << endl << "Podaj nazwisko:";
//		cin >> u.nazwisko;
//
//		return u;
//	}
//
//	void obliczLata(Data);
//private:
//	int pozostale_lata;
//	string imie, nazwisko;
//	Data data_przyjecia;
//	bool czyPodstawowka;
//};
//
//void Uczen::obliczLata(Data dzis) {
//	int lata = 0;
//	int temp = 0;
//
//	if (dzis.mm > 6) {
//		temp = dzis.rr - data_przyjecia.rr;
//	}
//	else temp = dzis.rr - data_przyjecia.rr - 1;
//
//	if (czyPodstawowka) lata = 5 - temp;
//	else lata = 4 - temp;
//	
//	cout << "Pozostalo mu: " << lata << " lat";
//	
//}
//
//int main() {
//	//wprowadz date;
//
//	Uczen u;
//	u.pobierzDane(u);
//
//	int d = 0, m = 0, r = 0;
//	cout << endl << "Podaj dzisiejszy dzien, miesiac i rok: ";
//	cin >> d, m, r;
//
//	cout << endl;
//
//	Data dzis;
//	dzis.dd = d;
//	dzis.mm = m;
//	dzis.rr = r;
//
//	u.obliczLata(dzis);
//	
//
//}

//----------------------------------------------------------

//class Prostokat {
//public:
//    Prostokat() {
//
//    }
//    Prostokat(int, int);
//    int getA();
//    int getB();
//    Prostokat& pobierzDane(Prostokat& u) {
//        cin >> u.a;
//        cin >> u.b;
//
//        return u;
//    }
//
//private:
//    int a, b;
//};
//
//Prostokat::Prostokat(int pA, int pB) {
//    a = pA;
//    b = pB;
//}
//
//int Prostokat::getA()
//{
//    return a;
//}
//
//int Prostokat::getB()
//{
//    return b;
//}
//
//class Prostopadloscian {
//public:
//    Prostopadloscian() {
//
//    }
//
//    void oblicz(int,int);
//private:
//    int h = 5;
//};
//
//void Prostopadloscian::oblicz(int a, int b) {
//    int obj = 0;
//    int pole = 0;
//    obj = a * b * h;
//    pole = (a * h * 2) + (a * b * 2) + (b * h * 2);
//    cout << "Pole: " << pole << " Objetosc: " << obj;
//}
//
//int main()
//{
//    Prostokat prost;
//    prost.pobierzDane(prost);
//
//    int bok1 = prost.getA();
//    int bok2 = prost.getA();
//
//    Prostopadloscian p;
//    p.oblicz(bok1, bok2);
//}

