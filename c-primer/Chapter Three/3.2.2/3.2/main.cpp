//3.2 编写一段程序从标准输入中读入一整行，然后修改程序使其一次读入一个词。

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    string line;
    cout<<"Enter :"<<endl;
    while(cin>>line)//一次读入一个词
    //while(getline(cin,line))//读入一整行
        cout<<line<<endl;
        cout<<"Enter :"<<endl;
    return 0;
}