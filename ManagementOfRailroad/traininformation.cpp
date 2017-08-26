#include "traininformation.h"
#include "ui_traininformation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <QTimer>
#include <QDateTime>
using namespace std;

TrainInformation::TrainInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainInformation)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    QObject::connect( timer,SIGNAL(timeout()),this,SLOT( timerUpdate() ) );              //在构造函数中关联计时器和相应的槽函数
    timer->start(1000);                 //每一秒刷新一次

    ifstream read("NumberOfTrain.txt");
    string NumberOfTrain;
    while(getline(read,NumberOfTrain))
    {
        //有意留空
    }

    ifstream Read("Train.txt");
    string s;

    while(getline(Read,s))              //读取并打印动车信息
    {
        istringstream is(s);
        string str;
        int i = 1;
        while(is>>str && (i--))
        {
            if(str == NumberOfTrain && (i == 0))
            {
                istringstream is1(s);
                string str1;
                int o = 5;                  //控制只读到第四个字符
                while(is1>>str1 && o--)
                {
                    if(o == 4)              //判断打印到的位置防止打印出错,防止打印的循环
                    {
                        ui->lineEdit->setText(QString::fromLocal8Bit(str1.c_str()));
                        while(is1>>str1 && o--)
                        {
                            if(o == 3)
                            {
                                ui->lineEdit_2->setText(QString::fromLocal8Bit(str1.c_str()));
                                while(is1>>str1 && o--)
                                {
                                    if(o == 2)              //判断打印到的位置防止打印出错
                                    {
                                        ui->lineEdit_3->setText(QString::fromLocal8Bit(str1.c_str()));
                                        while(is1>>str1 && o--)
                                        {
                                            if(o == 1)
                                            {
                                                ui->lineEdit_4->setText(QString::fromLocal8Bit(str1.c_str()));
                                                break;
                                            }

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

TrainInformation::~TrainInformation()
{
    delete ui;
}

void TrainInformation::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label_5->setText(str);
}

void TrainInformation::on_satisfyButton_clicked()
{
    buyticketDialog = new BuyTicketDialog(this);            //产生购票窗口
    buyticketDialog->setWindowTitle("乘客信息填写");
    this->close();
    buyticketDialog->show();
}

void TrainInformation::on_unsatisfyButton_clicked()
{
    this->close();
}
