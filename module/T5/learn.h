//
// Created by 温亚奇 on 2018/10/15.
//

#ifndef UNIT_TEST_LEARN_H
#define UNIT_TEST_LEARN_H

#include <iostream>
using namespace std;
//-------------------运算符优先级-------------------
void t1();
int t1_1();

//-------------------类----------------------------
class Circle
{
private:
    double r;//半径
public:
    Circle();//构造函数
    Circle(double R);//构造函数
    double Area();//求面积函数
};

class Time
{
private:
    int hours;
    int mintues;
public:
    Time();                                                       //默认构造函数
    Time(int h, int m);                                       //显式构造函数
//    Time(const Time &);                                           //拷贝构造函数
//    ~Time();                                                      //析构函数
    void AddMin(int m);
    void AddHour(int h);
    
    void reset(int h = 0, int m = 0);
    void show();
    

    
};







#endif //UNIT_TEST_LEARN_H
