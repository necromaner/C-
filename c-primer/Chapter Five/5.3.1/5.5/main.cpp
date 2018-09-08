//5.5：写一段自己的程序，使用ifelse语句实现把数字转换成字母的要求。

#include <iostream>
#include<vector>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    const vector<string> scores = {"F","D","C","B","A","A++"};
    string b;
    int i;
    cout<<"enter number(1 to 100):";
    cin>>i;
    if(i<60)
        b=scores[0];
    else if(i>100)
        b={"error"};
    else
        b=scores[(i-50)/10];

    cout<<"level is "<<b<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
