//3.16：编写一段程序，把练习3.13中vector对象的容量和具体内容输出出来。检验你之前的回答是否正确，如果不对，回过头重新学习3.3.1节（第97页）直到弄明白错在何处为止。
/*3.13：下列的vector对象各包含多少个元素？这些元素的值分别是多少？

(a) vector<int> v1;     (b) vector<int> v2(10);

(c) vector<int> v3(10, 42);  (d) vector<int> v4{10};

(e) vector<int> v5{10, 42};  (f) vector<string> v6{10};

(g) vector<string> v7{10, "hi"};
 */

#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    vector<int> v1;//空
    vector<int> v2(10);//10个元素，值都为0
    vector<int> v3(10, 42);//10个元素，值都为42
    vector<int> v4{10};//一个元素，值为10
    vector<int> v5{10, 42};//两个元素，值为10和42
    vector<string> v6{10};//10个默认初始化
    vector<string> v7{10, "hi"};//10个值为 hi
    cout<<"v1 = ";
    for(auto i:v1)
        cout<<i<<" ";
    cout<<endl<<"v2 = ";
    for(auto i:v2)
        cout<<i<<" ";
    cout<<endl<<"v3 = ";
    for(auto i:v3)
        cout<<i<<" ";
    cout<<endl<<"v4 = ";
    for(auto i:v4)
        cout<<i<<" ";
    cout<<endl<<"v5 = ";
    for(auto i:v5)
        cout<<i<<" ";
    cout<<endl<<"v6 = ";
    for(auto i:v6)
        cout<<i<<" ";
    cout<<endl<<"v7 = ";
    for(auto i:v7)
        cout<<i<<" ";
    return 0;
}