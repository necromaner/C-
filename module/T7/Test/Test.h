//
// Created by necromaner on 2018/12/13.
//

#ifndef T7_TEST_H
#define T7_TEST_H
#define private public
#define protected public


#include <gtest/gtest.h>
#undef private
#undef protected
class Test {
    Test();
    virtual ~Test();
    int test(int argc, char ** argv);
};


#endif //T7_TEST_H
