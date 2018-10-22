#include "udp/UdpClient.h"

#include <iostream>
using namespace std;
int main() {
    UdpClient udpClient;
    cout<<udpClient.Message("send")<<endl;
    return 0;
}