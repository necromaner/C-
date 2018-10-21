#include "classDemo.h"
/*
 * 类练习
 */
Circle::Circle()
{
    this->r=5.0;
    printf("圆-半径%f\n",this->r);
}

Circle::Circle(double R)
{
    this->r=R;
    printf("圆-半径%f\n",this->r);
}
Circle::Circle(int R){
    this->r=R;
    printf("圆-半径%f\n",this->r);
}

double Circle:: Area()
{
    printf("圆面积：");
    return PI*square(this->r);
}

double Circle::getR() const {
    return r;
}

void Circle::setR(double r) {
    Circle::r = r;
}

Circle::~Circle() {
    cout << "这是圆的析构函数" << endl;
}

Cylindrical::Cylindrical(){
    this->s=1;
    this->setR(0);
    this->h=0;
    printf("圆柱-高%f\n",this->h);
}

Cylindrical::Cylindrical(double R) : Circle(R) {
    this->h=0;
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
    printf("圆柱体积：");
    return Area()*getH();
}


Cone::Cone() {
    printf("圆锥\n");
    this->setR(0);
    this->setH(0);
}
Cone::Cone(double R) : Cylindrical(R) {
    this->setH(0);
}
Cone::Cone(double R, double H) : Cylindrical(R, H) {}

Cone::~Cone() {
    cout << "这是圆锥的析构函数" << endl;
    
}
double Cone::Volume(){
    printf("圆锥体积：");
    return this->a*Area()*getH();
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

