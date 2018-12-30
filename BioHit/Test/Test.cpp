#include "Test.h"
Test::Test() {
    printf("-------------test-begin------------\n");
}
Test::~Test() {
    printf("-------------test--end-------------\n");
}
int Test::test(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // 执行所有的 test case
}
TEST(APP_dev,GetMeanVal) {
    APP_dev app_dev;

    double Value_Value = 0;                       //电压平均值 充电状态时使用
    float Power[10];
    for (int i = 0; i < 10; ++i) {
        Power[i]=i;
    }
//    memset(Power, 0, 10);//memset将某一块内存中的内容全部设置为指定的值
    Power[0]=1;
    int xx=0;
//    for (auto num:Power) {
//        printf("--%f--\n",num);
//    }
    Value_Value = app_dev.GetMeanVal(Power, 10, 0.2);
    EXPECT_EQ(5,Value_Value);
}
TEST(APP_dev,Rank_Data){
    APP_dev app_dev;
    float Power[10];
    for (int i = 0; i < 10; ++i) {
        Power[i]=10-i;
    }
    Power[4]=100;
//    printf("begin:");
//    for (auto num:Power) {
//        printf("%f  ",num);
//    }
//    printf("\n");
//    app_dev.Rank_Data(Power,9);
//    printf("end  :");
//    for (auto num:Power) {
//        printf("%f  ",num);
//    }
//    printf("\n");
}

TEST(APP_dev,Timer_SelectDian){
    APP_dev app_dev;
//    充电
//    10.2	3164
//    10    3102
//    9.8	3040
//    9.5	2947
//    放电
//    11.06	3431
//    10.83	3360
//    10.72	3326
//    10.49	3254

//    充电
//    >3164 2.0
//3102-3164 1.8
//3040-3102 1.6
//2947-3040 1.4
//    <2947 1.2
//
//    放电
//    >3431 1.0
//3360-3431 0.8
//3326-3360 0.6
//3254-3326 0.4
//    <3254 0.2


//    printf("\n-----------------------状态改变-充电1.0--------------------\n");
//
//    printf("\n-----------------------连续充电-前充电-充电1.0--------------\n");
//    printf("\n-----------------------连续充电-前充电-不变1.0--------------\n");
//    printf("\n-----------------------连续充电-前充电-降低1.0--------------\n");
//
//    printf("\n-----------------------连续充电-前不变-充电1.0--------------\n");
//    printf("\n-----------------------连续充电-前不变-不变1.0--------------\n");
//    printf("\n-----------------------连续充电-前不变-降低1.0--------------\n");
//
//
//    printf("\n-----------------------状态改变-放电0.0--------------------\n");
//
//    printf("\n-----------------------连续放电-前放电-放电0.0--------------\n");
//    printf("\n-----------------------连续放电-前放电-不变0.0--------------\n");
//    printf("\n-----------------------连续放电-前放电-升高0.0--------------\n");
//
//    printf("\n-----------------------连续放电-前不变-放电0.0--------------\n");
//    printf("\n-----------------------连续放电-前不变-不变0.0--------------\n");
//    printf("\n-----------------------连续放电-前不变-升高0.0--------------\n");
}

