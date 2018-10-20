//
// Created by 温亚奇 on 2018/10/20.
//

#ifndef UNIT_TEST_INHERITANCE_H
#define UNIT_TEST_INHERITANCE_H

#include <iostream>
using namespace std;
/*
public:可以被任意实体访问
protected:只允许子类及本类的成员函数访问
private:只允许本类的成员函数访问
 */
class inheritance {

};
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

#endif //UNIT_TEST_INHERITANCE_H
