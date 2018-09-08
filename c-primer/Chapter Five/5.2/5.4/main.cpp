/*5.4：说明下列例子的含义，如果存在问题，试着修改它。
(a）while (string::iterator iter != s.end() ) {/*…* /}   //迭代器遍历

(b)while (bool status = find (word)) {/ *…* /}      //找到word这个词，进行条件判断
        if (!status) {/ ** /}           //if作用域在while外面
*/

#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main() {
    while (bool status = find (word))// {/*…*/}
        if (!status) {/**/}
    return 0;
}