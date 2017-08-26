#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <vector>
#include <fstream>
#include <iostream>
#include <QTextCodec>
#include <QTimer>
#include <QDateTime>
using namespace std;

LoginDialog::LoginDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    //this->setWindowFlags(Qt::FramelessWindowHint);          //设置窗口无边框
    this->setFixedSize( this->width (),this->height ());    //固定登录窗口大小

    // 设置编辑框无边框，背景为白色
    ui->lineEdit->setStyleSheet("QLineEdit{background-color: rgba(255,255,255,255); border-width:0;border-style:outset}");
    ui->lineEdit_2->setStyleSheet("QLineEdit{background-color: rgba(255,255,255,255); border-width:0;border-style:outset}");

    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);

    //设置pushButton的颜色
    ui->pushButton->setStyleSheet("background:#66B3FF");
    ui->pushButton_2->setStyleSheet("background:#66B3FF");
    QObject::connect(ui->lineEdit_2,SIGNAL(returnPressed()),this,SLOT(on_pushButton_clicked()));    //把lineEdit_2回车后与登录建立联系

    QTimer *timer = new QTimer(this);
    QObject::connect( timer,SIGNAL(timeout()),this,SLOT( timerUpdate() ) );              //在构造函数中关联计时器和相应的槽函数
    timer->start(1000);                 //每一秒刷新一次

    ui->lineEdit->setPlaceholderText(QString::fromStdString("请输入用户名"));      //在用户名输入框显示"请输入用户名"
    ui->lineEdit_2->setPlaceholderText(QString::fromStdString("请输入密码"));        //在密码输入框显示"请输入密码"

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);           //密码不明文显示

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label_4->setText(str);
}

void LoginDialog::on_pushButton_clicked()           //登录按钮被按下
{
    if(ui->checkBox->isChecked())       //以管理员身份登录
    {
        if(ui->lineEdit->text() == "admin" && ui->lineEdit_2->text() == "admin")
        {
            QMessageBox::information(this,"登陆成功!","以管理员身份登录...");

            this->close();      //关闭原先的窗口
            adminDialog = new AdminDialog(this);        //新建一个adminDialog窗口

            adminDialog->setWindowTitle("Admin");       //修改标题
            adminDialog->show();
        }
        else
        {
            QMessageBox::information(this,"登录失败!","用户名或密码错误,请重新输入");
            ui->lineEdit->clear();      //清空原先输入
            ui->lineEdit_2->clear();
        }
    }
    else if(ui->checkBox_2->isChecked())        //以用户身份登录
    {
        ifstream read;
        read.open("Passenger.txt");
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
            if(ui->lineEdit->text().toStdString() == vec[i] && ui->lineEdit_2->text().toStdString() == vec[i+1])
            {   //toStdString()为QString转换为string的函数 , QString::fromStdString()是String转换为QString的函数
                m++;
                QMessageBox::information(this,"登录成功!","以用户身份登录...");

                /*切记:这一部分对QString中文部分转换为string的处理*/
                string username = ui->lineEdit->text().toStdString();
                QTextCodec *code = QTextCodec::codecForName("gb18030");
                username = code->fromUnicode(ui->lineEdit->text()).data();

                ofstream WriteUsername;             //储存用户名
                WriteUsername.open("Username.txt", ios::trunc);     //ios::trunc打开并清空
                WriteUsername<<username;
                WriteUsername.close();

                UserDialog *userDialog = new UserDialog(this);

                userDialog->setWindowTitle("User");

                this->close();      //关闭登录窗口
                userDialog->show();
            }
        }
        if(m == 0)
        {
            QMessageBox::information(this,"登录失败!","用户名或密码错误,请重新输入");
            ui->lineEdit->clear();      //清空原先输入
            ui->lineEdit_2->clear();
        }

    }
    else if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked())
    {
        QMessageBox::warning(this,"警告:","对不起此程序没有双重身份登陆...");
        ui->lineEdit->clear();      //清空原先输入
        ui->lineEdit_2->clear();
    }
    else
    {
        QMessageBox::warning(this,"警告!","你未选择登录身份");
        ui->lineEdit->clear();      //清空原先输入
        ui->lineEdit_2->clear();
    }
}

void LoginDialog::on_pushButton_2_clicked()             //游客查询界面的产生
{
    if(ui->lineEdit->text().toStdString() != "" || ui->lineEdit_2->text().toStdString() != "")
    {
        QMessageBox::information(this,"提示:登陆失败","以此身份登录请勿在上方编辑框写入内容");
        ui->lineEdit->clear();              //清空
        ui->lineEdit_2->clear();
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(false);
    }
    else if(ui->checkBox->isChecked() || ui->checkBox_2->isChecked())
    {
        QMessageBox::information(this,"提示:登陆失败","以此身份登录请勿勾选登录身份");
        ui->lineEdit->clear();              //清空
        ui->lineEdit_2->clear();
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(false);
    }
    else
    {
        touristDialog = new Tourist(this);

        touristDialog->setWindowTitle("游客查询");
        this->close();                  //关闭登录窗口
        touristDialog->show();
    }
}
