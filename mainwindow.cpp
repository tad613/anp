#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QDataStream>
#include "packet.h"
#include "file.h"

Calculator *f;
File *k;

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
    k->show();
}








