//7.24：给你的Screen类添加三个构造函数：一个默认的构造函数；另一个构造函数接受宽和高的值，然后将contents初始化成给定数量的空白；第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容。

#include <iostream>
#include <string>
using namespace std;

class Screen{
public:
    typedef string::size_type pos;
    Screen()= default;  //默认构造函数
    Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){}//另一个构造函数
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}//第三个构造函数
    char get() const{ return contents[cursor];}
    inline char get(pos ht,pos wd) const;
    Screen &move(pos r,pos c);
private:
    pos cursor=0;
    pos height=0,width=0;
    string contents;
};
inline
Screen &Screen::move(pos r, pos c) {
    pos row=r*width;
    cursor=row+c;
    return *this;
}
char Screen::get(pos r, pos c) const {
    pos row=r*width;
    return contents[row+c];
}
int main()
{
    Screen s1(2,3,'F');
    cout << s1.get(1,1) << endl;
    Screen s2(2,3);
    cout << s2.get(1,1) << endl;
    return 0;
}