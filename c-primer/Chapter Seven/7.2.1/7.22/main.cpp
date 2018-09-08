//7.22：修改你的Person类使其隐藏实现的细节。


#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    friend istream &read(istream &is,Person &information);
    friend ostream &print(ostream &os,const Person &information);
    Person()= default;
    Person(string na,string ad):name(na),address(ad){}
    string getName() const {return name;}
    string getAddress() const {return address;}


private:
    string name;
    string address;
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
    cout<<endl;
    Person trans("abc","defgh");
    print(cout,trans);
    return 0;
}