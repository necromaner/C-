//
// Created by necromaner on 2018/12/10.
//

#ifndef CLIENT_TEST_H
#define CLIENT_TEST_H
//测试
#define private public  // hack complier
#define protected public
#include "../APP_dev/APP_dev.h"
#include "../refactoring/Refactoring.h"
#undef private
#undef protected
//测试
#include <cstring>
#include <gtest/gtest.h>

#define CHONG 34
#define FANG  622
#define P_C_100 "CHONG_100"
#define P_C_80 "CHONG_80"
#define P_C_60 "CHONG_60"
#define P_C_40 "CHONG_40"
#define P_C_20 "CHONG_20"

#define P_F_100 "FANG_100"
#define P_F_80 "FANG_80"
#define P_F_60 "FANG_60"
#define P_F_40 "FANG_40"
#define P_F_20 "FANG_20"
#define P_F_10 "FANG_10"
#define P_0 "ZERO"
#define P_ERROR "ERROR"

#define C5 3600
#define C4_1 3550
#define C4 3500
#define C3_1 3400
#define C3 3300
#define C2_1 3250
#define C2 3200
#define C1_1 3100
#define C1 3000

#define F5 3600
#define F4_1 3550
#define F4 3500
#define F3_1 3400
#define F3 3300
#define F2_1 3250
#define F2 3200
#define F1_1 3100
#define F1 3000


class Test {
public:
    Test();
    virtual ~Test();
    int test(int argc, char ** argv);
};


#endif //CLIENT_TEST_H
