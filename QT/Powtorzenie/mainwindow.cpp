#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    float dzielenie, liczba1, liczba2;
    liczba1 = ui->spinBox->value();
    liczba2 = ui->spinBox_2->value();
    dzielenie = liczba1 / liczba2;
    ui->wynik->setText(QString::number(dzielenie, 'f', ui->Slider->value()));
}
