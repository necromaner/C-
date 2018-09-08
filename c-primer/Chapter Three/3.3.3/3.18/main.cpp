/*3.18：下面的程序合法吗？如果不合法，你准备如何修改？

    vector<int> ivec;
    ivec[0] = 42;
    */
//不合法，没有[0]这个空间
#include <iostream>
#include<vector>
using std::vector;
int main() {
    vector<int> ivec(10);
    ivec[0] = 42;
    return 0;
}