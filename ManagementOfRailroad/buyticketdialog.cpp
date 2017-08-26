#include "buyticketdialog.h"
#include "ui_buyticketdialog.h"
#include "passenger.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <QTextCodec>
#include <QMessageBox>

BuyTicketDialog::BuyTicketDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuyTicketDialog)
{
    ui->setupUi(this);
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);

}

BuyTicketDialog::~BuyTicketDialog()
{
    delete ui;
}

void BuyTicketDialog::on_pushButton_clicked()
{
    Passenger P;
    loop:1;
    if(ui->lineEdit->text().toStdString() == "" || ui->lineEdit_2->text().toStdString() == "" ||
            ui->lineEdit_3->text().toStdString() == "" || ui->lineEdit_4->text().toStdString() == "" ||
            ui->lineEdit_5->text().toStdString() == "")
    {
        QMessageBox::information(this,"提示:","有未填写的内容,请补充完整");
    }

    else if((!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked()) || (!ui->radioButton->isChecked() &&
                !ui->radioButton_2->isChecked() && !ui->radioButton_3->isChecked()) )
    {
        QMessageBox::information(this,"提示:","有未勾选的内容,请补充完整");
    }

    else if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked())
    {
        QMessageBox::information(this,"提示:","请勿重复勾选");
    }

    else
    {
        string sex;
        string KindOfTrain;
        string NumberOfTrain;

        ifstream read("NumberOfTrain.txt");
        while(read>>NumberOfTrain)
        {
            //有意留空
        }
        read.close();

        if(ui->checkBox->isChecked())
        {
            sex = "男";
        }

        else if(ui->checkBox_2->isChecked())
        {
            sex = "女";
        }

        if(ui->radioButton->isChecked())
        {
            KindOfTrain = "硬座";

            //处理输入的预定票数过多的情况
            ifstream is1("Train.txt");
            vector<string> vec1;		//默认构造函数vec为空
            string str_1;

            while(is1>>str_1)			//把文件中数据读入内存中
            {
                vec1.push_back(str_1);			//在vector类中作用为在vector尾部加入一个数据
            }
            is1.close();

            for(size_t i = 0; i < vec1.size();i++)
            {
                if(NumberOfTrain == vec1[i])				//先找到指定位置的动车编号的位置
                {
                    string xx = vec1.at(i+4);			//取某个位置的值

                    int xx1 = atoi(xx.c_str());			//string转int

                    if(xx1 <= 0)
                    {
                        QMessageBox::warning(this,"警告:预定失败","硬座票源不足,本次预定失败,欢迎下次预定!");
                        ui->lineEdit->clear();
                        ui->lineEdit_2->clear();
                        ui->lineEdit_3->clear();
                        ui->lineEdit_4->clear();
                        ui->lineEdit_5->clear();
                        ui->checkBox->setChecked(false);
                        ui->checkBox_2->setChecked(false);
                        ui->radioButton->setChecked(false);
                        ui->radioButton_2->setChecked(false);
                        ui->radioButton_3->setChecked(false);
                        goto loop;
                    }
                }
            }

            //改变文件Train.txt中某种座位的数量
            ifstream is("Train.txt");
            vector<string> vec;		//默认构造函数vec为空
            string str_;

            while(is>>str_)			//把文件中数据读入内存中
            {
                vec.push_back(str_);			//在vector类中作用为在vector尾部加入一个数据
            }
            is.close();

            vector<string>::iterator it;		//iterator是C++标准库中的迭代器,可以实现对内存中数据的遍历
            //vector<string>::iterator it1;		//iterator前面加一个const时就可以修改it所指向的值,但不能修改it本身,eg:it++

            for(size_t i = 0; i < vec.size();i++)
            {
                if(NumberOfTrain == vec[i])				//先找到指定位置的动车编号的位置
                {
                    //it1 = it+4;  				//某个类型座位的数量

                    string xx = vec.at(i+4);			//取某个位置的值
                    string yy = vec.at(i+7);			//记录总数

                    int xx1 = atoi(xx.c_str());			//string转int
                    int yy1 = atoi(yy.c_str());

                    xx1 = xx1-1;
                    yy1 = yy1-1;

                    stringstream ss;			//stringstream可以吞下不同的类型,根据s1的类型,然后吐出不同的类型,即string转int
                    stringstream _ss;
                    ss<<xx1;
                    _ss<<yy1;

                    string sss = ss.str();
                    string sss1 = _ss.str();
                    vec[i+4] = sss; 	//改变其值
                    vec[i+7] = sss1;	//改变总数的值
                }
            }

            //将删除后的剩余内容写到文件中
            ofstream os("Train.txt");
            int w = 7;
            for(it=vec.begin(); it<vec.end(); it++,w--)
            {
                os<<*it<<" ";
                if(w == 0)
                {
                    os<<"\n";
                    w = 8;
                }
            }
        }

        else if(ui->radioButton_2->isChecked())
        {
            KindOfTrain = "硬卧";
            //处理输入的预定票数过多的情况
            ifstream _is1("Train.txt");
            vector<string> _vec1;		//默认构造函数vec为空
            string _str_1;

            while(_is1>>_str_1)			//把文件中数据读入内存中
            {
                _vec1.push_back(_str_1);			//在vector类中作用为在vector尾部加入一个数据
            }
            _is1.close();

            for(size_t i = 0; i < _vec1.size();i++)
            {
                if(NumberOfTrain == _vec1[i])				//先找到指定位置的动车编号的位置
                {
                    string _xx = _vec1.at(i+5);			//取某个位置的值

                    int _xx1 = atoi(_xx.c_str());			//int转string

                    if(_xx1 <= 0)
                    {
                        QMessageBox::warning(this,"警告:预定失败","硬卧票源不足,本次预定失败,欢迎下次预定!");
                        ui->lineEdit->clear();
                        ui->lineEdit_2->clear();
                        ui->lineEdit_3->clear();
                        ui->lineEdit_4->clear();
                        ui->lineEdit_5->clear();
                        ui->checkBox->setChecked(false);
                        ui->checkBox_2->setChecked(false);
                        ui->radioButton->setChecked(false);
                        ui->radioButton_2->setChecked(false);
                        ui->radioButton_3->setChecked(false);
                        goto loop;
                    }
                }
            }

            //改变文件Train.txt中某种座位的数量
            ifstream is("Train.txt");
            vector<string> vec;		//默认构造函数vec为空
            string str_;

            while(is>>str_)			//把文件中数据读入内存中
            {
                vec.push_back(str_);			//在vector类中作用为在vector尾部加入一个数据
            }
            is.close();

            vector<string>::iterator it;		//iterator是C++标准库中的迭代器,可以实现对内存中数据的遍历
            //vector<string>::iterator it1;		//iterator前面加一个const时就可以修改it所指向的值,但不能修改it本身,eg:it++

            for(size_t i = 0; i < vec.size();i++)
            {
                if(NumberOfTrain == vec[i])				//先找到指定位置的动车编号的位置
                {
                    string xx = vec.at(i+5);			//取某个位置的值
                    string yy = vec.at(i+7);			//记录总数

                    int xx1 = atoi(xx.c_str());			//int转string
                    int yy1 = atoi(yy.c_str());

                    xx1 = xx1-1;
                    yy1 = yy1-1;

                    stringstream ss;			//stringstream可以吞下不同的类型,根据s1的类型,然后吐出不同的类型,即string转int
                    stringstream _ss;
                    ss<<xx1;
                    _ss<<yy1;

                    string sss = ss.str();
                    string sss1 = _ss.str();
                    vec[i+5] = sss; 	//改变其值
                    vec[i+7] = sss1;	//改变总数的值
                }
            }

            //将删除后的剩余内容写到文件中
            ofstream os("Train.txt");
            int w = 7;
            for(it=vec.begin(); it<vec.end(); it++,w--)
            {
                os<<*it<<" ";
                if(w == 0)
                {
                    os<<"\n";
                    w = 8;
                }
            }
        }

        else if(ui->radioButton_3->isChecked())
        {
            KindOfTrain = "软卧";
            //处理输入的预定票数过多的情况
            ifstream __is1("Train.txt");
            vector<string> __vec1;		//默认构造函数vec为空
            string __str_1;

            while(__is1>>__str_1)			//把文件中数据读入内存中
            {
                __vec1.push_back(__str_1);			//在vector类中作用为在vector尾部加入一个数据
            }
            __is1.close();

            for(size_t i = 0; i < __vec1.size();i++)
            {
                if(NumberOfTrain == __vec1[i])				//先找到指定位置的动车编号的位置
                {
                    string __xx = __vec1.at(i+6);			//取某个位置的值

                    int __xx1 = atoi(__xx.c_str());			//int转string

                    if(__xx1 <= 0)
                    {
                        QMessageBox::warning(this,"警告:预定失败","软卧票源不足,本次预定失败,欢迎下次预定!");
                        ui->lineEdit->clear();
                        ui->lineEdit_2->clear();
                        ui->lineEdit_3->clear();
                        ui->lineEdit_4->clear();
                        ui->lineEdit_5->clear();
                        ui->checkBox->setChecked(false);
                        ui->checkBox_2->setChecked(false);
                        ui->radioButton->setChecked(false);
                        ui->radioButton_2->setChecked(false);
                        ui->radioButton_3->setChecked(false);
                        goto loop;
                    }
                }
            }

            //改变文件Train.txt中某种座位的数量
            ifstream is("Train.txt");
            vector<string> vec;		//默认构造函数vec为空
            string str_;

            while(is>>str_)			//把文件中数据读入内存中
            {
                vec.push_back(str_);			//在vector类中作用为在vector尾部加入一个数据
            }
            is.close();

            vector<string>::iterator it;		//iterator是C++标准库中的迭代器,可以实现对内存中数据的遍历
            //vector<string>::iterator it1;		//iterator前面加一个const时就可以修改it所指向的值,但不能修改it本身,eg:it++

            for(size_t i = 0; i < vec.size();i++)
            {
                if(NumberOfTrain == vec[i])				//先找到指定位置的动车编号的位置
                {
                    string xx = vec.at(i+6);			//取某个位置的值
                    string yy = vec.at(i+7);			//记录总数

                    int xx1 = atoi(xx.c_str());			//string转int
                    int yy1 = atoi(yy.c_str());

                    xx1 = xx1-1;
                    yy1 = yy1-1;

                    stringstream ss;			//stringstream可以吞下不同的类型,根据s1的类型,然后吐出不同的类型,即string转int
                    stringstream _ss;
                    ss<<xx1;
                    _ss<<yy1;

                    string sss = ss.str();
                    string sss1 = _ss.str();
                    vec[i+6] = sss; 	//改变其值
                    vec[i+7] = sss1;	//改变总数的值
                }
            }

            //将删除后的剩余内容写到文件中
            ofstream os("Train.txt");
            int w = 7;
            for(it=vec.begin(); it<vec.end(); it++,w--)
            {
                os<<*it<<" ";
                if(w == 0)
                {
                    os<<"\n";
                    w = 8;
                }
            }
        }

        //给一个类对象赋值
        P.SetPassenger(ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString(),
                       ui->lineEdit_3->text().toStdString(),sex,ui->lineEdit_4->text().toStdString(),
                       ui->lineEdit_5->text().toStdString(), NumberOfTrain, KindOfTrain);
        P.WriteIntoFile();
        QMessageBox::information(this,"提示:","预定成功,请登录查询");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(false);
        ui->radioButton_3->setChecked(false);
    }
}
