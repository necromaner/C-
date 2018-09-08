//7.25：Screen能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能，为什么？

//不能，在这个里Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}，contents是string类型，字符无法用来赋值

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