//5.3：使用逗号运算符（参见4.10节，第140页）重写1.4.1节（第10页）的while循环，使它不再需要块，观察改写之后的代码的可读性提高了还是降低了？

/*10页while循环
#include<iostream>
 int main()
 {
    int sum=0,val=1;
     while(val<=10){
         sum+=val;
         ++val;
     }
     std::cout<<"Sum of 1 to 10 inclusive is "<<sum<<std::endl;
     return 0;
 }

 */
#include<iostream>
int main()
{
    int sum=0,val=1;
    while(val<=10)
        sum+=val,++val;//去掉块，分号变逗号
    std::cout<<"Sum of 1 to 10 inclusive is "<<sum<<std::endl;
    return 0;
}