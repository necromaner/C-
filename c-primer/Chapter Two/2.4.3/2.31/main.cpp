//练习 2.31 假设已有上一个练习中所做的那些声明，则下面的那些语句是合法的，请说明顶层const和底层const在每个例子中有何体现。


#include <iostream>

int main() {
r1 =v2; //
p1=p2; //p2底层，p1不是
p2=p1;//
p1=p3;//p3底层，p1不是
p2=p3;//
    return 0;
}