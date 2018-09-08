//5.23：编写一段程序，从标准输入读取两个整数，输出第一个整数除以第二个整数的结果。

#include <iostream>
using namespace std;

int main() {
    int aa,bb;
    cout<<"Enter:";
    cin>>aa;
    cout<<"Enter:";
    cin>>bb;
    double cc;
    cc=1.0*aa/bb;
    cout<<"aa + bb = "<<cc<<endl;
    return 0;
}