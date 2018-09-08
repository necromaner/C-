/*4.14：执行下述if语句后将发生什么情况？
If (42 = i) //
If( i = 42)//
 */

//If (42 = i),错误，变量不能给常量赋值
//If( i = 42),当i=42时，if为真，i！=42是，为假
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}