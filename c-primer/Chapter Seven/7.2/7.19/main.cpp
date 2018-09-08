//7.19 在你的Person类中，你将哪些成员声明成public？哪些声明成private？解释你这样做的原因。

//将数据成员放在private中。
#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    Person()= default;
    Person(string na,string ad):name(na),address(ad){}
    string getName() const {return name;}
    string getAddress() const {return address;}

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
private:
    string name;
    string address;
};
int main() {
    Person person;
    Person total;
    person.read(cin,total);
    person.print(cout,total);
    cout<<endl;
    Person trans("abc","defgh");
    person.print(cout,trans);
    return 0;
}