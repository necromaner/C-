#include "udp/UdpClient.h"

#include <iostream>
using namespace std;
int main() {
    UdpClient udp;
    udp.setFile("/Users/necromaner/test/send/","send.txt");
    udp.Information();
    udp.show();
    udp.readFile(0);
    for (int i = 0; i < 6; ++i) {
        udp.show(udp.sendFile(i));
    }
    return 0;
}