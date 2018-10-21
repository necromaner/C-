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
    return PI*square(this->r);
}

double Circle::getR() const {
    return r;
}

void Circle::setR(double r) {
    Circle::r = r;
}

Cylindrical::Cylindrical(){
    this->setR(5);
    this->h=5;
}
Cylindrical::Cylindrical(double R){
    this->setR(R);
    this->h=5;
}
Cylindrical::Cylindrical(double R, double H){
    this->setR(R);
    this->h=H;
}
void Cylindrical::setH(double h) {
    Cylindrical::h = h;
}

double Cylindrical::getH() const {
    return h;
}

double Cylindrical::Volume(){
    return Area()*getH();
}
//------------------------------------------

Time::Time(){
    cout<<"这是Time的构造函数"<<endl;
    this->hours=0;
    this->mintues=0;
};                             //默认构造函数

Time::Time( int h): hours(h)
{
    cout<<"这是Time的带参构造函数"<<endl;
    cout << "Object is being created, length = " << h << endl;
}

Time::Time(int h, int m){
    cout<<"这是Time的带参构造函数"<<endl;
    this->hours=h;
    this->mintues=m;
};                            //显式构造函数
Time::~Time(){
    cout<<"这是Time的析构函数"<<endl;
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