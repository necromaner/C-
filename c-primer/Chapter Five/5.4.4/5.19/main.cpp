//5.19：编写一段程序，使用do while循环重复地执行下述任务：首先提示用户输入两个sting对象，然后挑出较短的那个并输出它。


#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string aa, bb;
    cout << "Enter first:";
    cin >> aa;
    cout << "Enter second:：";
    cin >> bb;

    if (aa.size() > bb.size())//得到最短长度
        cout << "The short is : " << bb << endl;
    else
        cout << "The short is : " << aa << endl;


    return 0;
}