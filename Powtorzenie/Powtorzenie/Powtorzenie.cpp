#include <iostream>
#include <vector>

using namespace std;


////////////////////////////////////////////
//FRIENDS
////////////////////////////////////////////

class Prostokat;

class Ostroslup {
	int h;
public:
	Ostroslup(int _h){
		h = _h;
	}
	float obj(Prostokat);
};

class Prostokat {
	int a, b;
public:
	Prostokat(int _a, int _b) {
		a = _a;
		b = _b;
	}
	friend float Ostroslup::obj(Prostokat); // to frienduje tylko metode;
	//friend Ostroslup; // to frienduje cala klase
};

float Ostroslup::obj(Prostokat p)
{
	return (1.0f / 3.0f * p.a * p.b * h);
}

int main()
{
	Prostokat p1(5,7);
	Ostroslup o1(7);
	cout << o1.obj(p1);
}

//////////////////////////////////////////////
////TEMPLATE KLAS
//////////////////////////////////////////////
//template <class T>
//class Prostokat {
//public:
//	T bok1, bok2;
//	T pole() {
//		T p = bok1 * bok2;
//		return p;
//	}
//	T obwod();
//	void wypisz() {
//		cout << bok1 << " " << bok2 << endl;
//	}
//};
//
//int main()
//{
//	Prostokat<int> p1{ 2, 5 };
//	cout << p1.pole() << endl;
//	cout << p1.obwod() << endl;
//	p1.wypisz();
//}
//
//template<class T>
//T Prostokat<T>::obwod()
//{
//	T o = 2 * bok1 + 2 * bok2;
//	return o;
//}

//////////////////////////////////////////////
////TEMPLATE FUNKCJI
//////////////////////////////////////////////
//template <typename T>
//T pole(T bok1, T bok2) {
//    T p = bok1 * bok2;//moga byc uzywane wewnatrz inne typy danych np: int string itd;
//    return p;
//}
//
//template<>
//double pole(double bok1, double bok2) {
//    double p = bok1 + bok2;
//    return p;
//}
//
//int main()
//{
//    cout << pole(3.3, 5.3) << endl;
//    cout << pole(3, 5) << endl;
//}
