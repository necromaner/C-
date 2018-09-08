/*2.17：执行下面的代码段将输出什么结果？

int i,& ri = i;

i = 5; ri =10;

std::cout<<i<<” ”<<ri<<std::endl;
 */

#include <iostream>

int main() {
    int i,& ri = i;
    i = 5; ri =10;
    std::cout<<"i = "<<i<<" ; "<<"ri = "<<ri<<std::endl;
    return 0;
}