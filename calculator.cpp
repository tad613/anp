
#include "calculator.h"
#include "ui_calculator.h"
#include "QWidget"
#include "QStack"
#include "math.h"
#include <QtGui>
int  i;
int  m=0;
double  a=0, b=0;


Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{

 delete ui;
}

void Calculator::on_pb1_clicked()
{
    a=a*10 + 1;
    ui->A->setText(QString::number(a));

}

void Calculator::on_pb2_clicked()
{
    a=a*10 + 2;
    ui->A->setText(QString::number(a));
}

void Calculator::on_pb3_clicked()
{
    a=a*10 + 3;
    ui->A->setText(QString::number(a));
}

void Calculator::on_pb4_clicked()
{
    a=a*10 + 4;
    ui->A->setText(QString::number(a));
}

void Calculator::on_pb5_clicked()
{
    a=a*10 + 5;
    ui->A->setText(QString::number(a));
}

void Calculator::on_pb6_clicked()
{
    a=a*10 + 6;
    ui->A->setText(QString::number(a));
}

void Calculator::on_pb7_clicked()
{
    a=a*10 + 7;
    ui->A->setText(QString::number(a));
}

void Calculator::on_pb8_clicked()
{
    a=a*10 + 8;
    ui->A->setText(QString::number(a));
}

void Calculator::on_pb9_clicked()
{
    a=a*10 + 9;
    ui->A->setText(QString::number(a));
}

void Calculator::on_pb0_clicked()
{
    a=a*10;
    ui->A->setText(QString::number(a));
}

void Calculator::on_pbAllDelete_clicked()
{
    a=0;
    ui->A->setText(QString::number(a));
}

void Calculator::on_pbPlus_clicked()
{
  b=a;
  a=0;
   m=1;
}

void Calculator::on_pbMinus_clicked()
{
    b=a;
    a=0;
     m=2;

}

void Calculator::on_pbUmn_clicked()
{
    b=a;
    a=0;
     m=3;

}

void Calculator::on_pbDelenie_clicked()
{
    b=a;
    a=0;
     m=4;
}

void Calculator::on_pbRavno_clicked()
{
    if (m==1){
        a=a+b;}
    if (m==2){
        a=b-a;}
    if (m==3){
        a=a*b;}
    if (m==4){

        a=b/a;}
    if (m==5)
    {
         for(i=1;i<=b;i++)
            {
                a=a*i;
            }

     }
    if (m==6){
        a=a*a;}
    if (m==7)
    {
     a= pow(b,a) ;
    }
    if (m==8){
        a=sqrt(a);}

     ui->A->setText(QString::number(a));

}

void Calculator::on_pbFactorial_clicked()
{
    b=a;
    m=5;
   a=1;
}

void Calculator::on_pbSQR_clicked()
{
  m=6;

}

void Calculator::on_pbStepen_clicked()
{
    b=a;
    m=7;
    a=0;
}

void Calculator::on_pbSqrt_clicked()
{
    m=8;
}
