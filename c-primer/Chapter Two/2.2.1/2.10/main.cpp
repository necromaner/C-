/*2.10 下列变量的初始值分别是什么？

std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}


 */

#include <iostream>

std::string global_str;//空串
int global_int;//0
int main()
{
    int local_int;//不确定值
    std::string local_str;//空串
}