TEST(APP_dev,Timer_SelectDian_chong){

    /*
     * 测试内容：
     * 1。电池连续充电
     *      0->20->20->40->60->80->100->100
     * 2。充电中检测到电池电量下降
     *      100->80->60->100
     */
    //仅充电
    APP_dev app_dev;
    printf("\n---------------------------状态改变-充电1.2--------------------\n");
    app_dev.setTest(CHONG,C1);
    EXPECT_EQ(0,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(CHONG,C1);
    EXPECT_EQ(1.2,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为1.2";

    printf("\n-----------------------连续充电-前不变-不变1.2--------------\n");
//    app_dev.setTest(CHONG,C1);
//    EXPECT_EQ(1.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C1);
    EXPECT_EQ(1.2,app_dev.getYx_power())<<"C1判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C1);
        EXPECT_EQ(1.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C1);
        EXPECT_EQ(1.2,app_dev.getYx_power())<<"C1判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C1);
    EXPECT_EQ(1.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C1);
    EXPECT_EQ(1.2,app_dev.getYx_power())<<"C1判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-充电1.4--------------\n");
//    app_dev.setTest(CHONG,C2);
//    EXPECT_EQ(1.4,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(1.2,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C2);
        EXPECT_EQ(1.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C2);
        EXPECT_EQ(1.2,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(1.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(1.4,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-9";


    printf("\n-----------------------连续充电-前充电-充电1.6--------------\n");
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(1.4,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(1.4,app_dev.getYx_power())<<"C3判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(1.4,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(1.4,app_dev.getYx_power())<<"C3判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(1.4,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C3判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前充电-充电1.8--------------\n");
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C4);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C4);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前充电-充电2.0--------------\n");
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(1.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(1.8,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前充电-不变2.0--------------\n");
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-不变2.0--------------\n");
//    app_dev.setTest(CHONG,C5);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-9";
    printf("\n-----------------------连续充电-前不变-降低1.8--------------\n");
//    app_dev.setTest(CHONG,C4);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C4);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C4);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-降低1.8--------------\n");
//    app_dev.setTest(CHONG,C4);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C4);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C4);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-降低1.6--------------\n");
//    app_dev.setTest(CHONG,C3);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-9";


    printf("\n-----------------------连续充电-前不变-不变2.0--------------\n");
//    app_dev.setTest(CHONG,C5);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-9";

    printf("\n\n");
}
TEST(APP_dev,Timer_SelectDian_chong80){

    /*
     * 测试内容：
     * 1。电池连续充电
     *      80->100
     * 2。充电中检测到电池电量下降
     *      100->80->60->40->20->40->100
     */
    //仅充电
    APP_dev app_dev;
    printf("\n-----------------------状态改变-充电1.8--------------------\n");
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(0,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为1.8";

    printf("\n-----------------------连续充电-前不变-充电2.0--------------\n");
//    app_dev.setTest(CHONG,C5);
//    EXPECT_EQ(1.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(1.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(1.8,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前充电-不变2.0--------------\n");
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-不变2.0--------------\n");
//    app_dev.setTest(CHONG,C5);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-9";
    printf("\n-----------------------连续充电-前不变-降低1.8--------------\n");
//    app_dev.setTest(CHONG,C4);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C4);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C4);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-降低1.8--------------\n");
//    app_dev.setTest(CHONG,C4);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C4);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C4);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-降低1.6--------------\n");
//    app_dev.setTest(CHONG,C3);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-降低1.4--------------\n");
//    app_dev.setTest(CHONG,C2);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C2);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C2);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-降低1.2--------------\n");
//    app_dev.setTest(CHONG,C1);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C1);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C1判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C1);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C1);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C1判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C1);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C1);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C1判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-降低1.4--------------\n");
//    app_dev.setTest(CHONG,C2);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C2);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C2);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-9";
    printf("\n-----------------------连续充电-前不变-降低1.6--------------\n");
//    app_dev.setTest(CHONG,C3);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C4判断连续放电状态，电量不变-9";


    printf("\n-----------------------连续充电-前不变-不变2.0--------------\n");
//    app_dev.setTest(CHONG,C5);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-9";

    printf("\n\n");
}
TEST(APP_dev,Timer_SelectDian_chong40_60){

    /*
     * 测试内容：
     * 1。电池连续充电
     *      40->60
     * 2。充电中检测到电池电量下降
     *      60->40->20->40->100
     */
    //仅充电
    APP_dev app_dev;
    printf("\n-----------------------状态改变-充电1.4--------------------\n");
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(0,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(1.4,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为1.2";

    printf("\n-----------------------连续充电-前不变-充电1.6--------------\n");
//    app_dev.setTest(CHONG,C3);
//    EXPECT_EQ(1.4,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(1.4,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(1.4,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(1.4,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(1.4,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前充电-降低1.4--------------\n");
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C2);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C2);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-降低1.2--------------\n");
//    app_dev.setTest(CHONG,C1);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C1);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C1判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C1);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C1);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"C1判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C1);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C1);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C1判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续充电-前不变-降低1.4--------------\n");
//    app_dev.setTest(CHONG,C2);
//    EXPECT_EQ(2.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C2);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C2);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C2);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C2判断连续放电状态，电量不变-9";
    printf("\n-----------------------连续充电-前不变-不变1.6--------------\n");
//    app_dev.setTest(CHONG,C3);
//    EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C3判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C3);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"C3判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C3判断连续放电状态，电量不变-9";


    printf("\n-----------------------连续充电-前不变-充电2.0--------------\n");
//    app_dev.setTest(CHONG,C5);
//    EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(1.6,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(1.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"C5判断连续放电状态，电量不变-9";

    printf("\n\n");
}

TEST(APP_dev,Timer_SelectDian_fang){
    /*
     * 测试内容：
     * 1。电池连续放电
     *      100->0
     * 2。放电中检测到电池电量上升
     *      20->40->60->20
     */
    APP_dev app_dev;

    printf("\n-----------------------状态改变-放电1.0--------------------\n");
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(0,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(1.0,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为1.0";

    printf("\n-----------------------连续放电-前不变-不变1.0--------------\n");
//    app_dev.setTest(FANG,F5);
//    EXPECT_EQ(1.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(1.0,app_dev.getYx_power())<<"F5判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F5);
        EXPECT_EQ(1.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F5);
        EXPECT_EQ(1.0,app_dev.getYx_power())<<"F5判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(1.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(1.0,app_dev.getYx_power())<<"F5判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续放电-前不变-放电0.8--------------\n");
//    app_dev.setTest(FANG,F4);
//    EXPECT_EQ(1.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F4);
    EXPECT_EQ(1.0,app_dev.getYx_power())<<"F4判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F4);
        EXPECT_EQ(1.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F4);
        EXPECT_EQ(1.0,app_dev.getYx_power())<<"F4判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F4);
    EXPECT_EQ(1.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F4);
    EXPECT_EQ(0.8,app_dev.getYx_power())<<"F4判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续放电-前放电-放电0.6--------------\n");
    app_dev.setTest(FANG,F3);
    EXPECT_EQ(0.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F3);
    EXPECT_EQ(0.8,app_dev.getYx_power())<<"F3判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F3);
        EXPECT_EQ(0.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F3);
        EXPECT_EQ(0.8,app_dev.getYx_power())<<"F3判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F3);
    EXPECT_EQ(0.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F3);
    EXPECT_EQ(0.6,app_dev.getYx_power())<<"F3判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续放电-前放电-放电0.4--------------\n");
    app_dev.setTest(FANG,F2);
    EXPECT_EQ(0.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F2);
    EXPECT_EQ(0.6,app_dev.getYx_power())<<"F2判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F2);
        EXPECT_EQ(0.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F2);
        EXPECT_EQ(0.6,app_dev.getYx_power())<<"F2判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F2);
    EXPECT_EQ(0.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F2);
    EXPECT_EQ(0.4,app_dev.getYx_power())<<"F2判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续放电-前放电-放电0.2--------------\n");
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.4,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.4,app_dev.getYx_power())<<"F1判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F1);
        EXPECT_EQ(0.4,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F1);
        EXPECT_EQ(0.4,app_dev.getYx_power())<<"F1判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.4,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"F1判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续放电-前放电-不变0.2--------------\n");
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"F1判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F1);
        EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F1);
        EXPECT_EQ(0.2,app_dev.getYx_power())<<"F1判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"F1判断连续放电状态，电量不变-9";


    printf("\n-----------------------连续放电-前不变-升高0.4--------------\n");
//    app_dev.setTest(FANG,F2);
//    EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F2);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"判断连续放电状态，电量不变-0   电量回落";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F2);
        EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F2);
        EXPECT_EQ(0.2,app_dev.getYx_power())<<"F2判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F2);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F2);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"F2判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续放电-前不变-升高0.6--------------\n");
//    app_dev.setTest(FANG,F3);
//    EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F3);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"判断连续放电状态，电量不变-0   电量回落";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F3);
        EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F3);
        EXPECT_EQ(0.2,app_dev.getYx_power())<<"F2判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F3);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F3);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"F2判断连续放电状态，电量不变-9";


    printf("\n-----------------------连续放电-前不变-不变0.2--------------\n");
//    app_dev.setTest(FANG,F1);
//    EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"判断连续放电状态，电量不变-0   电量恢复";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F1);
        EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F1);
        EXPECT_EQ(0.2,app_dev.getYx_power())<<"F1判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"F1判断连续放电状态，电量不变-9";

    printf("\n\n");
}
TEST(APP_dev,Timer_SelectDian_fang80_60){
    /*
     * 测试内容：
     * 1。电池连续放电
     *      80->60
     * 2。放电中检测到电池电量上升
     *      60->100->20
     */
    APP_dev app_dev;

    printf("\n-----------------------状态改变-放电0.8--------------------\n");
    app_dev.setTest(FANG,F4);
    EXPECT_EQ(0,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(FANG,F4);
    EXPECT_EQ(0.8,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为0.8";

    printf("\n-----------------------连续放电-前不变-放电0.6--------------\n");
//    app_dev.setTest(FANG,F3);
//    EXPECT_EQ(0.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F3);
    EXPECT_EQ(0.8,app_dev.getYx_power())<<"F4判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F3);
        EXPECT_EQ(0.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F3);
        EXPECT_EQ(0.8,app_dev.getYx_power())<<"F4判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F3);
    EXPECT_EQ(0.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F3);
    EXPECT_EQ(0.6,app_dev.getYx_power())<<"F4判断连续放电状态，电量不变-9";

    printf("\n-----------------------连续放电-前放电-升高1.0--------------\n");
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(0.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(0.6,app_dev.getYx_power())<<"判断连续放电状态，电量不变-0   电量回落";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F5);
        EXPECT_EQ(0.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F5);
        EXPECT_EQ(0.6,app_dev.getYx_power())<<"F2判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(0.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(0.6,app_dev.getYx_power())<<"F2判断连续放电状态，电量不变-9";


    printf("\n-----------------------连续放电-前不变-放电0.2--------------\n");
//    app_dev.setTest(FANG,F1);
//    EXPECT_EQ(0.2,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.6,app_dev.getYx_power())<<"判断连续放电状态，电量不变-0   电量恢复";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F1);
        EXPECT_EQ(0.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F1);
        EXPECT_EQ(0.6,app_dev.getYx_power())<<"F1判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.6,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F1);
    EXPECT_EQ(0.2,app_dev.getYx_power())<<"F1判断连续放电状态，电量不变-9";

    printf("\n\n");
}


TEST(APP_dev,Timer_SelectDian_bian) {
//充放电状态改变
/*
 * 测试内容：
 * 1。充放电状态改变，显示百分比不变
 *      充80->充100
 *      充100->放100
 *      放100->放80
 *      放80->充80
 * 2。充放电状态改变，显示百分比变化
 *      充80->放100
 *      放80->充60
 *      充80->放60
 *      放80->充100
 */
    APP_dev app_dev;
    printf("\n-----------------------状态改变-充电1.8--------------------\n");
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(0,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(CHONG,F5);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为1.0";

    printf("\n-----------------------连续充电-前不变-充电2.0--------------\n");
//    app_dev.setTest(CHONG,C5);
//    EXPECT_EQ(1.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"判断连续放电状态";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(1.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(CHONG,C5);
        EXPECT_EQ(1.8,app_dev.getYx_power())<<"判断连续放电状态";
    }
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(2.0,app_dev.getYx_power())<<"判断连续放电状态";
    printf("\n-----------------------状态改变-放电1.0--------------------\n");
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(2,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(1.0,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为1.0";

    printf("\n-----------------------连续放电-前不变-放电0.8--------------\n");
//    app_dev.setTest(FANG,F4);
//    EXPECT_EQ(1.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F4);
    EXPECT_EQ(1.0,app_dev.getYx_power())<<"F4判断连续放电状态，电量不变-0";
    for (int i = 1; i < 9; ++i) {
        app_dev.setTest(FANG,F4);
        EXPECT_EQ(1.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
        app_dev.setTest(FANG,F4);
        EXPECT_EQ(1.0,app_dev.getYx_power())<<"F4判断连续放电状态，电量不变-"<<i;
    }
    app_dev.setTest(FANG,F4);
    EXPECT_EQ(1.0,app_dev.getYx_power())<<"读取通道1，获取充放电状态";
    app_dev.setTest(FANG,F4);
    EXPECT_EQ(0.8,app_dev.getYx_power())<<"F4判断连续放电状态，电量不变-9";

    printf("\n-----------------------状态改变-充电1.8--------------------\n");
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(0.8,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(CHONG,C4);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为1.0";


    printf("\n-----------------------状态改变-放电1.0--------------------\n");
//    app_dev.setTest(FANG,F5);
//    EXPECT_EQ(1.8,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(FANG,F5);
    EXPECT_EQ(0.8,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为0.8";

    printf("\n-----------------------状态改变-充电1.6--------------------\n");
//    app_dev.setTest(CHONG,C3);
//    EXPECT_EQ(0.8,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(CHONG,C3);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为1.8";

    printf("\n-----------------------状态改变-放电0.8--------------------\n");
//    app_dev.setTest(FANG,F3);
//    EXPECT_EQ(1.8,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(FANG,F3);
    EXPECT_EQ(0.8,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为0.8";

    printf("\n-----------------------状态改变-充电2.0--------------------\n");
//    app_dev.setTest(CHONG,C5);
//    EXPECT_EQ(0.8,app_dev.getYx_power())<<"第一次为通道1，获取通道1值";
    app_dev.setTest(CHONG,C5);
    EXPECT_EQ(1.8,app_dev.getYx_power())<<"第二次为判断充放电状态,电量为1.8";



}