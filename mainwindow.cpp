#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include "file.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QDataStream>
#include "packet.h"
int y;
Calculator *f;
File *k;
PacketStream ps;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    f=new Calculator();
    ui->setupUi(this);
    k=new File();
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pbCalculator_clicked()
{
    f->show();
}

void MainWindow::on_actionOpen_triggered()
{
    int i,A[256];

    qint32 pos,size;
   // k->show();
    QString fName = QFileDialog::getOpenFileName(0, "Open file","","CAP files (*.*cap)");

 qDebug() << fName;
    if ( fName == "" )
        return;

    QFile file(fName);

    if (!file.open(QIODevice::ReadOnly))
    {
            qDebug() << "error open file";

            return ;
    }

qDebug()<<"size = "<<file.size();
qDebug()<<"Pos = "<<file.pos();
pos=file.pos();
size=file.size();
file.seek(30);
qDebug()<<"Pos = "<<file.pos();
  int q=30;
  /*file.read((char*)&ps.fHeader, 2);//16 байт заголовок pcap
  qDebug()<<ps.fHeader.magic;*/

 while (pos<size)
  {
       file.read((char*)&ps.fHeader, 2);
       qDebug()<<ps.fHeader.magic;
       q=q+2+ps.fHeader.magic;

       pos=file.pos();
       if (q<size) file.seek(q);
                             else file.seek(size);
           qDebug()<<"Pos = "<<file.pos();

  }
}





