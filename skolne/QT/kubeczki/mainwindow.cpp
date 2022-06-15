#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::losuj(){
    int ktory_przycisk = rand()%3 + 1;
    return ktory_przycisk;
}

void MainWindow::on_pushButton_clicked()
{
    ui->b1->setEnabled(1);
    ui->b2->setEnabled(1);
    ui->b3->setEnabled(1);
    ui->label->setText("");
    ui->pushButton->setEnabled(0);
}


void MainWindow::on_b1_clicked()
{
    int wylosowane = losuj();

     QMessageBox msg;

     if(wylosowane == 3){
          msg.setText("Wygrałeś!");
          msg.exec();
          wyg++;
          ui->wyg->setNum(wyg);
     }else{
         msg.setText("Przegrałeś!");
         msg.exec();
         prz++;
         ui->prz->setNum(prz);
     }
    setEnable();
}


void MainWindow::on_b2_clicked()
{
    int wylosowane = losuj();

     QMessageBox msg;

     if(wylosowane == 3){
          msg.setText("Wygrałeś!");
          msg.exec();
          wyg++;
          ui->wyg->setNum(wyg);
     }else{
         msg.setText("Przegrałeś!");
         msg.exec();
         prz++;
         ui->prz->setNum(prz);
     }
    setEnable();
}


void MainWindow::on_b3_clicked()
{
    int wylosowane = losuj();

    QMessageBox msg;

    if(wylosowane == 3){
         msg.setText("Wygrałeś!");
         msg.exec();
         wyg++;
         ui->wyg->setNum(wyg);
    }else{
        msg.setText("Przegrałeś!");
        msg.exec();
        prz++;
        ui->prz->setNum(prz);
    }
    setEnable();
}

void MainWindow::setEnable(){
    ui->b1->setEnabled(0);
    ui->b2->setEnabled(0);
    ui->b3->setEnabled(0);
    ui->pushButton->setEnabled(1);
}

