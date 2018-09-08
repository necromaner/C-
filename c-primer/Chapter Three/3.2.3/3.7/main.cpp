//3.7 就上一题完成的程序而言，如果将循环控制变量的类型设为char将发生什么？先估算一下结果，然后实际编程进行验证。

//没有变化

//3.6:编写一段程序，使用范围for语句将字符串内的所有字符用X代替

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    string aa;
    cout<<"Enter:"<<endl;
    getline(cin,aa);
    for(char &c:aa)
        if(isgraph(c))
            c='X';
    cout<<"The results of :"<<aa<<endl;
    return 0;
}
