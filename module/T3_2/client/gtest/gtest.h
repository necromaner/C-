//
// Created by necromaner on 2018/12/8.
//

#ifndef CLIENT_GTEST_H
#define CLIENT_GTEST_H
#include <gtest/gtest.h>
#include "../udp/UdpClient.h"

class gtest {
public:
    gtest();
    ~gtest();
    int test(int argc, char ** argv);
};


#endif //CLIENT_GTEST_H
