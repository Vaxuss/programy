#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

class Promien;

class Kolo {
public:
    double pole(Promien pPromien);
    double obwod(Promien pPromien);


   /* Kolo() {

    }
    Kolo(double r) {
        _r = r;
    }
    void setPromien(double);
    double getPromien();
    double pole();
    double obwod();
    friend void setPromienFriendKolo(Kolo&, double);
    friend double getPromienFriendKolo(Kolo);*/
};

class Promien {
private:
    double _r;
public:
    void setPromien(double r) {
        _r = r;
    }
    double getPromien() {
        return _r;
    }
    friend double Kolo::pole(Promien);
    friend double Kolo::obwod(Promien);
};

double Kolo::pole(Promien pPromien) {
    return 3.14 * pPromien._r * pPromien._r;
}

double Kolo::obwod(Promien pPromien) {
    return 2 * 3.14 * pPromien._r;
}

int main()
{   
    Promien p;
    p.setPromien(5);

    Kolo k;
    cout << k.pole(p) << endl;
    cout << k.obwod(p) << endl;

   /* Kolo k1;
    k1.setPromien(5);
    cout << k1.getPromien() << endl;
    cout << k1.pole() << endl;
    cout << k1.obwod() << endl;

    Kolo k2;
    setPromienFriendKolo(k2, 3);
    cout << getPromienFriendKolo(k2) << endl;
    cout << k2.pole() << endl;
    cout << k2.obwod() << endl;*/
}

//void Kolo::setPromien(double r)
//{
//    _r = r;
//}
//
//double Kolo::getPromien()
//{
//    return _r;
//}
//
//double Kolo::pole()
//{
//    return 3.14 * _r * _r;
//}
//
//double Kolo::obwod()
//{
//    return 2 * 3.14 * _r;
//}
//
//void setPromienFriendKolo(Kolo& kolo, double r)
//{
//    kolo._r = r;
//}
//
//double getPromienFriendKolo(Kolo kolo)
//{
//    return kolo._r;
//}
