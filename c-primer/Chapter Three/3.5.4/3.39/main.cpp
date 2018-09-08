//3.39：编写一段程序，比较两个string对象。再编写一段程序，比较两个C风格字符串的内容。

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    string aa="asd";
    string bb="asb";
    string cc="asd";
    if(aa==bb)
        cout<<"aa==bb"<<endl;
    else
        cout<<"aa!=bb"<<endl;
    if(aa==cc)
        cout<<"aa==cc"<<endl;
    else
        cout<<"aa!=cc"<<endl;

    const char aa1[]="asd";
    const char bb1[]="asb";
    const char cc1[]="asd";
    if(strcmp(aa1,bb1)==0)
        cout<<"aa1= bb1"<<endl;
    else
        cout<<"aa1!=bb1"<<endl;
    if(strcmp(aa1,cc1)==0)
        cout<<"aa1==cc1"<<endl;
    else
        cout<<"aa1!=cc1"<<endl;
    return 0;
}