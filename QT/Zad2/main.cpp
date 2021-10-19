#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QTextStream>
#include "fraction.h"
#include "fraction.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);

    Fraction f;
    f.set(2, 4);
    f.add(f);
    f.substract(f);
    f.multiply(f);
    f.divide(f);

    return a.exec();
}
