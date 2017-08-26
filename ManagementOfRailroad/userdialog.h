#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <string>
#include <iostream>
using namespace std;

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog(QWidget *parent = 0);
    ~UserDialog();


private slots:
    void on_tabWidget_currentChanged(int index);

    void on_DeletePassengerButton_clicked();

    void timerUpdate();         //定时刷新时间的信号实现函数

private:
    Ui::UserDialog *ui;
};

#endif // USERDIALOG_H
