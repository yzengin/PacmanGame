#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

#include <QDebug>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    asagi = false;
    yukari = false;
    sag = false;
    sol = false;
    ui->setupUi(this);
    ui->label->setText(QString::number(sayac));
    QString path2= ":/resim/yem.png";
    QImage resim2(path2);
    ui->yem_label->setScaledContents(true);
    ui->yem_label->setPixmap(QPixmap::fromImage(resim2));
    ui->yem_label->setGeometry(qrand()%744,qrand()%388,25,25);
    QString path= ":/resim/pacman.png";
    QImage resim(path);
    ui->pacman_label->setPixmap(QPixmap::fromImage(resim));
    ui->pacman_label->setGeometry(10,110,35,35);

    timer_asagi = new QTimer();
    connect(timer_asagi,SIGNAL(timeout()),this,SLOT(ilerlet()));
    timer_asagi->start(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ilerlet()
{
    if(sag==true){QTimer *timer_yukari;
        if((ui->pacman_label->x()+ui->pacman_label->width())<width())
        {
            int x= ui->pacman_label->x();
            int y= ui->pacman_label->y();
            int w=ui->pacman_label->width();
            int h=ui->pacman_label->height();
            ui->pacman_label->setGeometry(x+10 , y, w, h);
         }
    }
    else if(sol==true){
        if(ui->pacman_label->x()!=0)
        {
            int x= ui->pacman_label->x();
            int y= ui->pacman_label->y();
            int w=ui->pacman_label->width();
            int h=ui->pacman_label->height();
            ui->pacman_label->setGeometry(x-10 , y, w, h);
        }
    }
    else if(asagi==true){
        if((ui->pacman_label->y()+ui->pacman_label->height())<height()-35)
        {
            int x= ui->pacman_label->x();
            int y= ui->pacman_label->y();
            int w=ui->pacman_label->width();
            int h=ui->pacman_label->height();
            ui->pacman_label->setGeometry(x , y+10, w, h);
          }
    }
    else if(yukari==true){
        if(ui->pacman_label->y()!=0)
        {
            int x= ui->pacman_label->x();
            int y= ui->pacman_label->y();
            int w=ui->pacman_label->width();
            int h=ui->pacman_label->height();
            ui->pacman_label->setGeometry(x , y-10, w, h);
        }
    }
    int x = ui->pacman_label->x();
    int yem_x = ui->yem_label->x();
    int x_ = ui-> pacman_label->x()+ui->pacman_label->width();
    int y = ui->pacman_label->y();
    int yem_y = ui->yem_label->y();
    int y_ = ui->pacman_label->y()+ui->pacman_label->height() ;
    if((x<yem_x && yem_x<x_)&&(y<yem_y && yem_y<y_)){
            sayac=sayac+1;
            ui->yem_label->setGeometry(qrand()%740,qrand()%380,25,25);
            ui->label->setText(QString::number(sayac));
            ui->pacman_label->resize(ui->pacman_label->width()+10,ui->pacman_label->height()+10);
        }

}
 void MainWindow::keyPressEvent(QKeyEvent *event)
 {

     switch(event->key()){

         case Qt::Key_Up:
            asagi = false;
            yukari = true;
            sag = false;
            sol = false;
            break;

         case Qt::Key_Right:
             asagi = false;
             yukari = false;
             sag = true;
             sol = false;
             break;

         case Qt::Key_Left:
             asagi = false;
             yukari = false;
             sag = false;
             sol = true;
             break;

         case Qt::Key_Down:
             asagi = true;
             yukari = false;
             sag = false;
             sol = false;
             break;
         }
 }


