//7.9：对于7.1.2节（第233页）练习中的代码，添加读取和打印Person对象的操作。

#include <iostream>
#include <string>

using namespace std;

struct Person{
    string name;
    string address;

    string getName() const {return name;}
    string getAddress() const {return address;}
};

istream &read(istream &is,Person &information){
    cout<<"name :";
    is>>information.name;
    cout<<"address : ";
    is>>information.address;
}
ostream &print(ostream &os,const Person &information){
    os<<"name : "<<information.getName()<<endl;
    os<<"address : "<<information.getAddress() <<endl;
}
int main() {
    Person total;
    read(cin,total);
    print(cout,total);
    return 0;
}