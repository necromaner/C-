/*2.16 考察下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了什么样的操作？

int i =0,&ri = i; double d =0 ,&r2 = d;

(a) r2 =3.14159;

(b) r2 = r1;

(c) i =r2;

(d) r1 =d ;
 */

#include <iostream>

int main() {
    int i =0,&ri = i; double d =0 ,&r2 = d;
    //(a)
    r2 =3.14159;//d赋值3.14159
    //(b)
    r2 = r1;//值自动转换
    //(c)
    i =r2;//值会丢失
    //(d)
    r1 =d ;//值会丢失
    return 0;
}