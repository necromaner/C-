//6.28：在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型。

//const string
#include <iostream>
#include <initializer_list>
using namespace std;

void error_msg(ErrCode e,initializer_list<string> il) {
    cout << e.msg() << ": ";
    for (const auto &elem:il)
        cout << elem << " ";
    cout << endl;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}