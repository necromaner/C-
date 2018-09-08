//6.10：编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数，并输出交换后的结果，以此验证函数的正确性。

#include "Chapter6.h"

int main() {
    int aa,bb;
    cout<<"Enter two number:";
    cin>>aa>>bb;
    cout<<"Enter    two number is: "<<aa<<" "<<bb<<endl;
    exchange(&aa,&bb);
    cout<<"Exchange two number is: "<<aa<<" "<<bb<<endl;

    return 0;
}