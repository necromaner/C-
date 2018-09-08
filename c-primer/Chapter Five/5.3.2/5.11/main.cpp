//5.11：修改统计元音字母的程序，使其也能统计空格，制表符和换行符的数量。

#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    unsigned int aa = 0, ee = 0, ii = 0, oo = 0, uu = 0,space=0,tableSign=0,enter=0,other=0;
    cout << "enter :";
    string i;
    //cin>>i;           //不能输入空格，制表符和换行符
    getline(cin,i);     //不能输入制表符和换行符
    cout << endl;//以上打印文件里面的字符

    cout<<"input "<<i<<endl;
    for (auto j=i.begin();j!=i.end()+2;++j) {
        switch (*j) {
            case 'a':
            case 'A':
                ++aa;
                break;
            case 'e':
            case 'E':
                ++ee;
                break;
            case 'i':
            case 'I':
                ++ii;
                break;
            case 'o':
            case 'O':
                ++oo;
                break;
            case 'u':
            case 'U':
                ++uu;
                break;
            case ' ':
                ++space;
                break;
            case '\t':
                ++tableSign;
                break;
            case '\n':
                ++enter;
                break;
            default:
                ++other;
                break;
        }
    }

    int sum = aa + ee + ii + oo + uu;

    cout << "a = " << aa << endl;
    cout << "e = " << ee << endl;
    cout << "i = " << ii << endl;
    cout << "o = " << oo << endl;
    cout << "u = " << uu << endl;
    cout << "space = " << space << endl;
    cout << "tableSign = " << tableSign << endl;
    cout << "enter = " << enter << endl;
    cout << "sum = " << sum << endl;
}