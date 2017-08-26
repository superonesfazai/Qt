#ifndef TOURIST_H
#define TOURIST_H

#include <QDialog>
#include "traininformation.h"

namespace Ui {
class Tourist;
}

class Tourist : public QDialog
{
    Q_OBJECT

public:
    explicit Tourist(QWidget *parent = 0);
    ~Tourist();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void timerUpdate();                 //定时刷新时间

private:
    Ui::Tourist *ui;
    TrainInformation *traininformationDialog;
};

#endif // TOURIST_H
