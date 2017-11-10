#include "file.h"
#include "ui_file.h"
#include"mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QDataStream>
#include "packet.h"
QString p,s,n;
PacketStream ps;

File::File(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::File)
{
    ui->setupUi(this);

}

File::~File()
{

    delete ui;
}

void File::on_actionOpen_triggered()
{
    int i,A[256];

    qint32 pos,size;

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
  int q=30;int numb=1;
 while (pos<size)
  {

       file.read((char*)&ps.fHeader, 2);
       qDebug()<<ps.fHeader.magic;
       q=q+ps.fHeader.magic+14;


       if (q<size) file.seek(q);
                             else file.seek(size);
       pos=file.pos();
           qDebug()<<"Pos = "<<file.pos();
           ui->A1->setText(QString::number(pos));

           n="Packet "+ QString::number(numb);
           ui->textEdit->append(n);
           p="Pos = "+ QString::number(pos);
           ui->textEdit->append(p);
           s ="Size packet = "+ QString::number(ps.fHeader.magic);
           ui->textEdit->append(s);
           numb = numb + 1;
}
}



void File::on_Exit_clicked()
{
  File::close();
}
