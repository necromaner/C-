#include "udp/UdpServer.h"
#include <iostream>
#include <regex>

using namespace std;
int main() {
    UdpServer udp;
    udp.Information();
    udp.show();
    for (int i = 0; i < 6; ++i) {
        udp.show(udp.receiveFile());
    }
    udp.writeFile(0);
    
//    char* buf = new char[2];
//    char block[10]={0};
//    memcpy(buf, "请问", sizeof(buf));
//    for (int i = 3; i >=0; --i) {
//        memcpy(&block[2*i], "12", sizeof(buf));
//    }
//vector<char[2]> sss;
//    char ss[4][4];
//    memcpy(ss[2], "12", sizeof(buf));
//    memcpy(ss[1], "56", sizeof(buf));
//    memcpy(ss[0], "34", sizeof(buf));
//    for (int i = 0; i < 3; ++i) {
//        memcpy(&block[2*i], ss[i], 2);
//    }
//    printf("%s\n",block);
    return 0;
}