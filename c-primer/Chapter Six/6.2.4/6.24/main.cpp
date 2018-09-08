/*6.24：描述下面这个函数的行为。如果代码中存在问题，请指出并改正。

void print(const int ia[10])
{
for (size_t i =0; i ！= 10; ++i)
    cout << ia[i] << endl;
}
 */

//依次输出维度为10的值
#include <iostream>
using namespace std;

void print(const int ia[10]) {
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}

int main() {
    int i[10]={1,2,3,4,5,6,7,8,9,10};
    print(i);
    return 0;
}