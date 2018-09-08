//6.25：编写一个mian函数，令其接受两个实参，把实参的内容连接成一个string对象并输出出来。

#include <iostream>
#include <string>
using namespace std;

int main(int argc,char **argv) {
    string aa;
    for(int i=0;i<argc;i++){
        aa+=argv[i];
        aa+=" ";
    }
    cout<<aa<<endl;
    return 0;
}