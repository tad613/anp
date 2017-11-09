#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:
    void on_pb1_clicked();

    void on_pb2_clicked();

    void on_pb3_clicked();

    void on_pb4_clicked();

    void on_pb5_clicked();

    void on_pb6_clicked();

    void on_pb7_clicked();

    void on_pb8_clicked();

    void on_pb9_clicked();

    void on_pb0_clicked();



    void on_pbAllDelete_clicked();

    void on_pbPlus_clicked();

    void on_pbMinus_clicked();

    void on_pbUmn_clicked();

    void on_pbDelenie_clicked();

    void on_pbRavno_clicked();

    void on_pbFactorial_clicked();

    void on_pbSQR_clicked();

    void on_pbStepen_clicked();

    void on_pbSqrt_clicked();

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
