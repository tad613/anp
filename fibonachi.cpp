#include "fibonachi.h"
#include "ui_fibonachi.h"



Fibonachi::Fibonachi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fibonachi)
{
    ui->setupUi(this);
}

Fibonachi::~Fibonachi()
{
    delete ui;
}


