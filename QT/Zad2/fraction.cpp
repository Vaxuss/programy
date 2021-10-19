#include "fraction.h"
#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QTextStream>

void Fraction::set(int nn, int dn){
    m_Numer = nn;
    m_Denom = dn;
}

Fraction Fraction::add(Fraction &other) const{
    QTextStream cout(stdout);
    Fraction f;
    cout<< "Dodawanie: " << f.m_Numer + f.m_Denom <<endl;
    return f;
}

Fraction Fraction::substract(Fraction &other) const{
    QTextStream cout(stdout);
    Fraction f;
    cout << "Odejmowanie: " << f.m_Numer - f.m_Denom << endl;
    return f;
}

Fraction Fraction::multiply(Fraction &other) const{
    QTextStream cout(stdout);
    Fraction f;
    cout << "Mnozenie: " << f.m_Numer * f.m_Denom << endl;
    return f;
}

Fraction Fraction::divide(Fraction &other) const{
    QTextStream cout(stdout);
    Fraction f;
    cout << "Dzielenie: " << f.m_Numer / f.m_Denom << endl;
    return f;
}
