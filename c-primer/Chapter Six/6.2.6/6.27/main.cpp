//6.27：编写一个函数，它的参数是initializer_list <int> 类型的对象，函数的功能是计算计算列表中所有元素的和。

#include <iostream>
#include <initializer_list>

using namespace std;

int add(initializer_list<int> aa) {
    int cc = 0;
    for (auto beg = aa.begin(); beg != aa.end(); ++beg) {
        cc += *beg;
    }
    return cc;
}
int main() {
    initializer_list<int> bb{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << add(bb);
    return 0;
}