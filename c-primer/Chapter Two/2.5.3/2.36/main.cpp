/*练习2.36 关于下面的代码，请指出每一个变量的类型以及程序结束时他们各自的值

int a =3,b =4;
decltype(a) c =a ;
decltype((b)) d= a;
++c;
++d;
 */

#include <iostream>

int main() {
    int a =3,b =4; //a=3,b=4
    decltype(a) c =a ;// int c;c=a=3
    decltype((b)) d= a; //int &d;c=3;d=a=3   双层括号结果永远是引用
    ++c; //c=4,a=3
    ++d; //a=d=4
    return 0;
}