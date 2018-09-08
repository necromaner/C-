/*4.19：假设ptr的类型是指向int的指针、vec的类型是vector<int>、ival的类型是int，说明下面的表达式是何含义？如果有表达式不正确，为什么？应该如何修改？

(a) ptr != 0 && *ptr++    (b) ival++ && ival

(c) vec[ival++] <= vec[ival]
 */

/*
 (a) ptr != 0 && *ptr++    //ptr不为空指针且*ptr++为真是为真
 (b) ival++ && ival  //错，应该互换位置
 (c) vec[ival++] <= vec[ival]  //错
 */
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}