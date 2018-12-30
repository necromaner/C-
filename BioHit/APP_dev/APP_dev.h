//
// Created by necromaner on 2018-12-26.
//

#ifndef BIOHIT_APP_DEV_H
#define BIOHIT_APP_DEV_H

#include <unistd.h>//read
#include <sys/ioctl.h>//ioctl
#include <string.h>//memset
#include <iostream>
using namespace std;


#include <stdio.h>

class APP_dev {
private:
    float Power[10];
    int iCount_Power;


    bool isMotorStart;
    bool isDoorMove;
    bool isPrinterRun;

    float Hight_Data;
    float Low_Data;

    double yx_power;//2.00 ,1.00,0.75,0.50，0.2

    int test0;
    int test1;
public:
    APP_dev();

    void Rank_Data(float *arr, int lengh);
    void Timer_SelectDian();
    float GetMeanVal(float *DataBuf, int DataNumber, float Paramater);

    void setTest(int test0,int test1);

    double getYx_power() const;
    void printfPower();
};


#endif //BIOHIT_APP_DEV_H
