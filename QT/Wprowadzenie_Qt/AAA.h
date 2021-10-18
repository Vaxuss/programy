#ifndef AAA_H
#define AAA_H

#include <Qstring>

class Fraction{
public:
    void set(int numer, int denom);
    double toDouble() const;
    QString toString() const;
private:
    int m_Numer;
    int m_Denom;
};

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

#endif // AAA_H
