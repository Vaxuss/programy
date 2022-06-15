#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    s1 = 1;
    s2 = 1;

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wylosuj(int tab[50], int ile){
    int licznik = 0, liczba;
    bool czyIstnieje;
    for(int i=0;i<50;i++) tab[i]=0;
    while(licznik<ile){
        liczba = rand()%50+1;
        czyIstnieje = true;
        for(int i=0;i<licznik;i++){
            if(tab[i] == liczba) czyIstnieje = false;
        }
        if(czyIstnieje){
            tab[licznik] = liczba;
            licznik++;
        }
    }
}

int MainWindow::powtorzenia(int t1[50],int ile1, int t2[50], int ile2){
    int licznik = 0;
    for(int i=0;i<ile1;i++){
        for(int j = 0; j< ile2; j++){
            if(t1[i] == t2[j]) licznik++;
        }
    }
    return licznik;
}


void MainWindow::on_Slider1_valueChanged(int value)
{
    s1 = value;
    wylosuj(tab1,s1);
    ui->label->setNum(powtorzenia(tab1, s1, tab2, s2));
}


void MainWindow::on_Slider2_valueChanged(int value)
{
    s2 = value;
    wylosuj(tab2,s2);
    ui->label->setNum(powtorzenia(tab1, s1, tab2, s2));
}



