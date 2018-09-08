/*6.2：请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？

(a). int f()
{
    string s;
    //…
    return s;
}

(b) f2(int i){/ *…* /}
(c) int calc(int v1, int v1) / *…* / }
(d) double square(double x) return x*x;
*/

#include <iostream>
#include<string>

int f()//a.
{
    int s;
    //…
    return s;
}

int f2(int i){/*…*/}//c.缺int

int calc(int v1, int v2) {/*…*/}//b.不能有两个相同的行参名

double square(double x) {return x*x;}//c.无大括号
int main() {
    return 0;
}