/*4.9：解释在下面的if语句中条件部分的判断过程。
const char *cp = "Hello World";
if (cp && *cp) */

//当括号里的值非零为真，&&表示当cp和*cp都不为零时为真，cp为指针，指向某个地址，所以不为空，为真；*cp指向Hello World，不为空，为真。所以if为真
#include <iostream>

int main() {
    const char *cp = "Hello World";
    if (cp && *cp)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}