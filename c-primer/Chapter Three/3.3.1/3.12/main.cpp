/*3.12：下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果；对于不正确的，说明其错误的原因。

(a) vector<vector<int>> ivec;

(b) vector<string> svec = ivec;

(c) vector<string> svec(10, "null");
 */

#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    vector<vector<int>> ivec;
    vector<string> svec = ivec;//错误，ivec类型为int,而不是string
    vector<string> svec(10, "null");//错误，应该为花括号
    return 0;
}