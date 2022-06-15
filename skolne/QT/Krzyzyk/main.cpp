#include "widget.h"

#include <QApplication>
#include <ctime>
#include <QGridLayout>
#include <QPushButton>
#include <QObject>
#include <QMessageBox>
#include <QString>

QPushButton *button[3][5];
bool pomalowane[3][5];

void kolor(int i, int j){
        if(pomalowane[i+1][j] == false && i < 2){
             button[i+1][j]->setStyleSheet("QPushButton {background-color: green; }");
             pomalowane[i+1][j] = true;
        }
        else if(pomalowane[i+1][j] == true && i < 2) {
            button[i+1][j]->setStyleSheet("QPushButton {background-color: white; }");
            pomalowane[i+1][j] = false;
        }

        if(pomalowane[i][j+1] == false && j < 4){
            button[i][j+1]->setStyleSheet("QPushButton {background-color: green; }");
            pomalowane[i][j+1] = true;
        }
        else if(pomalowane[i][j+1] == true && j < 4) {
            button[i][j+1]->setStyleSheet("QPushButton {background-color: white; }");
            pomalowane[i][j+1] = false;
        }

        if(pomalowane[i-1][j] == false && i > 0){
            button[i-1][j]->setStyleSheet("QPushButton {background-color: green; }");
            pomalowane[i-1][j] = true;
        }
        else if(pomalowane[i-1][j] == true && i > 0){
            button[i-1][j]->setStyleSheet("QPushButton {background-color: white; }");
             pomalowane[i-1][j] = false;
        }

        if(pomalowane[i][j-1] == false && j > 0){
             button[i][j-1]->setStyleSheet("QPushButton {background-color: green; }");
             pomalowane[i][j-1] = true;
        }
        else if(pomalowane[i][j-1] == true && j > 0){
            button[i][j-1]->setStyleSheet("QPushButton {background-color: white; }");
            pomalowane[i][j-1] = false;
        }


    }

int main(int argc, char *argv[])
{
    srand(time(NULL));

    QApplication a(argc, argv);

    QGridLayout *gridLayout = new QGridLayout;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            pomalowane[i][j] = false;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            button[i][j] = new QPushButton;
            button[i][j]->setFixedSize(100,100);

            gridLayout->addWidget(button[i][j],i,j,1,1);
            QObject::connect(button[i][j],&QPushButton::clicked,[=](){
                if(button[i][j]->text() == "X") button[i][j]->setText("");

                if(pomalowane[i][j]){
                    button[i][j]->setStyleSheet("QPushButton {background-color: white; }");
                    pomalowane[i][j] = false;
                    kolor(i,j);
                }
                else if (pomalowane[i][j] == false){
                    button[i][j]->setStyleSheet("QPushButton {background-color: green; }");
                    pomalowane[i][j] = true;
                    button[i][j]->setText("X");
                    kolor(i,j);
                }

                bool ok = true;

                for(int ii = 0; ii < 3; ii++){
                    for(int jj = 0; jj < 5; jj++){
                        if(pomalowane[ii][jj] == false){
                            ok = false;
                        }
                    }
                }

                if(ok){
                    for(int ii = 0; ii < 3; ii++){
                        for(int jj = 0; jj < 5; jj++){
                            button[ii][jj]->setDisabled(1);
                        }
                    }
                }
            });
        }
    }

    Widget w;
    w.setFixedSize(600,400);
    w.setLayout(gridLayout);
    w.show();
    return a.exec();
}
