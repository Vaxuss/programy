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
	if ((iDana >= 1) && (iDana <= 100)) return true;
	else return false;
}

bool wejsciePozaJeden(string fDana) {
	if ((stoi(fDana) < 10) && (fDana.length() <= 1)) return true;
	else return false;
}

class Format : public Wyjatek {
	string sLiczba;
public:
	Format(string sLiczba) : sLiczba(sLiczba) {};// przypisanie wartosci do sOcena;
	string komunikat() {
		stringstream sTemp;
		sTemp << "Format dane wejsciowej '" << sLiczba << "' nie odpowiada liczbie calkowitej" << endl;
		return sTemp.str();
	}
};

class Zakres : public Wyjatek {
	string liczba;
public:
	Zakres(string liczba) : liczba(liczba) {};
	string  komunikat() {
		stringstream sTemp;
		sTemp << "Wartosc danej wejsciowej '" << liczba << "' jest poza zakresem" << endl;
		return sTemp.str();
	}
};

int main()
{
	string liczba1, liczba2;
	cin >> liczba1;
	cin >> liczba2;
	try {
		if (wejscieFormat(liczba1) == false)
			throw Format(liczba1);
		if (wejscieFormat(liczba2) == false)
			throw Format(liczba2);
		if (wejsciePozaJeden(liczba2) == false)
			throw Zakres(liczba2);
		if (wejscieZakres(stoi(liczba1)) == false)
			throw Zakres(liczba1);
		

		liczba1 += liczba2;
		float liczba = stoi(liczba1);
		liczba /= 10;
		liczba *= 2;
		cout << "Pole to: " << liczba;
	}
	catch (Wyjatek& wyjatek) {
		cout << wyjatek.komunikat() << endl;//program sam dobiera rodzaj problemu do rozwiazania;
	}
}

