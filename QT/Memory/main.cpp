#include "widget.h"
#include "ui_widget.h"

#include <QApplication>
#include <ctime>
#include <QGridLayout>
#include <QPushButton>
#include <QObject>
#include <QMessageBox>
#include <QString>
#include <QTimer>

using namespace std;

QPushButton *button[4][4];
QString plansza[4][4];
int ii = -1, jj = -1, memory = 0;

void see(int i, int j){

    button[i][j]->setText(plansza[i][j]);
    button[i][j]->setEnabled(0);
    if(ii == -1 && jj == -1){
        ii = i;
        jj = j;
    }
    memory++;
}

void win(){
    bool ok = true;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(button[i][j]->isEnabled() == true){
                ok = false;
            }
        }
    }
    if(ok){
        QMessageBox msg;
        msg.setText("Wygrales");
        msg.exec();
    }
}

void hideAll(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            button[i][j]->setText("");
        }
    }
}

void showAll(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            button[i][j]->setText(plansza[i][j]);
        }
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    QGridLayout *gridLayout = new QGridLayout;
    QString licznik[16] = {"1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8"};

    for(int i =0;i<=50;i++){
        swap(licznik[rand()%16], licznik[rand()%16]);
    }

    int temp = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            plansza[i][j] = licznik[temp++];
            button[i][j] = new QPushButton;
            button[i][j]->setText("");
            button[i][j]->setFixedSize(100,100);
            gridLayout->addWidget(button[i][j],i,j,1,1);
            QObject::connect(button[i][j],&QPushButton::clicked,[=](){
                see(i,j);
                if(memory >= 2){
                    QTimer::singleShot(600, [=](){
                        if(button[i][j]->text() != button[ii][jj]->text()){
                            button[i][j]->setText("");
                            button[ii][jj]->setText("");
                            button[i][j]->setEnabled(1);
                            button[ii][jj]->setEnabled(1);
                        }
                        memory = 0;
                        ii = -1;
                        jj = -1;
                        win();
                    });
                }
            });
        }
    }

    QPushButton *Start = new QPushButton;
    gridLayout->addWidget(Start,5,2,1,2);
    Start->setText("Start");
    QObject::connect(Start,&QPushButton::clicked,[=](){
        showAll();
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                button[i][j]->setEnabled(1);
            }
        }
        QTimer::singleShot(5000, [=](){
            hideAll();
            Start->setEnabled(0);
        });
    });

    QPushButton *Hide = new QPushButton;
    gridLayout->addWidget(Hide,5,0,1,2);
    Hide->setText("Showaj");
    QObject::connect(Hide,&QPushButton::clicked,[=](){
        hideAll();
        Start->setEnabled(1);
    });


    Widget w;
    w.setFixedSize(450,450);
    w.setLayout(gridLayout);
    w.show();
    return a.exec();
}

