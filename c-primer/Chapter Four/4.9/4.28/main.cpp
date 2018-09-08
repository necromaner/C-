//4.28 编写一段程序，输出每一种内置类型所占空间的大小。

#include <iostream>
using std::cout;
using std::endl;
int main() {
    cout<<"int            : "<< sizeof(int)<<endl;
    cout<<"long int       : "<< sizeof(long int)<<endl;
    cout<<"unsigned int   : "<< sizeof(unsigned int)<<endl;
    cout<<"long           : "<< sizeof(long)<<endl;
    cout<<"long long      : "<< sizeof(long long)<<endl;
    cout<<"unsigned long  : "<< sizeof(unsigned long)<<endl;
    cout<<"char           : "<< sizeof(char)<<endl;
    cout<<"unsigned char  : "<< sizeof(unsigned char)<<endl;
    cout<<"short          : "<< sizeof(short)<<endl;
    cout<<"unsigned short : "<< sizeof(unsigned short)<<endl;
    cout<<"double         : "<< sizeof(double)<<endl;
    cout<<"long double    : "<< sizeof(long double)<<endl;
    cout<<"float          : "<< sizeof(float)<<endl;
    cout<<"bool           : "<< sizeof(bool)<<endl;
    return 0;
}