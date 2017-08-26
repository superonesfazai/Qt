#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <QFile>
#include <QTextStream>
#include "Passenger.h"
using namespace std;

Passenger::Passenger(string username,string password,string name,string sex,string ID,string phone,string NumberOfTrain,string KindOfSeat)
{
    this->username = username;
    this->password = password;
    this->name = name;
    this->sex = sex;
    this->ID = ID;
    this->phone = phone;
    this->NumberOfTrain = NumberOfTrain;
    this->KindOfSeat = KindOfSeat;
}

string Passenger::Getusername()
{
    return this->username;
}

string Passenger::Getpassword()
{
    return this->password;
}

string Passenger::Getname()
{
    return this->name;
}

string Passenger::Getsex()
{
    return this->sex;
}

string Passenger::GetID()
{
    return this->ID;
}

string Passenger::Getphone()
{
    return this->phone;
}

string Passenger::GetNumberOfTrain()
{
    return this->NumberOfTrain;
}

string Passenger::GetKindOfSeat()
{
    return this->KindOfSeat;
}

void Passenger::SetPassenger(string username,string password,string name,string sex,string ID,string phone,string NumberOfTrain,string KindOfSeat)
{
    this->username = username;
    this->password = password;
    this->name = name;
    this->sex = sex;
    this->ID = ID;
    this->phone = phone;
    this->NumberOfTrain = NumberOfTrain;
    this->KindOfSeat = KindOfSeat;
}

void Passenger::WriteIntoFile()
{
    QFile read("Passenger.txt");
    read.open(QIODevice::WriteOnly | QIODevice::Append);     //在文件的后面添加内容,清空原来的内容,只要IO_WriteOnly
    QTextStream write(&read);
    write<<QString::fromStdString(Getusername())
         <<" "<<QString::fromStdString(Getpassword())
         <<" "<<QString::fromStdString(Getname())
         <<" "<<QString::fromStdString(Getsex())
         <<" "<<QString::fromStdString(GetID())
         <<" "<<QString::fromStdString(Getphone())
         <<" "<<QString::fromStdString(GetNumberOfTrain())
         <<" "<<QString::fromStdString(GetKindOfSeat())<<"\n";
}
