/*2.32 下面代码是否合法，如果非法，请假设将其修改正确
int null = 0 ,*p =null;
 */

#include <iostream>

int main() {
    int null = 0 ,*p =&null;
    return 0;
}