#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QTextStream>
#include "thing.h"

QTextStream cout(stdout);

int Thing::s_Count = 0;

Thing::Thing(int a, int b)
    : m_First(a), m_Second(b){
        ++s_Count;
    }

Thing::~Thing(){
    --s_Count;
}

void Thing::display() const{

    cout << m_First << "$$" << m_Second;
}

void Thing::showCount() {

    cout << "Count = " << s_Count << endl;
}
