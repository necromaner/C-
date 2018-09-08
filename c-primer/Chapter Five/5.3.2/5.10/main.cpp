//5.10：我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写字母形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，也统计大写形式，也就是说，新程序遇到‘a’和‘A’都应该递增aCnt的值，以此类推。

#include <iostream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    unsigned int aa = 0, ee = 0, ii = 0, oo = 0, uu = 0;
    cout << "enter :";
    /*char i;               //初版
    while (cin >> i) {
        switch (i) {
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
        }
    }*/

    string i;           //2.1版
    getline(cin,i);
    for (auto j=i.begin();j!=i.end()+1;++j) {
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
        }
    }

    int sum = aa + ee + ii + oo + uu;

    cout << "a = " << aa << endl;
    cout << "e = " << ee << endl;
    cout << "i = " << ii << endl;
    cout << "o = " << oo << endl;
    cout << "u = " << uu << endl;
    cout << "sum = " << sum << endl;
}