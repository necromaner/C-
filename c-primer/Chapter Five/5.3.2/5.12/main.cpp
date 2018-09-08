//5.12：修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列的数量：ff，fl和fi。

#include <iostream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    unsigned int ff = 0, fl = 0, fi = 0;
    cout << "enter :";
    string i;
    getline(cin, i);
    for (auto j = i.begin(); j != i.end() + 1; ++j) {
        if(*j='f'){
            switch (*(j+1)) {
                case 'f':
                    ++ff;
                    break;
                case 'l':
                    ++fl;
                    break;
                case 'i':
                    ++fi;
                    break;
            }

        }
    }


    cout << "ff = " << ff << endl;
    cout << "fl = " << fl << endl;
    cout << "fi = " << fi << endl;
}
