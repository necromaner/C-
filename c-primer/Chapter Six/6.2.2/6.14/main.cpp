//6.14：举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。

#include "Chapter6.h"

int main() {
    int aa,bb,cc,dd;
    cout<<"Enter two number:";
    cin>>aa>>bb;
    cc=aa;
    dd=bb;
    cout<<"Brfore    two number is: "<<aa<<" "<<bb<<endl;
    exchange1(aa,bb);//引用
    cout<<"Exchange1 two number is: "<<aa<<" "<<bb<<endl;
    exchange2(&cc,&dd);//指针
    cout<<"Exchange1 two number is: "<<cc<<" "<<dd<<endl;

    return 0;
}