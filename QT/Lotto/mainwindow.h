#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int tab1[50], tab2[50],s1,s2;

    void wylosuj(int tab[50], int ile);
    int powtorzenia(int t1[50],int ile1, int t2[50], int ile2);

private slots:
    void on_Slider1_valueChanged(int value);

    void on_Slider2_valueChanged(int value);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
