#include "fraction.h"
#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QTextStream>

void Fraction::set(int nn, int dn){
    m_Numer = nn;
    m_Denom = dn;
}

double Fraction::toDouble() const{
    return 1.0 * m_Numer / m_Denom;
}

QString Fraction::toString() const{
    return QString("%1 / %2").arg(m_Numer).arg(m_Denom);
}

Fraction Fraction::add(const Fraction &other){
    Fraction f;
    f.m_Numer = m_Numer * other.m_Denom + m_Denom * other.m_Numer;
    f.m_Denom = m_Denom * other.m_Denom;
    return f;
}

Fraction Fraction::subtract(const Fraction &other) {
    Fraction f;
    f.m_Numer = m_Numer * other.m_Denom - m_Denom * other.m_Numer;
    f.m_Denom = m_Denom * other.m_Denom;
    return f;
}

Fraction Fraction::multiply(const Fraction &other) {
    Fraction f;
    f.m_Numer = m_Numer * other.m_Numer;
    f.m_Denom = m_Denom * other.m_Denom;
    return f;
}

Fraction Fraction::divide(const Fraction &other) {
    Fraction f;
    f.m_Numer = m_Numer * other.m_Denom;
    f.m_Denom = m_Denom * other.m_Numer;
    return f;
}
