#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QTimer>
#include <QMainWindow>
#include <QKeyEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void keyPressEvent(QKeyEvent*);
    explicit MainWindow(QWidget *parent = 0);
     QTimer *timer_saga;
     QTimer *timer_sola;
     QTimer *timer_yukari;
     QTimer *timer_asagi;
     QTimer *zaman;
    ~MainWindow();

signals:


public slots:
     void ilerlet();





private:
    Ui::MainWindow *ui;
    bool asagi;
    bool yukari;
    bool sag;
    bool sol;
    int sayac=0;

};

#endif // MAINWINDOW_H
