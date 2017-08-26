#ifndef TRAININFORMATION_H
#define TRAININFORMATION_H

#include <QDialog>
#include "buyticketdialog.h"

namespace Ui {
class TrainInformation;
}

class TrainInformation : public QDialog
{
    Q_OBJECT

public:
    explicit TrainInformation(QWidget *parent = 0);
    ~TrainInformation();

private slots:
    void on_satisfyButton_clicked();

    void on_unsatisfyButton_clicked();

    void timerUpdate();         //定时刷新时间的信号实现函数

private:
    Ui::TrainInformation *ui;
    BuyTicketDialog *buyticketDialog;
};

#endif // TRAININFORMATION_H
