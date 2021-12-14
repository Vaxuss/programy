#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

struct Wyjatek {
	virtual string komunikat() = 0;
};

bool wejscieFormat(string sDana) {
	for (int i = 0; i < sDana.length(); i++)
		if (isdigit(sDana[i]) == false)
			return false;
	return true;
}

bool wejscieZakres(int iDana) {
	if ((iDana >= 1) && (iDana <= 6)) return true;
	else return false;
}

class Foramt : public Wyjatek {
	string sOcena;
public:
	Foramt(string sOcena) : sOcena(sOcena) {};// przypisanie wartosci do sOcena;
	string komunikat() {
		stringstream sTemp;
		sTemp << "Format dane wejsciowej " << sOcena << " nie odpowiada liczbie calkowitej" << endl;
		return sTemp.str();
	}
};

class Zakres : public Wyjatek {
	int ocena;
public:
	Zakres(int ocena) : ocena(ocena) {};
	string  komunikat() {
		stringstream sTemp;
		sTemp << "Wartosc danej wejsciowej " << ocena << " nie miesci sie w zakresie  1 do 6" << endl;
		return sTemp.str();
	}
};

int main()
{
	string sOcena;
	cin >> sOcena;
	try {
		if (wejscieFormat(sOcena) == false)
			throw Foramt(sOcena);
		int ocena = stoi(sOcena);
		if (wejscieZakres(ocena) == false)
			throw Zakres(ocena);
		switch (ocena) {
		case 1:
			cout << "Uczen nie zdaje";
			break;
		case 6:
			cout << "Uczen zdaje";
			break;
		default:
			cout << "Ocena normalna";
			break;
		}
	}
	catch (Wyjatek& wyjatek) {
		cout << wyjatek.komunikat() << endl;//program sam dobiera rodzaj problemu do rozwiazania;
	}
}



//////////////////////////

//bool wejscieFormat(string sDana) {
//	for (int i = 0; i < sDana.length(); i++) 
//		if(isdigit(sDana[i]) == false)
//			return false;
//	return true;
//}
//
//bool wejscieZakres(int iDana) {
//	if ((iDana >= 1) && (iDana <= 6)) return true;
//	else return false;
//}
//
//int main()
//{
//	string ocena;
//	cin >> ocena;
//
//	try {
//		if (wejscieFormat(ocena) == false)
//			throw ocena;
//		int sOcena = stoi(ocena);
//		if (wejscieZakres(sOcena) == false)
//			throw sOcena;
//		switch (sOcena) {
//		case 1:
//			cout << "Uczen nie zdaje";
//			break;
//		case 6:
//			cout << "Uczen zdaje";
//			break;
//		default:
//			cout << "Ocena normalna";
//			break;
//		}
//	}
//
//	catch (string ocena) {
//		cout << "Format danej wejsciowej: '" << ocena << "' nie odpowiada liczbie calkowitej";
//	}
//	catch (int sOcena) {
//		cout << "wartosc danej wejsciowej: '" << sOcena << "' nie miesci sie w zakresie";
//	}
//	
//}

///////////////////

//int main()
//{
//    try {
//        double licznik, mianownik;
//        cin >> licznik;
//        cin >> mianownik;
//        if (mianownik == 0)
//            throw mianownik;//przerywany program
//        cout << licznik << "/" << mianownik << "=" << licznik / mianownik << endl;
//    }
//    catch (double mianownik){//mozna napisac:   catch(double)  przy duzej ilosci bledow tego samego typu robi sie problem;
//        cout << "Dzielisz przez zero." << endl;
//    }
//}