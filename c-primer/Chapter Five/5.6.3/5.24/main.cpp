//5.24：修改你的程序，使得当第二个数是0时抛出异常。先不要设定catch子句，运行程序并真的为除数输入0，看看会发生什么？
//5.23：编写一段程序，从标准输入读取两个整数，输出第一个整数除以第二个整数的结果。

//输出Process finished with exit code 8
#include <iostream>
using namespace std;

int main() {
    int aa, bb;
    cout << "Enter:";
    cin >> aa;
    cout << "Enter:";
    cin >> bb;
    double cc;
    cc = 1.0 * aa / bb;
    if (bb == 0)
        throw runtime_error("bb don't zero!");
    else
        cout << "aa + bb = " << cc << endl;
    return 0;
}