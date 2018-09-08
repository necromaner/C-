//练习2.30 对于下面的这些语句，请说明对象被声明成了顶层const还是底层const.



#include <iostream>

int main() {
    //a.
    const int v2 =0;  //指针本身是常量，顶层
    //b.
    int v1 = v2;//拷贝v2值
    //c.
    int *p1=&v1,&r1=v1;//p1是指针，指向对象是个常量；普通的int&不能绑定到int常量上
    //d.
    const int *p2 =&v2,*const p3 =&i,&r2 =v2; //右面的是顶层，左面是底层
    return 0;
}