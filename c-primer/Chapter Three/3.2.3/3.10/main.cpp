//3.10 编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    string aa;
    cout<<"Enter:";
    getline(cin,aa);
    for(auto c:aa)
        if(!ispunct(c))
            cout<<c;
    return 0;
}