//3.14 编写一段程序，用cin读入一组整数并把它们存入一个vector对象。

#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    int aa;
    vector<int>bb;
    while(cin>>aa){
        bb.push_back(aa);
    }
    return 0;
}