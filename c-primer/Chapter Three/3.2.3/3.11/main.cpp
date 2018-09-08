/*3.11 下面的范围for语句合法吗，如果合法c的类型是什么
const string s ="Keep out!";
for(auto &c：s){}
 */
//c的类型是const &,不能修改c的值
#include <iostream>

int main() {
    const string s ="Keep out!";
    for(auto &c:s) {/*......*/}
    return 0;
}