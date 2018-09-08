/*练习 2.25 说明下面变量的类型和值
a. int * ip,i,&r = i;
b.int i,*ip=0;
c. int* ip,ip2;
*/
#include <iostream>

int main() {
    //(a)
    int * ip,i,&r = i; //ip 指向int类型的指针，i int变量，r int类型引用
    //(b).
    int i,*ip=0;//i int类型变量，ip int类型指针，初始化为0
    //(c)
    int* ip,ip2;//ip int类型指针，ip2 int类型变量
    return 0;
}