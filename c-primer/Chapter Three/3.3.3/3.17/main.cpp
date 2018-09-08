//3.17 从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改写为大写形式。输出改变后的结果，每个词占一行。

#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    string aa;
    vector<string> bb;
    cout<<"Enter:";
    while(cin>>aa)
    {
        for (int i = 0; i <aa.size(); ++i) {
            aa[i]=toupper(aa[i]);
        }
        bb.push_back(aa);
        cout<<"Enter:";
    }
    for (int j = 0; j < bb.size(); ++j) {
        cout<<"result : "<<bb[j]<<endl;
    }
    return 0;
}
