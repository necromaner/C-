//1.16  编写程序，从cin读取一组数，输出其和。

#include <iostream>

int main() {
    int sum=0,value=0;
    std::cout<<"Enter some numbers:(End of input is not digital)"<<std::endl;
    while(std::cin>>value)
        sum+=value;
    std::cout<<"Sum is "<<sum<<std::endl;
    return 0;
}