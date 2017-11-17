#include "file.h"
#include "ui_file.h"
#include"mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QDataStream>
#include "packet.h"
QString p,s,n,str;
PacketStream ps;
Packet ph;
long int A[2000],Pos[2000],NumberPacket,max=0,min=65000000;
 QString fName;
 long int q=30;int numb=0;

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
    qint32 pos,size;

   fName = QFileDialog::getOpenFileName(0, "Open file","","CAP files (*.*cap)");


    if ( fName == "" )
        return;

    QFile file(fName);

    if (!file.open(QIODevice::ReadOnly))
    {
        ui->A1->setText("error open file");
            return ;
    }

 pos=file.pos();
 size=file.size();
 for(int i=0;i<2000;i++)
 {
     A[i]=0;
     Pos[i]=0;
 }



  ui->A1->setText(fName);
   file.read((char*)&ps.fHeader, 24);
   ui->textEdit->append("Header: ");
   ui->textEdit->append("Magic: "+ QString::number(ps.fHeader.magic));
   ui->textEdit->append("Version Major: "+ QString::number(ps.fHeader.version_major));
    ui->textEdit->append("Version Minor: "+ QString::number(ps.fHeader.version_minor));
     ui->textEdit->append("thiszone: "+ QString::number(ps.fHeader.thiszone));
    ui->textEdit->append("sigfigs: "+ QString::number(ps.fHeader.sigfigs));
    ui->textEdit->append("snaplen: "+ QString::number(ps.fHeader.snaplen));
    ui->textEdit->append("linktype: "+ QString::number(ps.fHeader.linktype));
     ui->textEdit->append(" ");
file.seek(30);
long int k=0,r;

while (pos<size)
  {
 k++;
 numb++;
       file.read((char*)&ph.pHeader,2);
       q=q+ph.pHeader.caplen+14;
 pos=file.pos();
    if (q<size) file.seek(q);
                             else file.seek(size);

           n="Packet "+ QString::number(numb);
           ui->textEdit->append(n);
           p="Pos = "+ QString::number(pos);
           ui->textEdit->append(p);
           s ="Size packet = "+ QString::number(ph.pHeader.caplen);
            qDebug()<<QString::number(ph.pHeader.caplen);
           ui->textEdit->append(s);

          ui->textEdit->append(" ");
          A[k]=ph.pHeader.caplen;
          Pos[k]=pos+8;

  }
 for(int i=1;i<numb;i++)
 { if(min>A[i])
         min=A[i];
     if (max<A[i])
         max=A[i];
      };

 ui->textEdit->append("Max Len: "+ QString::number(max));
 ui->textEdit->append("Min Len: "+ QString::number(min));
}

void File::on_Exit_clicked()
{
  File::close();
}
void File::on_spinBox_valueChanged(int arg1)
{
   NumberPacket=arg1;

}
void File::on_pushButton_clicked()
{
        QFile file(fName);
        if(NumberPacket>numb)
            ui->textEdit_2->append("Error");
        else
        {
    file.seek(Pos[NumberPacket]);
    file.read((char*)&ph.data,A[NumberPacket]);
    for (int i=0;i<A[NumberPacket];i++)
    {//ui->textEdit_2->append(QString::number(ph.data[i]));
        str= str+ QString::number(ph.data[i])+" ";
    };
     ui->textEdit_2->append("Packet "+QString::number(NumberPacket));
    ui->textEdit_2->append(str);

}
}

