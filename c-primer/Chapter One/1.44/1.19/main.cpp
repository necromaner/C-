// 1.19 修改你为1.4.1 练习1.10（第11页）所编写的程序（打印一个范围内的数），使其能处理用户输入的第一个数比第二个数小的情况。

#include <iostream>
int main() {
    int val=0,x2=0;
    std::cout<<"Enter two numbers:";
    std::cin>>val>>x2;
    if(val<=x2) {
        while (val <= x2) {
            std::cout << val << std::endl;
            ++val;
        }
    }
    else{
        while(val>=x2){
            std::cout<<val<<std::endl;
            --val;
        }
    }
    return 0;
}