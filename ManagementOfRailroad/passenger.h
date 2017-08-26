#include <iostream>
#include <string.h>
using namespace std;

#ifndef PASSENGER_H
#define PASSENGER_H

class Passenger			//乘客类
{
    public:
        Passenger(string username,string password,string name,string sex,string ID,string phone,string NumberOfTrain,string KindOfSeat);
        Passenger()
        {
            //有意留空
        }
        string Getusername();
        string Getpassword();
        string Getname();
        string Getsex();
        string GetID();
        string Getphone();
        string GetNumberOfTrain();
        string GetKindOfSeat();
        void SetPassenger(string username,string password,string name,string sex,string ID,string phone,string NumberOfTrain,string KindOfSeat);
        void WriteIntoFile();
        ~Passenger()
        {

        }
    private:
        string username;
        string password;
        string name;
        string sex;
        string ID;
        string phone;
        string NumberOfTrain;			//动车编号
        string KindOfSeat;				//座位类型
};

#endif // PASSENGER_H

