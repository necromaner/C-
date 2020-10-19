//
// Created by necromaner on 2020/7/22.
//

#ifndef LEETCODE2_TEST_H
#define LEETCODE2_TEST_H


#include "../Leetcode/leetcode.h"
#include "../JianZhiOffer/JianZhiOffer.h"
#include "../Tencent/Tencent.h"
#include "../Other/MyStack.h"
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


#endif //LEETCODE2_TEST_H
