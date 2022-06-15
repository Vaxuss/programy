#include <iostream>

using namespace std;

/////zad6//////

template <class T>
class Srednie {
public:
	T pJp, pJa, pM, pI;
	T srednia() {
		pJp += pJa + pM + pI;
		return (pJp / 4);
	}
	T sredniaWazona() {
		pJp = pJp * 0.1 + pJa * 0.2 + pM * 0.4 + pI * 0.3;
		return (pJp / 4);
	}
};


int main() {
	double jp = 0, ja = 0, m = 0, i = 0;

	cin >> jp;
	cin >> ja;
	cin >> m;
	cin >> i;

	Srednie <double> s{ jp, ja, m, i };

	cout << "Srednia to: " << s.srednia() << endl;
	cout << "Srednia wazona to: " << s.sredniaWazona() << endl;

}



/////zad4//////

//template <typename T>
//T srednia(T pJp, T pJa, T pM, T pI) {
//	pJp += pJa + pM + pI;
//	return (pJp / 4);
//}
//
//template <typename W>
//W sredniaWazona(W pJp, W pJa, W pM, W pI) {
//	pJp = pJp * 0.1 + pJa * 0.2 + pM * 0.4 + pI * 0.3;
//	return (pJp / 4);
//}
//
//
//int main() {
//	double jp = 0, ja = 0, m = 0 , i = 0;
//
//	cin >> jp;
//	cin >> ja;
//	cin >> m;
//	cin >> i;
//
//	cout << "Srednia to: " << srednia(jp, ja, m, i) << endl;
//	cout << "Srednia wazona to: " << sredniaWazona(jp, ja, m, i) << endl;
//
//}




/////zad3//////

//template <class T>
//class Prostokat {
//	public:
//		T bok1, bok2;
//		T pole() {
//			return (bok1 * bok2);
//		}
//		T obwod() {
//			return (bok1 * 2 + bok2 * 2);
//		}
//};
//
//template <class O>
//class Kolo {
//public:
//	O r;
//	O poleK() {
//		return (3.14 * r * r);
//	}
//	o obwK() {
//		return(2 * 3.14 * r);
//	}
//};
//
//int main()
//{
//	float bok1, bok2, r;
//	cout << "Podaj boki: " << endl;
//	cin >> bok1;
//	cin >> bok2;
//	cout << "Podaj promien: " << endl;
//	cin >> r;
//
//	Prostokat<float> p{ bok1, bok2 };
//	Kolo<float> k{r};
//
//	cout << "Pole Kwadratu to: " << p.pole() << endl;
//	cout << "Pole Prostokata to: " << p.pole() << endl;
//	cout << "Obwod Kwadratu to: " << p.obwod() << endl;
//	cout << "Obwod Kwadratu to: " << p.obwod() << endl;
//	cout << "Pole Kola to: " << k.poleK() << endl;
//	cout << "Obwod Kola to: " << k.obwK() << endl;
//
//}



/////zad1//////

//template <typename T>
//T poleKwadratu(T pBok1, T pBok2) {
//	return (pBok1 * pBok2);
//}
//
//template <typename C>
//C obwodKw(C pBok1, C pBok2) {
//	return (pBok1 * 2 + 2 * pBok2);
//}
//
//template <typename O>
//O poleKola(O promien) {
//	return (3.14 * promien * promien);
//}
//
//template <typename K>
//K obwKola(K promien) {
//	return (2 * 3.14 * promien);
//}
//
//
//int main()
//{
//	float bok1, bok2, r;
//	cout << "Podaj boki: " << endl;
//	cin >> bok1;
//	cin >> bok2;
//	cout << "Podaj promien: " << endl;
//	cin >> r;
//	
//	cout << "Pole Kwadratu to: " << poleKwadratu < float >(bok1, bok1) << endl;
//	cout << "Pole Prostokata to: " << poleKwadratu < float >(bok1, bok2) << endl;
//	cout << "Obwod Kwadratu to: " << obwodKw < float >(bok1, bok1) << endl;
//	cout << "Obwod Kwadratu to: " << obwodKw < float >(bok1, bok2) << endl;
//	cout << "Pole Kola to: " << poleKola < float >(r) << endl;
//	cout << "Obwod Kola to: " << obwKola < float >(r) << endl;
//
//}
