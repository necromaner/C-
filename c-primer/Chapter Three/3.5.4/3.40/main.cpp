#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    const char aa[]="Hello";
    const char bb[]="World";
    char cc[]=" ";
    //cout<<cc<<endl;
    strcpy(cc,aa);
    //cout<<cc<<endl;
    strcat(cc," ");
    //cout<<cc<<endl;
    strcat(cc,bb);
    cout<<cc<<endl;
    return 0;
}