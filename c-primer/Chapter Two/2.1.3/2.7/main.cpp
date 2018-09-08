/*2.7：下述字面值表示何种含义？它们各自的数据类型是什么？

(a)”Who goes with F\145rgus?\012”

(b)3.14e1L (c)1024f (d)3.14L
 */

#include <iostream>

int main() {
    std::cout<<"(a): " << "Who goes with F\145rgus?\012" << std::endl;
    std::cout<<"(b): " << "3.14e1L" << std::endl;//long double
    std::cout<<"(c): " << "1024f" << std::endl;//float
    std::cout<<"(d): " << "3.14L" << std::endl;//log double

    return 0;
}