#include "admindialog.h"
#include "ui_admindialog.h"
#include "train.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>             //atoi的头文件
#include <QTextCodec>
#include <QTimer>
#include <QDateTime>
using namespace std;


AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
    this->setFixedSize( this->width (),this->height ());    //固定窗口大小

    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);

    QTimer *timer = new QTimer(this);
    QObject::connect( timer,SIGNAL(timeout()),this,SLOT( timerUpdate() ) );              //在构造函数中关联计时器和相应的槽函数
    timer->start(1000);                 //每一秒刷新一次

    QObject::connect(ui->lineEdit_8, SIGNAL(returnPressed()), this, SLOT(on_DeleteButton_clicked()));   //把lineEdit_8回车后与确认删除建立联系
    QObject::connect(ui->lineEdit_7, SIGNAL(returnPressed()), this, SLOT(on_addButton_clicked()));
}

AdminDialog::~AdminDialog()
{
    delete ui;
}

void AdminDialog::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label_13->setText(str);
}

void AdminDialog::ReadFromFile()
{
    QFile file("Train.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Can not open!";
    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
}


void AdminDialog::on_tabWidget_currentChanged(int index)
{
    AdminDialog::ReadFromFile();
}

void AdminDialog::on_addButton_clicked()        //添加动车信息
{
    Train T;
    int l = 0;      //记录是否非空
    if(ui->lineEdit->text().toStdString() == "" || ui->lineEdit_2->text().toStdString() == "" ||
            ui->lineEdit_3->text().toStdString() == "" || ui->lineEdit_4->text().toStdString() == "" ||
            ui->lineEdit_5->text().toStdString() == "" || ui->lineEdit_6->text().toStdString() == "" ||
            ui->lineEdit_7->text().toStdString() == "")       //判断是否完整填写动车信息
    {
        QMessageBox::information(this,"添加失败!","还有未填信息,请完整填写");
    }

    else
    {
        l++;
    }

    ifstream read;              //判断是否重复输入动车信息
    read.open("Train.txt");
    string s;

    vector<string> vec;
    while(read>>s)
    {
        vec.push_back(s);
    }
    read.close();

    int m = 0;
    for(size_t i = 0;i < vec.size(); i++)
    {
        if(ui->lineEdit->text().toStdString() == vec[i])    //通过列车编号判断是否重复输入动车信息
        {
            m++;
        }
    }
    if(m != 0)
    {
        QMessageBox::information(this,"提示:","对不起该动车信息已在之前被录入,请勿重复操作");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
    }

    if(l != 0)
    {
        //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));       //避免中文QString乱码
        T.SetTrain(ui->lineEdit->text().toStdString(), ui->lineEdit_2->text().toStdString(),
                   ui->lineEdit_3->text().toStdString(),ui->lineEdit_4->text().toStdString(),
                   ui->lineEdit_5->text().toInt(), ui->lineEdit_6->text().toInt(),
                   ui->lineEdit_7->text().toInt());        //toInt()为QString转换为int类型

        T.WriteIntoFile();
        QMessageBox::information(this,"添加成功!","");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
    }
}




void AdminDialog::on_DeleteButton_clicked()
{
    if(ui->lineEdit_8->text().toStdString() == "")
    {
        QMessageBox::information(this,"提示:","未输入动车编号,请输入");
    }
    else
    {
        ifstream read("Train.txt");
        vector<string> vec;		//默认构造函数vec为空
        string s;

        /*读取文件内容到 缓存中*/
        while(read>>s)
        {
            vec.push_back(s);		//在vector类中作用为在vector尾部加入一个数据,string 中也有这个函数
        }
        read.close();

        int u = 0;      //判断是否输入编号不匹配
        vector<string>::iterator it;
        for(it = vec.begin(); it < vec.end(); it++)
        {
            if(ui->lineEdit_8->text().toStdString() == *it)
            {
                u++;
                vector<string>::iterator it1;
                it1 = (it+8);
                vec.erase(it, it1);         //切记erase(string * ,string * );用erase(vec[i],vec[i+8]),报错
            }
        }
        if(u != 0)
        {
            ofstream write("Train.txt");
            int w = 7;                  //控制写入格式
            for(size_t k = 0; k < vec.size(); k++,w--)
            {
                write<<vec[k]<<" ";
                if(w == 0)
                {
                    write<<"\n";
                    w = 8;
                }
            }

            QMessageBox::information(this,"提示:","删除成功!");
            ui->lineEdit_8->clear();
        }

        else
        {
            QMessageBox::warning(this,"警告:","所填写的动车编号不存在,请重新输入");
            ui->lineEdit_8->clear();
        }

    }
}

void AdminDialog::on_EditButton_clicked()
{
    if(ui->lineEdit_15->text().toStdString() == "")     //判断是否动车编号已填写
    {
        QMessageBox::information(this,"提示:","操作失败,原因动车编号未填写");
    }

    //判断是否要修改的地方都未勾选
    else if((!ui->checkBox->isChecked()) &&(!ui->checkBox_2->isChecked()) &&
             (!ui->checkBox_3->isChecked()) && (!ui->checkBox_4->isChecked()) &&
             (!ui->checkBox_5->isChecked()) && (!ui->checkBox_6->isChecked()))
    {
        QMessageBox::information(this,"提示:","操作失败,原因未选择要修改的地方");
    }

    else if(ui->lineEdit_9->text().toStdString() == "" && ui->lineEdit_10->text().toStdString() == "" &&
            ui->lineEdit_11->text().toStdString() == "" && ui->lineEdit_12->text().toStdString() == "" &&
            ui->lineEdit_13->text().toStdString() == "" && ui->lineEdit_14->text().toStdString()== "")
    {
        QMessageBox::information(this,"提示:","操作失败,原因未填写修改后的内容");
    }
    else
    {
        ifstream read("Train.txt");
        vector<string> vec;		//默认构造函数vec为空
        string s;

        /*读取文件内容到 缓存中*/
        while(read>>s)
        {
            vec.push_back(s);		//在vector类中作用为在vector尾部加入一个数据,string 中也有这个函数
        }
        read.close();

        int u = 0;      //判断是否输入动车编号不匹配
        vector<string>::iterator it;
        for(it = vec.begin(); it < vec.end(); it++)
        {
            if(ui->lineEdit_15->text().toStdString() == *it)
            {
                u++;
            }
        }
        if(u != 0)
        {
            int p1 = 0,p2 = 0,p3 = 0,p4 = 0,p5 = 0,p6 = 0;              //判断是否checkBox与lineEdit的对应关系出错 eg: 只勾选了checkBox和lineEdit_2的情况

            if(ui->checkBox->isChecked() && ui->lineEdit_9->text().toStdString() != "")
            {
                AdminDialog::EditTime();
                ui->lineEdit_9->clear();
                ui->checkBox->setChecked(false);        //使其不勾选
                //原先打算用信号与槽来搞,但是有部分功能不好实现
                //QObject::connect( ui->checkBox, SIGNAL(stateChanged(Checked)), this, SLOT( AdminDialog::EditTime() ) ) ;     //建立各个信号也对应函数的联系
                p1++;
            }

            if(ui->checkBox_2->isChecked() && ui->lineEdit_10->text().toStdString() != "")
            {
                AdminDialog::EditStart();
                ui->lineEdit_10->clear();
                ui->checkBox_2->setChecked(false);
                p2++;
            }

            if(ui->checkBox_3->isChecked() && ui->lineEdit_11->text().toStdString() != "")
            {
                AdminDialog::EditFinish();
                ui->lineEdit_11->clear();
                ui->checkBox_3->setChecked(false);
                p3++;
            }

            if(ui->checkBox_4->isChecked() && ui->lineEdit_12->text().toStdString() != "") //改硬座数量
            {
                AdminDialog::EditHard_seat();
                ui->lineEdit_12->clear();
                ui->checkBox_4->setChecked(false);
                p4++;
            }

            if(ui->checkBox_5->isChecked() && ui->lineEdit_13->text().toStdString() != "") //改硬卧数量
            {
                AdminDialog::EditHard_berth();
                ui->lineEdit_13->clear();
                ui->checkBox_5->setChecked(false);
                p5++;
            }

            if(ui->checkBox_6->isChecked() && ui->lineEdit_14->text().toStdString() != "") //改软卧数量
            {
                AdminDialog::EditHard_berth();
                ui->lineEdit_14->clear();
                ui->checkBox_6->setChecked(false);
                p6++;
            }

            if(p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0)      //判断是否有 eg: 只勾选了checkBox和lineEdit_2的情况
            {
                QMessageBox::warning(this,"警告:","对应关系不正确,请修改");
                goto loop;      //跳过下方修改成功的提示
            }

            QMessageBox::information(this,"提示:","已勾选和填写的地方已修改成功!");
            ui->lineEdit_15->clear();
            loop:1;
        }
        else
        {
            QMessageBox::warning(this,"警告:","没有找到对应编号动车,请重新输入");
            ui->lineEdit_15->clear();
        }
    }
}

//总结可以用命名空间解决在case中某些函数运行不了的情况,企鹅注意运用一些功能函数是的定义位置

void AdminDialog::EditTime()
{
    ifstream read("Train.txt");
    vector<string> vec;
    string str;

    while(read>>str)
    {
        vec.push_back(str);
    }
    read.close();

    for(size_t i = 0;i < vec.size(); i++)
    {
        if(ui->lineEdit_15->text().toStdString() == vec[i])
        {
             /*切记:这一部分对QString中文部分转换为string的处理*/
            string s = ui->lineEdit_9->text().toStdString();
            QTextCodec *code = QTextCodec::codecForName("gb18030");
            s = code->fromUnicode(ui->lineEdit_9->text()).data();

            vec[i+1] = s;
        }
    }

    //将修改后的剩余内容写到文件中
    ofstream write("Train.txt");
    int w = 7;
    for(size_t k = 0; k<vec.size(); k++,w--)
    {
        write<<vec[k]<<" ";
        if(w == 0)
        {
            write<<"\n";
            w = 8;
        }
    }
}

void AdminDialog::EditStart()
{
    ifstream read("Train.txt");
    vector<string> vec;
    string str;
    while(read>>str)
    {
        vec.push_back(str);
    }
    read.close();

    for(size_t i = 0;i < vec.size(); i++)
    {
        if(ui->lineEdit_15->text().toStdString() == vec[i])
        {
            /*切记:这一部分对QString中文部分转换为string的处理*/
            string s = ui->lineEdit_10->text().toStdString();
            QTextCodec *code = QTextCodec::codecForName("gb18030");
            s = code->fromUnicode(ui->lineEdit_10->text()).data();

            vec[i+2] = s;
        }
    }

    //将修改后的剩余内容写到文件中
    vector<string>::iterator it;
    ofstream write("Train.txt");
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
}

void AdminDialog::EditFinish()
{
    ifstream read("Train.txt");
    vector<string> vec;
    string str;
    while(read>>str)
    {
        vec.push_back(str);
    }
    read.close();

    for(size_t i = 0;i < vec.size(); i++)
    {
        if(ui->lineEdit_15->text().toStdString() == vec[i])
        {
             /*切记:这一部分对QString中文部分转换为string的处理*/
            string s = ui->lineEdit_11->text().toStdString();
            QTextCodec *code = QTextCodec::codecForName("gb18030");
            s = code->fromUnicode(ui->lineEdit_11->text()).data();
            vec[i+3] = s;
        }
    }

    //将修改后的剩余内容写到文件中
    vector<string>::iterator it;
    ofstream write("Train.txt");
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
}

void AdminDialog::EditHard_seat()
{
    ifstream read("Train.txt");
    vector<string> vec;
    string str;
    while(read>>str)
    {
        vec.push_back(str);
    }
    read.close();

    for(size_t i = 0;i < vec.size(); i++)
    {
        if(ui->lineEdit_15->text().toStdString() == vec[i])
        {
            int s = ui->lineEdit_12->text().toInt();

            stringstream s1;
            s1<<s;

            string s2 = s1.str();
            vec[i+4] = s2;

            string xx = vec.at(i+5);			//读取其他位置的数量
            string yy = vec.at(i+6);

            int xx1 = atoi(xx.c_str());
            int yy1 = atoi(yy.c_str());

            int all;
            all = s+xx1+yy1;

            stringstream s3;
            s3<<all;

            string s4 = s3.str();
            vec[i+7] = s4;

        }
    }

    //将修改后的剩余内容写到文件中
    vector<string>::iterator it;
    ofstream write("Train.txt");
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
}

void AdminDialog::EditHard_berth()
{
    ifstream read("Train.txt");
    vector<string> vec;
    string str;
    while(read>>str)
    {
        vec.push_back(str);
    }
    read.close();

    for(size_t i = 0;i < vec.size(); i++)
    {
        if(ui->lineEdit_15->text().toStdString() == vec[i])
        {
            int s = ui->lineEdit_13->text().toInt();

            stringstream s1;
            s1<<s;

            string s2 = s1.str();
            vec[i+5] = s2;

            string xx = vec.at(i+4);			//读取其他位置的数量
            string yy = vec.at(i+6);

            int xx1 = atoi(xx.c_str());
            int yy1 = atoi(yy.c_str());

            int all;
            all = s+xx1+yy1;

            stringstream s3;
            s3<<all;

            string s4 = s3.str();
            vec[i+7] = s4;

        }
    }

    //将修改后的剩余内容写到文件中
    vector<string>::iterator it;
    ofstream write("Train.txt");
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
}

void AdminDialog::EditSoft_berth()
{
    ifstream read("Train.txt");
    vector<string> vec;
    string str;
    while(read>>str)
    {
        vec.push_back(str);
    }
    read.close();

    for(size_t i = 0;i < vec.size(); i++)
    {
        if(ui->lineEdit_15->text().toStdString() == vec[i])
        {
            int s = ui->lineEdit_13->text().toInt();

            stringstream s1;
            s1<<s;

            string s2 = s1.str();
            vec[i+6] = s2;

            string xx = vec.at(i+4);			//读取其他位置的数量
            string yy = vec.at(i+5);

            int xx1 = atoi(xx.c_str());
            int yy1 = atoi(yy.c_str());

            int all;
            all = s+xx1+yy1;

            stringstream s3;
            s3<<all;

            string s4 = s3.str();
            vec[i+7] = s4;

        }
    }

    //将修改后的剩余内容写到文件中
    vector<string>::iterator it;			//运用是才在前面命名
    ofstream write("Train.txt");
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
}

