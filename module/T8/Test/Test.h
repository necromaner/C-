//
// Created by necromaner on 2019-01-27.
//

#ifndef T8_TEST_H
#define T8_TEST_H
//测试
#define private public  // hack complier
#define protected public
#include "../BinaryTree/BinaryTree.h"
#include "../BinaryTree/ColumnOutput/ColumnOutput.h"
#undef private
#undef protected
//测试
#include <gtest/gtest.h>

class Test {
public:
    Test();
    virtual ~Test();
    int test(int argc, char ** argv);
};


#endif //T8_TEST_H
