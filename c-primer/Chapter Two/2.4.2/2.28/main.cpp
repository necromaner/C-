//练习 2.28 说明下面的这些定义是什么意思，挑出其中不合法的。



#include <iostream>

int main() {
//a. 
int i,*const cp;//没有初始化
//b. 
int *p1,*const p2; //没有初始化
//c. 
const int ic,&r =ic;//没有初始化
//d.
const int * const p3;//没有初始化
//e. 
const int *p; //正确,指针是常量
    return 0;
}