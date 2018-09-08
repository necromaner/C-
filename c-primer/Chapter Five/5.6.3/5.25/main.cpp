//5.25：修改上一题的程序，使用try语块去捕获异常。Catch子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行try语块的内容。
//5.24：修改你的程序，使得当第二个数是0时抛出异常。先不要设定catch子句，运行程序并真的为除数输入0，看看会发生什么？
//5.23：编写一段程序，从标准输入读取两个整数，输出第一个整数除以第二个整数的结果。

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int aa, bb;
    cout << "Enter:";
    double cc;
    cc = 1.0 * aa / bb;
    while (cin >> aa >> bb) {
        double cc;
        cc = 1.0 * aa / bb;
        try {
            if (bb == 0)
                throw runtime_error("bb don't zero!");
            else
                cout << "aa + bb = " << cc << endl;
        } catch (runtime_error err) {
            cout << err.what() << "\nTry Again? Enter Y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
    return 0;
}
