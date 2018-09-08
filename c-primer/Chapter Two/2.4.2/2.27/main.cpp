//练习 2.27 下面的那些初始化是合法的，请说明原因




#include <iostream>

int main() {
    //a.
    int i = -1,&r =0;//引用错误，r是一个普通的非常量引用
    //b.
    int *const p2 =&i2;//
    //c.
    const int i = -1,&r =0;//
    //d.
    const int *const p3 = &i2;//
    //e.
    const int *p1 =&i2;//
    //f.
    const int &const r2;//错误，引用不能const
    //g.
    const int i2 = i;&r=i;//
    return 0;
}