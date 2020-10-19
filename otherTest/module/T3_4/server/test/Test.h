//
// Created by necromaner on 2018/12/10.
//

#ifndef CLIENT_TEST_H
#define CLIENT_TEST_H
//测试
#define private public  // hack complier
#define protected public
#include "../other/Other.h"
#include "../udp/Udp.h"
#include "../md5/md5.h"
#undef private
#undef protected
//测试

#include <gtest/gtest.h>
#define PATH "/Users/necromaner/test/gtest/"
class Test {
public:
    Test();
    virtual ~Test();
    int test(int argc, char ** argv);
};


#endif //CLIENT_TEST_H
