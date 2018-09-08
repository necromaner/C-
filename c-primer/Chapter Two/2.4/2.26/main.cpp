/*练习 2.26 下面那些句子是合法的，如果有不合法的句子，请说明为什么
a . const int buf;
b. int cnt =0;
c const int sz = cnt;
d ++cnt;++sz;
 */

#include <iostream>

int main() {
    //a . 
    const int buf;//不合法 没有初始化const
    //b. 
    int cnt =0;
    //c  
    const int sz = cnt;
    //d 
    ++cnt;++sz; //错误 sz是const 不能对其值进行修改
    return 0;
}