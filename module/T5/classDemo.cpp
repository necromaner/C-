#include "learn.h"

//------------------------------------------
Circle::Circle()
{
    this->r=5.0;
}

Circle::Circle(double R)
{
    this->r=R;
}

double Circle:: Area()
{
    return 3.14*r*r;
}

//------------------------------------------

Time::Time(){
    this->hours=0;
    this->mintues=0;
};                                                       //默认构造函数
Time::Time(int h, int m){
    this->hours=h;
    this->mintues=m;
};                                       //显式构造函数
void Time::AddMin(int m){
    this->mintues=m;
};
void Time::AddHour(int h){
    this->hours=h;
};

void Time::reset(int h, int m){
    this->hours=h;
    this->mintues=m;
}
void Time::show()
{
    cout << "hours:" << hours << "  " << "mintues:" << mintues << "  "<<endl;
}