#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    QPushButton Przycisk("Napis");
    Przycisk.resize(230,40);

    w.show();
    return a.exec();
}
