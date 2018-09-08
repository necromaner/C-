//6.26:编写一个程序，使其接受本节所示的选项；输出传递给main函数的实参的内容。

#include <iostream>
#include <string>
using namespace std;

int main(int argc,char **argv) {
    string aa;
    for(int i=0;i<=argc;i++){
        aa+=argv[i];
        aa+=" ";
    }
    cout<<aa<<endl;
    return 0;
}