#include "tourist.h"
#include "ui_tourist.h"
#include <QMessageBox>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <QTextCodec>
#include <QTimer>
#include <QDateTime>
using namespace std;

Tourist::Tourist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tourist)
{
    ui->setupUi(this);
    this->setFixedSize( this->width (),this->height ());    //固定窗口大小

    QTimer *timer = new QTimer(this);
    QObject::connect( timer,SIGNAL(timeout()),this,SLOT( timerUpdate() ) );              //在构造函数中关联计时器和相应的槽函数
    timer->start(1000);                 //每一秒刷新一次

    //把对应的编辑框与槽函数建立响应机制
    QObject::connect(ui->lineEdit,SIGNAL(returnPressed()),ui->pushButton,SLOT(Tourist::on_pushButton_clicked()));
    QObject::connect(ui->lineEdit_2,SIGNAL(returnPressed()),ui->pushButton_2,SLOT(Tourist::on_pushButton_clicked()));
    QObject::connect(ui->lineEdit_3,SIGNAL(returnPressed()),ui->pushButton_3,SLOT(Tourist::on_pushButton_clicked()));

}

Tourist::~Tourist()
{
    delete ui;
}

void Tourist::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label_2->setText(str);
}

void Tourist::on_pushButton_clicked()           //编号查询
{
    string NumberOfTrain;

    if(ui->lineEdit->text().toStdString() == "")
    {
        QMessageBox::information(this,"提示:查询失败","未在对应位置输入查询的数据");
    }

    else if(ui->lineEdit_2->text().toStdString() != "" || ui->lineEdit_2->text().toStdString() != "")
    {
        QMessageBox::information(this,"提示:查询失败","未对应的编辑框内有内容");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
    }
    else
    {
        ifstream read("Train.txt");
        string s;
        int u = 0;

        while(getline(read, s))			//逐行读到s里 ，逐行判断与输出
        {
            istringstream is(s);  		//istringstream::istringstream(string str);它的作用是从string对象str中读取字符
            string str;
            while(is>>str)  			//is遇到空格即结束一个的录入
            {
                if(str == ui->lineEdit->text().toStdString())
                {
                    u++;                //记录是否成功查询到该动车
                }
            }
        }

        if(u != 0)                      //有
        {
            QMessageBox::information(this,"提示:","有该车次");

            NumberOfTrain = ui->lineEdit->text().toStdString();       //QString中文转string
            QTextCodec *code = QTextCodec::codecForName("gb18030");
            NumberOfTrain = code->fromUnicode(ui->lineEdit->text()).data();

            ofstream write;
            write.open("NumberOfTrain.txt",ios::trunc);
            write<<NumberOfTrain;
            write.close();

            traininformationDialog = new TrainInformation(this);
            traininformationDialog->setWindowTitle("查询到的动车基础信息");
            traininformationDialog->show();
        }
        else                            //无
        {
            QMessageBox::information(this,"提示:查询失败","对不起没有该车次,请重新输入");
            ui->lineEdit->clear();
        }
    }
}

void Tourist::on_pushButton_2_clicked()         //起始站查询
{
    string NumberOfTrain;

    if(ui->lineEdit_2->text().toStdString() == "")
    {
        QMessageBox::information(this,"提示:查询失败","未在对应位置输入查询的数据");
    }

    else if(ui->lineEdit->text().toStdString() != "" || ui->lineEdit_3->text().toStdString() != "")
    {
        QMessageBox::information(this,"提示:查询失败","未对应的编辑框内有内容");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
    }
    else
    {
        ifstream read("Train.txt");
        string s;
        int u = 0;

        while(getline(read, s))			//逐行读到s里 ，逐行判断与输出
        {
            istringstream is(s);  		//istringstream::istringstream(string str);它的作用是从string对象str中读取字符
            string str;
            int w = 3; 							//定义一个w来控制读到的位置
            while(is>>str && (w--))  			//is遇到空格即结束一个的录入 //读数据只读到 起始站 过
            {
                string ss = ui->lineEdit_2->text().toStdString();       //避免QString中文部分转string错误导致无法对比
                QTextCodec *code = QTextCodec::codecForName("gb18030");
                ss = code->fromUnicode(ui->lineEdit_2->text()).data();

                if(str == ss)
                {
                    int d = 1;
                    istringstream __is(s);
                    while(__is>>str && (d--))			//有意给NumberOfTrian赋值,使其对应start的起始站
                    {
                        NumberOfTrain = str;
                    }
                    u++;
                }
            }
        }

        if(u != 0)                      //有
        {
            QMessageBox::information(this,"提示:","有该车次");

            ofstream write;                                 //记录下动车编号
            write.open("NumberOfTrain.txt",ios::trunc);     //打开时清空
            write<<NumberOfTrain;
            write.close();

            traininformationDialog = new TrainInformation(this);
            traininformationDialog->setWindowTitle("查询到的动车基础信息");
            traininformationDialog->show();
        }
        else                            //无
        {
            QMessageBox::information(this,"提示:查询失败","对不起没有该车次,请重新输入");
            ui->lineEdit_2->clear();
        }
    }
}

void Tourist::on_pushButton_3_clicked()             //终点站查询
{
    string NumberOfTrain;

    if(ui->lineEdit_3->text().toStdString() == "")
    {
        QMessageBox::information(this,"提示:查询失败","未在对应位置输入查询的数据");
    }

    else if(ui->lineEdit_2->text().toStdString() != "" || ui->lineEdit->text().toStdString() != "")
    {
        QMessageBox::information(this,"提示:查询失败","未对应的编辑框内有内容");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
    }
    else
    {
        ifstream read("Train.txt");
        string s;
        int u = 0;

        while(getline(read, s))			//逐行读到s里 ，逐行判断与输出
        {
            istringstream is(s);  		//istringstream::istringstream(string str);它的作用是从string对象str中读取字符
            string str;
            int w = 4; 							//定义一个w来控制读到的位置
            while(is>>str && (w--))  			//is遇到空格即结束一个的录入 //读数据只读到 起始站 过
            {
                string ss = ui->lineEdit_3->text().toStdString();       //避免QString中文部分转string错误导致无法对比
                QTextCodec *code = QTextCodec::codecForName("gb18030");
                ss = code->fromUnicode(ui->lineEdit_3->text()).data();

                if(str == ss && (w == 0))		//通过使 w==0 来跳过 如果 文件前面起始站与 查询的终点站相同的情况,从而避免错误
                {
                    int d = 1;
                    istringstream __is(s);
                    while(__is>>str && (d--))			//有意给number赋值,使其对应start的起始站
                    {
                        NumberOfTrain = str;
                    }
                    u++;
                }

            }
        }

        if(u != 0)                      //有
        {
            QMessageBox::information(this,"提示:","有该车次");

            ofstream write;
            write.open("NumberOfTrain.txt",ios::trunc);     //打开时清空
            write<<NumberOfTrain;
            write.close();

            traininformationDialog = new TrainInformation(this);
            traininformationDialog->setWindowTitle("查询到的动车基础信息");
            traininformationDialog->show();
        }
        else                            //无
        {
            QMessageBox::information(this,"提示:查询失败","对不起没有该车次,请重新输入");
            ui->lineEdit_3->clear();
        }
    }
}
