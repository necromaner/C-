//4.18：如果第148页那个输出vector对象元素的while循环使用前置递增运算符，将得到什么结果？

//后置先取值再自加，前置先自加再取值
#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main() {
    vector<int> v={1,2,3,4,5};
    auto pbeg=v.begin();
    while(pbeg!=v.end()&&*pbeg>=0)
        cout<<*++pbeg<<endl;
    return 0;
}