//4.22：本节的示例程序将成绩划分成high pass,pass 和fail三种，扩展改程序使其进一步将60分到75分之间的成绩设定为low pass。要求程序包含两个版本：一个版本只使用条件运算符；另外一个版本使用1个或多个if语句。哪个版本的程序更容易理解呢？为什么?

//两个版本都容易理解
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    int aa;
    cout<<"Enter number:";
    cin>>aa;
    cout<<"1."<<endl<<"finalggrade :"<<((aa>90)?"high pass":(aa>75)?"pass":(aa>60)?"low pass":"fail")<<endl;
    cout<<"2."<<endl<<"finalggrade :";
    if(aa>90)
        cout<<"high pass";
    else if(aa>75)
        cout<<"pass";
    else if(aa>60)
        cout<<"low pass";
    else
        cout<<"fail";
    cout<<endl;
    return 0;
}