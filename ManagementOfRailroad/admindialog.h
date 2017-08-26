#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>
#include <QString>
#include <string>
#include <iostream>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
using namespace std;

namespace Ui {
class AdminDialog;
}

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = 0);          //构造函数
    ~AdminDialog();                                     //析构函数
    void ReadFromFile();                                //文件读取

    void EditTime();       //修改列车的信息
    void EditStart();
    void EditFinish();
    void EditHard_seat();
    void EditHard_berth();
    void EditSoft_berth();

private slots:
    void on_tabWidget_currentChanged(int index);         //响应tabWidget在不同子界面的位置,这里主要对响应浏览所有动车信息

    void on_addButton_clicked();

    void on_DeleteButton_clicked();

    void on_EditButton_clicked();

    void timerUpdate();         //定时刷新时间的信号实现函数

private:
    Ui::AdminDialog *ui;
};



#endif // ADMINDIALOG_H
