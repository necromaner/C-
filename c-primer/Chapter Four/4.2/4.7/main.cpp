//4.7：溢出是何含义?写出三条将导致溢出的表达式。

//溢出是超过了指定范围
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    short aa=32767;
    aa+=1;
    cout<<"aa = "<<aa<<endl;
    short aa1=-32767;
    aa1+=-2;
    cout<<"aa1 = "<<aa1<<endl;
    return 0;
}