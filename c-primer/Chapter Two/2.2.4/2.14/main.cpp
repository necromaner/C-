/*2.14 下面的程序合法吗？如果合法，它将输出什么？

int i = 100,sum = 0;
for(int i =0 ;i!=10;++i)
{
sum+=i;
}
std::cout<<i <<” ”<<sum<<std::endl;
*/

#include <iostream>

int main() {
    int i = 100,sum = 0;
    for(int i =0 ;i!=10;++i)
    {
    sum+=i;
    }
    std::cout<<"i = "<<i <<" "<<"sum = "<<sum<<std::endl;//i = 100 sum = 45(sum=0+1+2+3+4+5+6+7+8+9)
    return 0;
}