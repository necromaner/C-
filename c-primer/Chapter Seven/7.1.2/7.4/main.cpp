//7.4：编写一个名为Person的类，使其表示人员的姓名和地址。使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。


#include <iostream>
#include <string>

using namespace std;

struct Person{
    string name;
    string address;

};
int main() {
    Person total;
    cout<<"name : ";
    cin>>total.name;
    cout<<"address : ";
    cin>>total.address;
    cout<<"name : "<<total.name<<endl;
    cout<<"address : "<<total.address<<endl;
    return 0;
}