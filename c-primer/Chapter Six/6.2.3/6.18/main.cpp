/*6.18：为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。
（a） 名为compare的函数，返回bool值，两个参数都是matrix类的引用。
（b） 名为change_val的函数，返回vector的迭代器，有两个参数：一个是int，另一个是vector的迭代器。
 */

#include <iostream>
#include <vector>

using namespace std;

bool compare(const matrix &,const matrix &);//没有matrix类
vector<int>::iterator change_val(int, vector<int>::iterator);//iterator迭代器
//

int main() {
    return 0;
}