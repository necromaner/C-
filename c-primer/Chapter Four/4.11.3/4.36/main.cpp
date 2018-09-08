//4.36：假设i是int类型，d是double类型，书写表达式i*=d使其执行整数类型的乘法而非浮点类型的乘法。

#include <iostream>
using std::cout;
using std::endl;

int main() {
    int i=20;
    double d=2.222;
    cout<<i<<"    "<<static_cast<int>(d)<<endl;
    i*= static_cast<int>(d);
    cout<<i<<"    "<<static_cast<int>(d)<<endl;
    return 0;
}