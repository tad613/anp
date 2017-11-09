#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <QMainWindow>

namespace Ui {
class Fibonachi;
}

class Fibonachi : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fibonachi(QWidget *parent = 0);
    ~Fibonachi();

private slots:
    void on_sp1_valueChanged(int arg1);

private:
    Ui::Fibonachi *ui;
};

#endif // FIBONACHI_H
