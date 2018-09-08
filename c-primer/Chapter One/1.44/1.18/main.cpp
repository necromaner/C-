//1.18 编译并运行本节的程序，给它输入全都相等的值，再次运行程序，输入没有重复的值。

#include <iostream>

int main() {
    int currVal=0,val=0;
    std::cout<<"Enter numbers：（End of input is not digital）"<<std::endl;
    if(std::cin>>currVal){
        int cnt=1;
        while(std::cin>>val) {
            if (val == currVal)
                ++cnt;
            else{
                std::cout<<currVal<<" occurs "<<cnt<<" time "<<std::endl;
                currVal=val;
                cnt=1;
            }
        }
        std::cout<<currVal<<" occurs "<<cnt<<" time "<<std::endl;
    }
    return 0;
}