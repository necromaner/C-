//
// Created by 温亚奇 on 2018/10/20.
//

#ifndef UNIT_TEST_CLASSDEMO_H
#define UNIT_TEST_CLASSDEMO_H

#include <iostream>
using namespace std;
#define PI 3.1415926

class Circle
{
private:
    double r;           //半径
public:
    Circle();           //构造函数
    Circle(double R);   //构造函数
    Circle(int R);      //重载
    double Area();      //求面积函数
};

class Time {
private:
    int hours;
    int mintues;
public:
    Time();                 //构造函数
    Time(int h, int m);     //构造函数
    Time(const Time &t);     //拷贝构造函数
    ~Time();                //析构函数
    void reset(int m);     //重载
    void reset(int h, int m);
    
    void show();
};
#endif //UNIT_TEST_CLASSDEMO_H
