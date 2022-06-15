#include "widget.h"

#include <QApplication>
#include <ctime>
#include <QGridLayout>
#include <QPushButton>
#include <QObject>
#include <QMessageBox>
#include <QString>

using namespace std;

int ii,jj;
QPushButton *button[3][3];

void change(int i, int j){
    bool ok = false;
    for(int h = -1; h <= 1;h += 2){
        if((i+h == ii)&&(j == jj)) ok = true;
        if((i == ii)&&(j+h == jj)) ok = true;
        if(ok){
            button[ii][jj]->setText(button[i][j]->text());
            button[i][j]->setText(" ");
            ii = i;
            jj = j;
        }
    }
}

bool winner(){
    int licznik = 1;
    bool ok = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(licznik!=9){
                if(button[i][j]->text().toInt() != licznik) ok = false;
            }
            licznik++;
        }
    }
    return ok;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    QGridLayout *gridLayout = new QGridLayout;

    QString liczby[9] = {"1","2","3","4","5","6","7","8"," "};
    for(int i =0;i<=50;i++){
        swap(liczby[rand()%9], liczby[rand()%9]);
    }

    int licznik = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0;j < 3; j++){
            button[i][j] = new QPushButton;
            if(liczby[licznik] == " "){
                ii = i;
                jj = j;
            }
            button[i][j]->setText(liczby[licznik++]);
            button[i][j]->setFixedSize(100,100);
            //button[i][j]->setStyleSheet("width:100px;//ogolem css");
            gridLayout->addWidget(button[i][j],i,j,1,1);
            QObject::connect(button[i][j],&QPushButton::clicked,[=](){
                change(i,j);
                QMessageBox mb;
                mb.setWindowTitle("Wynik");
                mb.setText("Wygrana!");
                if(winner()){
                    mb.exec();
                }
            });
        }
    }
    Widget w;
    w.setFixedSize(350,350);
    w.setLayout(gridLayout);
    w.show();
    return a.exec();
}
