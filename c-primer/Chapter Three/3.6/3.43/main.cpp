/*3.43 编写3个不同版本的程序，令其均能输出ia的元素。
版本1 使用范围for语句管理迭代过程，
版本2 和版本3 都使用普遍版本的for语句，
其中版本2 要求用下标运算符，版本3要求用指针，此外，在所有3个版本的程序中都要直接写出数据类型，而不能用类型别名，auto 关键字或decltype关键字。
*/
#include <iostream>
#include<vector>
#include <cstring>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    int ia[4][3]={1,2,3,4,5,6,7,8,9,0,11,12};
    cout<<"1."<<endl;
    for(int &m:ia) {
        for (int &n:m)
            cout << n << " ";
        cout << endl;
    }
    cout<<"2."<<endl;
    for(int m=0;m!=4;++m){
        for(int n=0;n!=3;++n)
            cout << ia[m][n] << " ";
        cout << endl;
    }
    cout<<"3."<<endl;
    for(int(*m)[3]=ia;m!=ia+4;++m)
    {
        for(int*n=*m;n!=*m+3;++n)
            cout << *n << " ";
        cout << endl;
    }
    return 0;
}