#include <iostream>
#include <gtest/gtest.h>
#include "Output.h"
using namespace std;

int main(int argc, char ** argv) {
    int arr[] = {6, 7, 8, 9 ,10,11};
    int* ptr = arr;
//    *(++ptr) = 123;
    int size=(int)sizeof(arr)/ (int)sizeof(arr[0]);
    printf("%d---%d---%d\n",(int)sizeof(arr), (int)sizeof(arr[0]),size);
    cout<<*ptr<<endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}