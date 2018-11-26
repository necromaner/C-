#include <gtest/gtest.h>
#include "OutPut/Output.h"
#include "classDemo/classDemo.h"
#include "inheritance/inheritance.h"
#include "operator/operator.h"
#include "learn.h"
TEST(testCase, test0){
    T1 t1;
    EXPECT_EQ(1, t1.t1_1());
}



int main(int argc, char ** argv) {
//    Circle circle(3);
//    outPut(circle.Area());
//    Cylindrical cylindrical;
//    outPut(cylindrical.Area());
//    outPut(cylindrical.Volume());
//    Cone cone(1,1);
//    outPut(cone.Area());
//    outPut(cone.Volume());
//
//
//
//    Time time1(10, 1);
//    time1.show();
//
//    A *ab=new B;
//    ab->out1();
//    ab->out2();
//    ab->out3();
//    B *bb=new B;
//    bb->out1();
//    bb->out2();
//    bb->out3();
//
//    delete ab;
//    delete bb;
//    int i=0;
//    TrafficLight trafficLight=RED;
//    while (i<5) {
//        if (trafficLight == RED) {
//            printf("stop\n");
//        } else if (trafficLight == YELLOR) {
//            printf("prepare\n");
//        } else if (trafficLight == GREEN) {
//            printf("go\n");
//        } else
//            exit(0);
//        i++;
//        if (trafficLight == GREEN)
//            trafficLight = (enum TrafficLight) 0;
//        else
//            trafficLight = (enum TrafficLight) (trafficLight + 1);
//    }
//    int a,d; int &b=a;int *c;
//    c=&a;
//    a=10;
//    printf("b=%d\n",b);
//    printf("c=%d\n",*c);
//    b=100;
//    printf("a=%d\n",a);
//    printf("c=%d\n",*c);
//    d=9;
//    c=&d;
//    printf("c=%d\n",*c);

//    Time time2(10);
//    time2.reset(10);
//    time2.show();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}
