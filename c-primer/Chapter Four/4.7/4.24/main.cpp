//4.24：本节示例程序将成绩划分成high pass,pass 和fail三种，它的依据是条件运算符满足右结合率。假如条件运算符满足的是左结合律，求值过程将是怎样的？
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    int grade;
    cin>>grade;
    cout<<endl<<(grade>60)?(grade>90)?"high pass":"pass":"fail";
    return 0;
}