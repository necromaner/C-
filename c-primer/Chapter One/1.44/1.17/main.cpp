//1.17 如果输入的所有值都是相等的，本节的程序会输出什么？如果没有重复值，输出又会是怎样的？
//如果都想等，则会一直计数，不会输出；没有重复值输一个就输出一个。
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