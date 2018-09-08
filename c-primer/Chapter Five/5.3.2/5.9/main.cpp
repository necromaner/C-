//5.9：编写一段程序，使用一系列if语句统计从cin读入的文本中有多少个元音字母。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
int main() {
    unsigned int aa=0,ee=0,ii=0,oo=0,uu=0;
    cout<<"enter :";
    /*
    char i;             //初版
    while(cin>>i) {
        if (i == 'a')
            ++aa;
        if (i == 'e')
            ++ee;
        if (i == 'i')
            ++ii;
        if (i == 'o')
            ++oo;
        if (i == 'u')
            ++uu;
    }
     */

    string i;               //2.1版
    getline(cin,i);
    for (auto j=i.begin();j!=i.end()+1;++j) {
        switch (*j) {
            case 'a':
                ++aa;
                break;
            case 'e':
                ++ee;
                break;
            case 'i':
                ++ii;
                break;
            case 'o':
                ++oo;
                break;
            case 'u':
                ++uu;
                break;
        }
    }

    int sum=aa+ee+ii+oo+uu;
    
    cout<<"a = "<<aa<<endl;
    cout<<"e = "<<ee<<endl;
    cout<<"i = "<<ii<<endl;
    cout<<"o = "<<oo<<endl;
    cout<<"u = "<<uu<<endl;
    cout<<"sum = "<<sum<<endl;
    return 0;
}