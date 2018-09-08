//6.12：改写6.2.1节中练习6.10（第188页）的程序，使用引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？
//6.10：编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数，并输出交换后的结果，以此验证函数的正确性。

//引用，更简单方便
#include "Chapter6.h"

int main() {
    int aa,bb;
    cout<<"Enter two number:";
    cin>>aa>>bb;
    cout<<"Brfore   two number is: "<<aa<<" "<<bb<<endl;
    exchange(aa,bb);
    cout<<"Exchange two number is: "<<aa<<" "<<bb<<endl;

    return 0;
}