/* 1.6 解释下面程序片段是否合法。
    std::cout << "The sum of " << v1;
                << " and " << v2;
                << " is " << v1 + v2 << std::endl;
如果程序是合法的，它输出什么？如果程序不合法，原因何在？应该如何修正？*/


//答：不合法，第一行和第二行末尾不应该有分号，应改为如下
/*
     std::cout << "The sum of " << v1
                << " and " << v2
                << " is " << v1 + v2 << std::endl;
 */
#include <iostream>

int main() {
int v1=3,v2=5;
      std::cout << "The sum of " << v1
                << " and " << v2
                << " is " << v1 + v2 << std::endl;
    return 0;
}