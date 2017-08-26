#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QMainWindow>
#include "admindialog.h"
#include "userdialog.h"
#include "tourist.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

signals:

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void timerUpdate();         //定时刷新时间的信号实现函数

private:
    Ui::LoginDialog *ui;
    AdminDialog *adminDialog;       //声明一个AdminDialog窗口,后面的对象一定最好不要和类名相同
    UserDialog *userDialog;
    Tourist *touristDialog;

};

#endif // LOGINDIALOG_H
