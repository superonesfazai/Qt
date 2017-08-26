#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#include "Train.h"
#include <QFile>
#include <QTextStream>
using namespace std;


Train::Train(string NumberOfTrain,string TimeOfTrain,	string StartOfTrain, string FinishOfTrain,
            int hard_seat,int hard_berth,int soft_berth,int RestOfTrain)
{
    this->NumberOfTrain = NumberOfTrain;
    this->TimeOfTrain = TimeOfTrain;
    this->StartOfTrain = StartOfTrain;
    this->FinishOfTrain = FinishOfTrain;
    this->hard_seat = hard_seat;
    this->hard_berth = hard_berth;
    this->soft_berth = soft_berth;
    this->RestOfTrain = RestOfTrain;
    RestOfTrain = this->hard_seat+this->hard_berth+this->soft_berth;
}

void Train::SetTrain(string NumberOfTrain, string TimeOfTrain,	string StartOfTrain, string FinishOfTrain,
              int hard_seat,int hard_berth,int soft_berth)
{
    this->NumberOfTrain = NumberOfTrain;
    this->TimeOfTrain = TimeOfTrain;
    this->StartOfTrain = StartOfTrain;
    this->FinishOfTrain = FinishOfTrain;
    this->hard_seat = hard_seat;
    this->hard_berth = hard_berth;
    this->soft_berth = soft_berth;
    RestOfTrain = this->hard_seat+this->hard_berth+this->soft_berth;
}

string Train::GetNumber()
{
    return this->NumberOfTrain;
}

string Train::GetTime()
{
    return this->TimeOfTrain;
}

string Train::GetStart()
{
    return this->StartOfTrain;
}

string Train::GetFinish()
{
    return this->FinishOfTrain;
}

int Train::GetHard_seat()
{
    return hard_seat;
}
int Train::GetHard_berth()
{
    return hard_berth;
}
int Train::GetSoft_berth()
{
    return soft_berth;
}

int Train::GetRest()
{
    return this->hard_seat+this->hard_berth+this->soft_berth;
}

void Train::WriteIntoFile()     //之前我用C++的文件流写入文件但是中文乱码,后来找到解决方法,但是遇到每一个QString转化为string都要用三句长话,索性就改用了QT的文件流,方便点
{
    /*
    ofstream write;
    write.open("Train.txt",ios::app);		//ios::noreplace   打开一个文件时，如果文件不存在，创建该文件
     if (!write)
    {
        cout<< "open file error!" <<"\n";
        abort();
    }
    write<<GetNumber()
         <<" "<<GetTime()
         <<" "<<GetStart()
         <<" "<<GetFinish()
         <<" "<<GetHard_seat()
         <<" "<<GetHard_berth()
         <<" "<<GetSoft_berth()
         <<" "<<GetRest()<<"\n";
    write.close();
    */
    QFile read("Train.txt");
    read.open(QIODevice::WriteOnly | QIODevice::Append);     //在文件的后面添加内容,清空原来的内容,只要IO_WriteOnly
    QTextStream write(&read);
    write<<QString::fromStdString(GetNumber())      //string转为QString,再进行录入
         <<" "<<QString::fromStdString(GetTime())
         <<" "<<QString::fromStdString(GetStart())
         <<" "<<QString::fromStdString(GetFinish())
         <<" "<<GetHard_seat()
         <<" "<<GetHard_berth()
         <<" "<<GetSoft_berth()
         <<" "<<GetRest()<<"\n";
    //write.close();
}
