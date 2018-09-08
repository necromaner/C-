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
    for(auto &c:aa)
        if(isgraph(c))
            c='X';
    cout<<"The results of :"<<aa<<endl;
    return 0;
}