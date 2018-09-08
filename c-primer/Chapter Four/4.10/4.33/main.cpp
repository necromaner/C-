/*4.33 根据4.12节中的表说明下面这条表达式的含义。
someValue ? ++x, ++y : --x, --y
 */



#include <iostream>

int main() {
    someValue ? ++x, ++y : --x, --y//','优先度最低，（someValue ? ++x, ++y : --x）, --ysomeValue 为真，++x,++y，为假--x
    return 0;
}