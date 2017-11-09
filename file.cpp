#include "file.h"
#include "ui_file.h"
#include"mainwindow.h"

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
