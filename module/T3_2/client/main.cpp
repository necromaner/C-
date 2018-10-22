#include "udp/UdpClient.h"

#include <iostream>
using namespace std;
int main() {
    UdpClient udp;
    udp.Information("/Users/necromaner/test/send/","4.zip");
    udp.show();
    return 0;
}