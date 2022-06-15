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


QLineEdit *edit[3][3];
QString plansza[3][3];
int poz_wypelniony = 0;

using namespace std;

void win(){
    bool ok = true;
    for(int i = 0; i < 3; i++){
       for(int j = 0; j < 3; j++){
            if(edit[i][j]->isEnabled() == true){
                ok = false;
            }
       }
    }
    if(ok){
        QMessageBox msg;
        msg.setText("Wygrales!");
        msg.exec();
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    QGridLayout *gridLayout = new QGridLayout;
    QString liczby[11] = {"0","1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
    QString wartosci[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    QIntValidator *val = new QIntValidator(1,9);

    for(int i =0;i<=50;i++){
        swap(liczby[rand()%8], liczby[rand()%8]);
    }

    for(int i = 0; i < 3; i++){
       for(int j = 0; j < 3; j++){
            edit[i][j] = new QLineEdit;
            edit[i][j]->setFixedSize(100,100);
            edit[i][j]->setValidator(val);
       }
    }

    int temp = 0;

    for(int i = 0; i < 9; i++){
        int ii = rand()%3;
        int jj = rand()%3;
        plansza[ii][jj] = liczby[temp++];
        if(plansza[ii][jj] == "0"){
            edit[ii][jj]->setText("");
        }
        else {
            edit[ii][jj]->setText(plansza[ii][jj]);
            edit[ii][jj]->setEnabled(0);
        }
    }

    for(int i = 0; i < 3; i++){
       for(int j = 0; j < 3; j++){
           gridLayout->addWidget(edit[i][j],i,j,1,1);
            QObject::connect(edit[i][j],&QLineEdit::textChanged,[=](){
                bool w = true;
                for(int ii = 0; ii < 3; ii++){
                   for(int jj = 0; jj < 3; jj++){
                       if(ii == i && jj == j){

                       }
                       else if(edit[i][j]->text() == edit[ii][jj]->text()){
                            edit[i][j]->setText("");
                            edit[i][j]->setEnabled(1);
                            w = false;
                       }
                    }
                }
                if(w){
                     edit[i][j]->setDisabled(1);
                }
            });
       }
    }

    Widget w;
    w.setFixedSize(450,450);
    w.setLayout(gridLayout);
    w.show();
    return a.exec();
}
