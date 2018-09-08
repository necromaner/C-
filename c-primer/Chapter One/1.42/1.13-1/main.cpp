//1.13： 使用for循环重做1.4.1节中的所有练习（第11页）。
//1.9 ： 编写程序，使用while循环将50到100的整数相加。


#include <iostream>

int main()
{
    int sum = 0;
    for (int val = 50; val <= 100; ++val) {
        sum = sum + val;
    }
    std::cout << "the sum of 50 to 100 is " << sum << std::endl;
    return 0;
}