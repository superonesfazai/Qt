#include <string.h>
#include <iostream>
using namespace std;

#ifndef TRAIN_H
#define TRAIN_H


class Train
{
public:
    Train(string NumberOfTrain, string TimeOfTrain,	string StartOfTrain, string FinishOfTrain,
            int hard_seat,int hard_berth,int soft_berth,int RestOfTrain);
    Train()
    {

    }

    string GetNumber();
    string GetTime();
    string GetStart();
    string GetFinish();
    int GetHard_seat();
    int GetHard_berth();
    int GetSoft_berth();
    int GetRest();
    void SetTrain(string NumberOfTrain, string TimeOfTrain,	string StartOfTrain, string FinishOfTrain,
                  int hard_seat,int hard_berth,int soft_berth);
    void WriteIntoFile();
    ~Train()
    {

    }
private:
    string NumberOfTrain;
    string TimeOfTrain;
    string StartOfTrain;
    string FinishOfTrain;
    int hard_seat, hard_berth, soft_berth;
    int RestOfTrain;
};

#endif // TRAIN_H
