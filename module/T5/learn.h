//
// Created by 温亚奇 on 2018/10/15.
//

#ifndef UNIT_TEST_LEARN_H
#define UNIT_TEST_LEARN_H
#define PI 3.1415926
#include <iostream>
using namespace std;
//-------------------运算符优先级-------------------
void t1();
int t1_1();

//-------------------类----------------------------
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

class Time
{
private:
    int hours;
    int mintues;
public:
    Time();                 //构造函数
    Time(int h, int m);     //构造函数
//    Time(const Time &);     //拷贝构造函数
//    ~Time();                //析构函数
    void AddMin(int m);
    void AddHour(int h);
    
    void reset(int h = 0, int m = 0);
    void show();
    

    
};


//----------virtual-------------------

class A
{
public:
    virtual void out1()=0;   //纯虚函数
    virtual ~A(){};          //析构函数
    virtual void out2()      //虚函数
    {
        cout<<"A(out2)"<<endl;
    }
    void out3()             //重写
    {
        cout<<"A(out3)"<<endl;
    }
};

class B:public A
{
public:
    virtual ~B(){};
    void out1()
    {
        cout<<"B(out1)"<<endl;
    }
    void out2()
    {
        cout<<"B(out2)"<<endl;
    }
    void out3()
    {
        cout<<"B(out3)"<<endl;
    }
};


enum TrafficLight{RED,YELLOR,GREEN};

#endif //UNIT_TEST_LEARN_H
