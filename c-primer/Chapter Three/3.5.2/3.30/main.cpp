/*3.30：指出下面代码中的索引错误。

constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
ia[ix] = ix;
*/

#include <iostream>

int main() {
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 1; ix <= array_size; ++ix)//从0开始而不是从1开始，最后就是最后一个下表越界
        ia[ix] = ix;
    return 0;
}