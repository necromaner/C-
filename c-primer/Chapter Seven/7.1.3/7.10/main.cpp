//7.10：在下面if语句中，条件部分的作用是什么？
//if(read(read(cin,data1),data2))

//答:read(cin,data1)向data1输入内容，read(read(cin,data1),data2)把data1内容输入到data2里，if(read(read(cin,data1),data2))如果值为0为假
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

int main() {
    Person data1;
    Person data2;
    if(read(read(cin,data1),data2)){
    }
        return 0;
}