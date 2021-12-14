#include <iostream>
#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QTextStream>
#include "fraction.h"
#include "fraction.cpp"

using namespace std;
int main(int argc, char *argv[])
{
    QTextStream cout(stdout);

    Fraction f;
    f.set(2, 4);
    Fraction f1;
    f1.set(3,4);
    Fraction f2;
    f2 = f.add(f1);
    cout << f2.toString();
    f2 = f.subtract(f1);
    cout << f2.toString();
    f2 = f.multiply(f1);
    cout << f2.toString();
    f2 = f.divide(f1);
    cout << f2.toString();
}
