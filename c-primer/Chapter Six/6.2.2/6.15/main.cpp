//6.15：说明find_char函数中的三个形参为什么是现在的类型，特别说明为什么S是常量引用而occurs是普通引用？为什么s和occurs是引用类型而c不是？如果令s是普通引用会发生什么情况？如果令occurs是常量引用会发生什么情况？

//字符串s的长度固定，且s本身不允许被修改，所以s是常量引用
//occurs值要改变，所以occurs是普通引用
//c值不用改变，不需要传出，不需要引用
#include <iostream>
using namespace std;

string::size_type find_char(const string &s,char c,string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}
string::size_type find_char1(string &s,char c,string::size_type &occurs) {//s不是常量引用，s值会在后面改变
    s="oo";
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}
/*
string::size_type find_char2(const string &s,char c,const string::size_type &occurs) {//occurs是常量引用，在后面就不能统计次数，因为不能改变值大小
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}*/
int main() {
    string s = "asdooasdasdooasdoaosd";
    string s1=s;
    string::size_type crt;
    string::size_type crt1;
    auto index = find_char(s, 'o', crt);
    auto index1 = find_char1(s1, 'o', crt1);
    cout << s << " have " << crt << " o "<<endl;
    cout << s1 << " have " << crt1 << " o "<<endl;
    return 0;
}