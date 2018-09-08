//3.5 编写一段程序从标准输入中读入多个字符串并将他们连接在一起，输出连接成的大字符串，然后修改上述程序，用空格把输入的多个字符串分隔开来。

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    string aa,bb,cc;
    cout<<"Enter:";
    cin>>aa;
    while(getline(cin,aa)){
        if(!aa.empty())
        bb+=aa;
        cc=cc+" "+aa;
        cout<<"Enter:";
    }
    cout<<"There is no space to separate:"<<bb<<endl;
    cout<<"Have a space-delimited:"<<cc<<endl;
    return 0;
}