#ifndef FILE_H
#define FILE_H

#include <QMainWindow>

namespace Ui {
class File;
}

class File : public QMainWindow
{
    Q_OBJECT

public:
    explicit File(QWidget *parent = 0);
    ~File();

private slots:
    void on_actionOpen_triggered();


    void on_Exit_clicked();

    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::File *ui;
};

#endif // FILE_H
