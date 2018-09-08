//1.13 使用for循环重做1.4.1节中的所有练习（第11页）。
//1.11 编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。

#include <iostream>
int main() {
    int val,x2;
    std::cout<<"Enter two numbers:";
    std::cin>>x2>>val;
    for(int i=x2;i<=val;++i)
    {
        std::cout<<i<<std::endl;
    }
    return 0;
}