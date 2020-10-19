//
// Created by necromaner on 2018/12/8.
//

#ifndef SERVER_GTEST_H
#define SERVER_GTEST_H

#include <gtest/gtest.h>
#include "../udp/UdpServer.h"
class gtest {
public:
    gtest();
    ~gtest();
    int test(int argc, char ** argv);
};


#endif //SERVER_GTEST_H
