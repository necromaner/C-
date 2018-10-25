#include "udp/UdpServer.h"
#include <iostream>
#include <regex>
#include <vector>
using namespace std;
int main() {
    UdpServer udp;
    udp.Information();
    udp.show();
    udp.manage(0);

    printf("输出：\n%s\n",udp.getBlock());
    udp.writeFile(0);
    

    return 0;
}