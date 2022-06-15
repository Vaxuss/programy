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
    int prz = 0, wyg = 0;

private slots:
    void on_pushButton_clicked();
    int losuj();
    void setEnable();

    void on_b1_clicked();

    void on_b2_clicked();

    void on_b3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
