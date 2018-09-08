//7.5：在你的Person类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是const的呢？解释原因。

//答：应该是const，指针所指对象不会改变
#include <iostream>
#include <string>

using namespace std;

struct Person{
    string name;
    string address;

    string getName() const {return name;}
    string getAddress() const {return address;}
};
int main() {
    Person total;
    cout<<"name : ";
    cin>>total.name;
    cout<<"address : ";
    cin>>total.address;
    cout<<"name : "<<total.getName()<<endl;
    cout<<"address : "<<total.getAddress()<<endl;
    return 0;
}