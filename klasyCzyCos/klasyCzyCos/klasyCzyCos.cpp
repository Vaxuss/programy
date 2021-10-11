#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Prostokat {
private:
	double bok1;
	double bok2;

public:
	Prostokat(double, double);
	Prostokat(const Prostokat&);//konstruktor kopiujący;

	void pobierzBoki(double&, double&);
	void ustawBoki(double, double);
	double pole();
	double obwod();
};

Prostokat::Prostokat(double pBok1, double pBok2) {
	bok1 = pBok1;
	bok2 = pBok2;
}

Prostokat::Prostokat(const Prostokat& wzorzec) {
	bok1 = wzorzec.bok1;
	bok2 = wzorzec.bok2;
}

void Prostokat::pobierzBoki(double& pBok1, double& pBok2) {
	pBok1 = bok1;
	pBok2 = bok2;
}

void Prostokat::ustawBoki(double pBok1, double pBok2) {
	bok1 = pBok1;
	bok2 = pBok2;
}

double Prostokat::pole() {
	return bok1 * bok2;
}

double Prostokat::obwod() {
	return 2 * bok1 + 2 * bok2;
}

Prostokat kopiujProstokat(Prostokat prostokat) {
	return prostokat;
}

int main()
{
	double b1, b2;

	Prostokat p1(1, 2);
	p1.pobierzBoki(b1, b2);
	cout << b1 << " " << b2 << endl;

	Prostokat p2 = p1;
	p2.pobierzBoki(b1, b2);
	cout << b1 << " " << b2 << endl;

	//kopiowanie na bazie wzorca
	Prostokat p3(p1);
	p3.pobierzBoki(b1, b2);
	cout << b1 << " " << b2 << endl;
}

//struct Data {
//	int dd, mm, rr;
//};
//
//class Pracownik {
//public:
//	int id;
//	string imie, nazwisko;
//	Data data_urodzenia;
//	//prototyp
//	Pracownik();
//	Pracownik(int, string, string);
//	Pracownik(int, string, string, Data);
//	
//	void wyswietlDane() {
//		cout << id << ": " << imie << " " << nazwisko << endl
//			<< data_urodzenia.dd << "."
//			<< data_urodzenia.mm << "."
//			<< data_urodzenia.rr<<endl;
//	}
//};
//
//Pracownik::Pracownik() {
//	id = -1;
//	imie = "AAAAAA";
//	nazwisko = "AAA";
//	data_urodzenia = { 1 , 1, 1900 };
//}
//
//Pracownik::Pracownik(int pId, string pImie, string pNazwisko) {
//	id = pId;
//	imie = pImie;
//	nazwisko = pNazwisko;
//}
//
////konstruktor poza klasą;
//Pracownik::Pracownik(int pId, string pImie, string pNazwisko, Data pDaraUrodzenia) {
//	id = pId;
//	imie = pImie;
//	nazwisko = pNazwisko;
//	data_urodzenia = pDaraUrodzenia;
//}
//
//int main() {
//	Pracownik pracownik1;
//	pracownik1.wyswietlDane();
//
//	Pracownik pracownik2;
//	pracownik2 = { 1, "Jan", "Kowalski" };
//	pracownik2.wyswietlDane();
//	
//	Pracownik pracownik3(10, "adam", "Nowak", {10,10,2000});
//	pracownik3.wyswietlDane();
//}

//------------------------------------------------------------------------------------------

//struct Data {
//	int dd, mm, rr;
//};
//
//class Pracownik {
//public:
//	int id;
//	string imie, nazwisko;
//	Data data_urodzenia;
//	//def. konstruktora domyślnego
//	Pracownik() {
//		id = -1;
//		imie = "Domyslne imie", nazwisko = "Domyslne nazwisko";
//		data_urodzenia = { 31, 12, 1899 };
//	}
//};
//
//int main() {
//	Pracownik pracownik1;
//	cout << pracownik1.imie << " " << pracownik1.nazwisko << endl
//		<< pracownik1.data_urodzenia.dd << "."
//		<< pracownik1.data_urodzenia.mm << "."
//		<< pracownik1.data_urodzenia.rr;
//}

//------------------------------------------------------------------------------------------

//class Pracownik {
//static string s_szkola;
//public:
//
//    string imie, nazwisko;
//    static string s_zwrocSzkola();
//    static void s_ustawSzkola(string pSzkola) {
//        s_szkola = pSzkola;
//    }
//
//    void wyswietlDane() {
//        cout << "Dane pracownika: " << imie << " " << nazwisko << " " << s_szkola << " " << endl;
//    }
//
//};
//
//string Pracownik::s_szkola = "TKKOM";
//string Pracownik::s_zwrocSzkola() {
//    return s_szkola;
//}
//
//int main()
//{
//    Pracownik pracownik1;
//    pracownik1.imie = "Ala";
//    pracownik1.nazwisko = "Nowak";
//    pracownik1.wyswietlDane();
//    
//    Pracownik pracownik2;
//    pracownik2.imie = "Adam";
//    pracownik2.nazwisko = "Kowalski";
//    Pracownik::s_ustawSzkola("Technikum");
//    pracownik2.wyswietlDane();
//}

//--------------------------------------------------------------------------------------------

//class Pracownik {
//public:
//
//    string imie, nazwisko;
//    static string s_szkola, s_stanowisko;
//    
//    void ustawImie(string);
//    void ustawNazwisko(string);
//    void wyswietlDane();
//
//};
//
//string Pracownik::s_szkola = "TKKOM";
//string Pracownik::s_stanowisko = "Nauczyciel";
//
//void Pracownik::ustawImie(string pImie) {
//    imie = pImie;
//}
//
//void Pracownik::ustawNazwisko(string pNazwisko) {
//    nazwisko = pNazwisko;
//}
//
//void Pracownik::wyswietlDane() {
//    cout << "Dane pracownika: " << imie << " " << nazwisko << " " << s_szkola << " " << s_stanowisko << endl;
//}
//
//int main()
//{
//    Pracownik pracownik1;
//    pracownik1.ustawImie("Ala");
//    pracownik1.ustawNazwisko("Nowak");
//    pracownik1.wyswietlDane();
//    Pracownik pracownik2;
//    pracownik2.ustawImie("Ala");
//    pracownik2.ustawNazwisko("Nowak");
//    pracownik2.wyswietlDane();
//
//    Pracownik::s_stanowisko = "Portier";
//
//    Pracownik pracownik3;
//    pracownik3.ustawImie("Adam");
//    pracownik3.ustawNazwisko("Kowalski");
//    pracownik3.wyswietlDane();
//}


