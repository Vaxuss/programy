#include "widget.h"

#include <QApplication>
#include <ctime>
#include <QGridLayout>
#include <QPushButton>
#include <QObject>
#include <QMessageBox>
#include <QString>
#include <QTimer>
#include <QLineEdit>
#include <QValidator>


QPushButton *cell[5][5];
bool plansza[5][5];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));

    QGridLayout *gridLayout = new QGridLayout;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            plansza[i][j] = false;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cell[i][j] = new QPushButton;
            cell[i][j]->setFixedSize(100,100);
            gridLayout->addWidget(cell[i][j],i,j,1,1);
            QObject::connect(cell[i][j],&QPushButton::clicked,[=](){
                if(plansza[i][j]){
                    cell[i][j]->setStyleSheet("QPushButton {background-color: white}");
                    plansza[i][j] = false;
                }
                else{
                    cell[i][j]->setStyleSheet("QPushButton {background-color: green}");
                    plansza[i][j] = true;
                }

            });
        }
    }


    QPushButton *start = new QPushButton;
    start->setText("Zycie");
    start->setFixedHeight(100);
    gridLayout->addWidget(start,6,0,1,5);
    QObject::connect(start,&QPushButton::clicked,[=](){
        int next = 0;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(plansza[i][j]){
                    for(int x = 0; x < 2; x++){
                        for(int y = 0; y < 2; y++){
                            if(plansza[i-x][j-x] == true) next++;
                            if(plansza[i+x][j+x] == true) next++;
                        }
                    }
                    if(next < 3){
                        cell[i][j]->setStyleSheet("QPushButton {background-color: white}");
                        plansza[i][j] = false;
                    }
                    if(next == 3){
                        for(int x = 0; x < 2; x++){
                            for(int y = 0; y < 2; y++){
                                if(plansza[i-x][j-x] == true)  cell[i][j]->setStyleSheet("QPushButton {background-color: green}");
                                if(plansza[i+x][j+x] == true)  cell[i][j]->setStyleSheet("QPushButton {background-color: green}");
                            }
                        }
                    }
                    if(next > 3){
                        cell[i][j]->setStyleSheet("QPushButton {background-color: white}");
                        plansza[i][j] = false;
                    }
                }
            }
        }

    });

    Widget w;
    w.setFixedSize(650,650);
    w.setLayout(gridLayout);
    w.show();
    return a.exec();
}
