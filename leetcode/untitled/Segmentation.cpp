#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> SplitString1(const string& s)
{
    vector<string> v;
    const string c="/";
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
        
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
    return v;
}
char SplitString(char s[]) {
}

int main(){
    char buf[BUFSIZ];
    sprintf(buf, "a/b/c/d/e/f");
    char v[BUFSIZ];
//    v=SplitString(buf); //可按多个字符来分隔;
    printf("%d\n",v);
    //输出: a b c d e f
}