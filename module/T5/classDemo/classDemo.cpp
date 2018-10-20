#include "classDemo.h"
/*
 * 类练习
 */
Circle::Circle()
{
    this->r=5.0;
}

Circle::Circle(double R)
{
    this->r=R;
}
Circle::Circle(int R){
    this->r=R;
}
double Circle:: Area()
{
    return PI*r*r;
}

//------------------------------------------

Time::Time(){
    this->hours=0;
    this->mintues=0;
};                             //默认构造函数
Time::Time(int h, int m){
    this->hours=h;
    this->mintues=m;
};                            //显式构造函数
Time::~Time(){
    cout<<"~Time()"<<endl;
}
Time::Time(const Time &t){
    this->hours=t.hours;
    this->mintues=t.mintues;
    cout<<"Time(const Time &t)"<<endl;
}

void Time::reset( int m){
    this->mintues=m;
}
void Time::reset(int h, int m){
    this->hours=h;
    this->mintues=m;
}
void Time::show()
{
    cout << "hours:" << hours << "  " << "mintues:" << mintues << "  "<<endl;
}