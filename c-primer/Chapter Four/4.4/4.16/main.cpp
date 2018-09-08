/*4.16：尽管下面的语句合法，但它们实际执行的行为可能和预期并不一样，为什么？应该如何修改？
（a） if (p = getPtr() != 0)
（b） if (i = 1024)
 */

 //（a） if ((p = getPtr()) != 0)
//（b） if (i == 1024)

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}