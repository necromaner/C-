#include "udp/UdpServer.h"
#include <iostream>
using namespace std;
int main() {
    UdpServer udpServer;
    cout<<udpServer.Message()<<endl;
    return 0;
}