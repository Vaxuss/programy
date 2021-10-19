#ifndef FRACTION_H
#define FRACTION_H


#include <QString>

class Fraction{
public:
    void set(int numer, int denom);
    double toDouble() const;
    QString toString() const;
    Fraction add(Fraction& other) const;
    Fraction substract(Fraction& other) const;
    Fraction multiply(Fraction& other) const;
    Fraction divide(Fraction& other) const;

private:
    int m_Numer = 2;
    int m_Denom = 4;
};

double Fraction::toDouble() const{
    return 1.0 * m_Numer / m_Denom;
}

QString Fraction::toString() const{
    return QString("%1 / %2").arg(m_Numer).arg(m_Denom);
}

#endif // FRACTION_H
