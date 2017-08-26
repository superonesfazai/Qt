#include "userdialog.h"
#include "ui_userdialog.h"
#include "logindialog.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>         //c_str()的头文件
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
using namespace std;


UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    this->setFixedSize( this->width (),this->height ());    //固定窗口大小

    QTimer *timer = new QTimer(this);
    QObject::connect( timer,SIGNAL(timeout()),this,SLOT( timerUpdate() ) );              //在构造函数中关联计时器和相应的槽函数
    timer->start(1000);                 //每一秒刷新一次

}

UserDialog::~UserDialog()
{
    delete ui;
}

void UserDialog::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label_12->setText(str);
}

void UserDialog::on_tabWidget_currentChanged(int index)
{
    string NumberOfTrain;

    ifstream read("Username.txt");
    string username;
    while(getline(read,username))
    {

    }
    read.close();

    QString _s = QString::fromLocal8Bit(username.c_str());      //避免string中的中文转换为QString乱码
    ui->lineEdit->setText(_s);

    read.open("Passenger.txt");
    string s;
    while(getline(read, s))				//逐行读取
    {
        istringstream is(s);
        string str;
        int k = 1;
        while(is>>str && (k--))		//检索第一个字符串是否符合,不符合则跳过继续检索下一行数据
        {
            if(ui->lineEdit->text().toStdString() == str && k == 0)
            {
                istringstream _is(s);
                string _str;
                int w = 8;
                while(_is>>_str && (w--))           //在对应编辑框设置对应内容
                {
                    if(w <= 6)		//读到第三个字符串开始输出
                    {
                        while(_is>>_str && (w--))
                        {
                            QString _str1 = QString::fromLocal8Bit(_str.c_str());      //避免string中的中文转换为QString乱码
                            ui->lineEdit_2->setText(_str1);         //真实姓名
                            while(_is>>_str && (w--))
                            {
                                QString _str1 = QString::fromLocal8Bit(_str.c_str());
                                ui->lineEdit_3->setText(_str1);     //性别
                                while(_is>>_str && (w--))
                                {
                                    QString _str1 = QString::fromLocal8Bit(_str.c_str());
                                    ui->lineEdit_4->setText(_str1);     //ID
                                    while(_is>>_str && (w--))
                                    {
                                        QString _str1 = QString::fromLocal8Bit(_str.c_str());
                                        ui->lineEdit_5->setText(_str1);
                                        while(_is>>_str && (w--))
                                        {
                                            NumberOfTrain = _str;       //记下所乘坐的动车编号
                                            QString _str1 = QString::fromLocal8Bit(_str.c_str());
                                            ui->lineEdit_6->setText(_str1);
                                            while(_is>>_str && (w--))
                                            {
                                                QString _str1 = QString::fromLocal8Bit(_str.c_str());
                                                ui->lineEdit_8->setText(_str1);
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        string _s;
                        ifstream ReadFromTrain;
                        ReadFromTrain.open("Train.txt");

                        while(getline(ReadFromTrain, _s))		//在对应编辑框设置对应内容
                        {
                            istringstream ist(_s);
                            int e = 1;
                            string str1;
                            while(ist>>str1 && (e--))
                            {
                                if(NumberOfTrain == str1 && e == 0)
                                {
                                    istringstream ist1(_s);
                                    string str2;
                                    int r = 8;                  //设置r=8来读取动车信息的第n个字符串
                                    while(ist1>>str2 && (r--))
                                    {
                                        if(r<7 && r >= 4)       //输出的范围
                                        {
                                            QString str3 = QString::fromLocal8Bit(str2.c_str());
                                            ui->lineEdit_7->setText(str3);      //发车时间
                                            while(ist1>>str2 && (r--))
                                            {
                                                QString str3 = QString::fromLocal8Bit(str2.c_str());
                                                ui->lineEdit_9->setText(str3);  //起始站
                                                while(ist1>>str2 && (r--))
                                                {
                                                    if(r == 4)
                                                    {
                                                        QString str3 = QString::fromLocal8Bit(str2.c_str());
                                                        ui->lineEdit_10->setText(str3);     //终点站
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            _s = "";					//同上清除不匹配的动车的信息,使s为空字符串
                        }
                        break;							//跳出打印乘客信息
                    }
                }
            }
            else
            {
                s = "";		//假如读到的数据不符合,则清空前面储存的数据
            }

        }
    }
}

void UserDialog::on_DeletePassengerButton_clicked()
{
    ifstream read_("Username.txt");
    string username;
    while(getline(read_,username))       //读取对应的用户名
    {
        //有意留空
    }
    read_.close();

    ifstream read("Passenger.txt");
    vector<string> vec;		//默认构造函数vec为空
    string i;

    /*读取文件内容到 缓存中*/
    while(read>>i)
    {
        vec.push_back(i);		//在vector类中作用为在vector尾部加入一个数据,string 中也有这个函数
    }
    read.close();

    vector<string>::iterator it;		//iterator是C++标准库中的迭代器,可以实现对内存中数据的遍历

    for(it=vec.begin(); it<vec.end(); it++)
    {
        if(username == *it)
        {
            vector<string>::iterator it1;
            it1 = (it+8);			//it后面的第八个数据的位置,在进行it的位置变换时,切记it前面不要加*
            vec.erase(it, it1);      //删除从first到last之间的元素，包含起点，不包含终点,erase(it)为删除某个数据
        }
    }

    //将删除后的剩余内容写到文件中
    ofstream write("Passenger.txt");
    int w = 7;
    for(it=vec.begin(); it<vec.end(); it++,w--)
    {
        write<<*it<<" ";
        if(w == 0)
        {
            write<<"\n";
            w = 8;
        }
    }
    QMessageBox::information(this,"提示:","退票成功!");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();

    ofstream write1;             //清空Username.txt中保存的数据
    write1.open("Username.txt",ios::trunc);
    write1.close();
}
