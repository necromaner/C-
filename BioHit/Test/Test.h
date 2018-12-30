//
// Created by necromaner on 2018/12/10.
//

#ifndef CLIENT_TEST_H
#define CLIENT_TEST_H
//测试
#define private public  // hack complier
#define protected public
#include "../APP_dev/APP_dev.h"
#undef private
#undef protected
//测试
#include <cstring>
#include <gtest/gtest.h>

#define CHONG 3200
#define FANG  3000

#define C5 3200
#define C4 3150
#define C3 3070
#define C2 3000
#define C1 2900

#define F5 3500
#define F4 3400
#define F3 3340
#define F2 3300
#define F1 3200

class Test {
public:
    Test();
    virtual ~Test();
    int test(int argc, char ** argv);
};


#endif //CLIENT_TEST_H
