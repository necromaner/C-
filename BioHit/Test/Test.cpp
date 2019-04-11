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
string getPower(APP_dev app_dev){
    int x=app_dev.getYx_power();
    switch(x){
        case 0:
            return P_0;
        case 1:
            return P_F_10;
        case 2:
            return P_F_20;
        case 3:
            return P_F_40;
        case 4:
            return P_F_60;
        case 5:
            return P_F_80;
        case 6:
            return P_F_100;
        case 7:
            return P_C_20;
        case 8:
            return P_C_40;
        case 9:
            return P_C_60;
        case 10:
            return P_C_80;
        case 11:
            return P_C_100;
        default:
            return P_ERROR;

    }
}
TEST(APP_dev,power_average_MIN_MAX){
    APP_dev app_dev;
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(1));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(2));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(3));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(4));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(5));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(6));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(7));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(8));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(9));
    EXPECT_EQ(5.5,app_dev.power_average_MIN_MAX(10));

    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(10));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(20));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(30));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(40));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(50));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(60));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(70));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(80));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(90));
    EXPECT_EQ(55,app_dev.power_average_MIN_MAX(100));

    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(10));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(20));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(30));

    EXPECT_EQ(-1,app_dev.power_average_MIN_MAX(0))<<"重置";
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(10));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(20));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(30));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(40));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(50));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(60));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(70));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(80));
    EXPECT_EQ(0,app_dev.power_average_MIN_MAX(90));
    EXPECT_EQ(55,app_dev.power_average_MIN_MAX(100));
}
TEST(APP_dev,power_State){
    APP_dev app_dev;
    int dy=C5;//电量
    int zt=CHONG;//充放电状态
    app_dev.setTest1(zt,dy);
    EXPECT_EQ(P_0,getPower(app_dev))<<"初始化";

    EXPECT_EQ(ZT1,app_dev.power_State())<<"第一次1";
    EXPECT_EQ(P_C_20,getPower(app_dev))<<"第一次2";

    EXPECT_EQ(ZT3,app_dev.power_State())<<"状态不变1";
    EXPECT_EQ(P_C_20,getPower(app_dev))<<"状态不变2";
    zt=FANG;//充放电状态
    app_dev.setTest1(zt,dy);
    EXPECT_EQ(ZT0,app_dev.power_State())<<"状态改变1";
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"状态改变2";

    EXPECT_EQ(ZT4,app_dev.power_State())<<"状态不变1";
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"状态不变2";

    EXPECT_EQ(ZT4,app_dev.power_State())<<"状态不变1";
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"状态不变2";
    EXPECT_EQ(ZT4,app_dev.power_State())<<"状态不变1";
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"状态不变2";
    EXPECT_EQ(ZT4,app_dev.power_State())<<"状态不变1";
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"状态不变2";

    zt=CHONG;//充放电状态
    app_dev.setTest1(zt,dy);
    EXPECT_EQ(ZT0,app_dev.power_State())<<"状态改变1";
    EXPECT_EQ(P_C_20,getPower(app_dev))<<"状态改变2";

    EXPECT_EQ(ZT3,app_dev.power_State())<<"状态不变1";
    EXPECT_EQ(P_C_20,getPower(app_dev))<<"状态不变2";
    EXPECT_EQ(ZT3,app_dev.power_State())<<"状态不变1";
    EXPECT_EQ(P_C_20,getPower(app_dev))<<"状态不变2";
    EXPECT_EQ(ZT3,app_dev.power_State())<<"状态不变1";
    EXPECT_EQ(P_C_20,getPower(app_dev))<<"状态不变2";
    EXPECT_EQ(ZT3,app_dev.power_State())<<"状态不变1";
    EXPECT_EQ(P_C_20,getPower(app_dev))<<"状态不变2";


    zt=FANG;//充放电状态
    app_dev.setTest1(zt,dy);
    EXPECT_EQ(ZT0,app_dev.power_State())<<"状态改变1";
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"状态改变2";
    EXPECT_EQ(DISCHARGE_10,app_dev.setYx_power(1))<<"状态改变2";


    EXPECT_EQ(ZT4,app_dev.power_State())<<"状态不变1";
    EXPECT_EQ(P_F_10,getPower(app_dev))<<"状态不变2";
    EXPECT_EQ(ZT4,app_dev.power_State())<<"状态不变1";
    EXPECT_EQ(P_F_10,getPower(app_dev))<<"状态不变2";


    zt=CHONG;//充放电状态
    app_dev.setTest1(zt,dy);
    EXPECT_EQ(ZT0,app_dev.power_State())<<"状态改变1";
    EXPECT_EQ(P_C_20,getPower(app_dev))<<"状态改变2";

}

TEST(APP_dev,power_Electricity_chong){
    APP_dev app_dev;
    int dy=C1;//电量
    int zt=CHONG;//充放电状态
    app_dev.setTest1(zt,dy);
    EXPECT_EQ(P_0,getPower(app_dev))<<"初始化";
////----------------------7-> 7 初始化
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_C_20,getPower(app_dev))<<"计算";
////----------------------7->11>> 8   充上升
    dy=C5;//电量
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_C_20,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_C_40,getPower(app_dev))<<"计算";
////----------------------8->11>> 9   充上升
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_C_40,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_C_60,getPower(app_dev))<<"计算";
////----------------------9->11>>10   充上升
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_C_60,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_C_80,getPower(app_dev))<<"计算";
////----------------------10->11>>11   充上升
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_C_80,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_C_100,getPower(app_dev))<<"计算";
////----------------------11->11 无变化
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_C_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_C_100,getPower(app_dev))<<"计算";
////----------------------11->10>>11   充临界
    dy=C4_1;
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_C_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_C_100,getPower(app_dev))<<"计算";
////----------------------11->10>>10   充下降
    dy=C4;
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_C_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_C_80,getPower(app_dev))<<"计算";
////----------------------10-> 8>> 9   充下降
    dy=C2_1;
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_C_80,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_C_60,getPower(app_dev))<<"计算";
////----------------------9-> 8>> 9   充临界
    dy=C2_1;
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_C_60,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_C_60,getPower(app_dev))<<"计算";
////----------------------9-> 8>> 9   充临界
    dy=C2_1;
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_C_60,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_C_60,getPower(app_dev))<<"计算";
}
TEST(APP_dev,power_Electricity_fang){
    APP_dev app_dev;
    int zt=FANG;//充放电状态
    int dy=F5;//电量
    app_dev.setTest1(zt,dy);
    EXPECT_EQ(P_0,getPower(app_dev))<<"初始化";

////----------------------2-> 6>> 6   第一次
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_F_100,getPower(app_dev))<<"计算";
////----------------------6-> 6 无变化
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_F_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_F_100,getPower(app_dev))<<"计算";
////----------------------6-> 2>> 5   放下降
    dy=F1;//电量
    app_dev.setTest1(zt,dy);
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_F_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_F_80,getPower(app_dev))<<"计算";
////----------------------5-> 2>> 4   放下降
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_F_80,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_F_60,getPower(app_dev))<<"计算";
////----------------------4-> 2>> 3   放下降
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_F_60,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_F_40,getPower(app_dev))<<"计算";
////----------------------3-> 2>> 2   放下降
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_F_40,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"计算";
////----------------------2-> 2 无变化
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_F_20,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"计算";


////----------------------2-> 5>> 2   放上升
    dy=F4;//电量
    app_dev.setTest1(zt,dy);
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_Electricity(app_dev.power_State());
        EXPECT_EQ(P_F_20,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_Electricity(app_dev.power_State());
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"计算";
}

TEST(APP_dev,power_SelectDian_chong){
    APP_dev app_dev;
    int dy=C1;//电量
    int zt=CHONG;//充放电状态
    app_dev.setTest1(zt,dy);
    EXPECT_EQ(P_0,getPower(app_dev))<<"初始化";
////----------------------7-> 7 初始化
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_20,getPower(app_dev))<<"计算";
////----------------------7->11>> 8   充上升
    dy=C5;//电量
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_20,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_40,getPower(app_dev))<<"计算";
////----------------------8->11>> 9   充上升
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_40,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_60,getPower(app_dev))<<"计算";
////----------------------9->11>>10   充上升
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_60,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_80,getPower(app_dev))<<"计算";
////----------------------10->11>>11   充上升
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_80,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_100,getPower(app_dev))<<"计算";
////----------------------11->11 无变化
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_100,getPower(app_dev))<<"计算";
////----------------------11->10>>11   充临界
    dy=C4_1;
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_100,getPower(app_dev))<<"计算";
////----------------------11->10>>10   充下降
    dy=C4;
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_80,getPower(app_dev))<<"计算";
////----------------------10-> 8>> 9   充下降
    dy=C2_1;
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_80,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_60,getPower(app_dev))<<"计算";
////----------------------9-> 8>> 9   充临界
    dy=C2_1;
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_60,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_60,getPower(app_dev))<<"计算";
////----------------------9-> 8>> 9   充临界
    dy=C2_1;
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_60,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_60,getPower(app_dev))<<"计算";
}
TEST(APP_dev,power_SelectDian_fang){
    APP_dev app_dev;
    int zt=FANG;//充放电状态
    int dy=F5;//电量
    app_dev.setTest1(zt,dy);
    EXPECT_EQ(P_0,getPower(app_dev))<<"初始化";

////----------------------2-> 6>> 6   第一次
    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_100,getPower(app_dev))<<"计算";
////----------------------6-> 6 无变化
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_F_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_100,getPower(app_dev))<<"计算";
////----------------------6-> 2>> 5   放下降
    dy=F1;//电量
    app_dev.setTest1(zt,dy);
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_F_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_80,getPower(app_dev))<<"计算";
////----------------------5-> 2>> 4   放下降
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_F_80,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_60,getPower(app_dev))<<"计算";
////----------------------4-> 2>> 3   放下降
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_F_60,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_40,getPower(app_dev))<<"计算";
////----------------------3-> 2>> 2   放下降
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_F_40,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"计算";
////----------------------2-> 2 无变化
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_F_20,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"计算";


////----------------------2-> 5>> 2   放上升
    dy=F4;//电量
    app_dev.setTest1(zt,dy);
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_F_20,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_20,getPower(app_dev))<<"计算";
}
TEST(APP_dev,power_SelectDian_bian){
    APP_dev app_dev;
    int zt=FANG;//充放电状态
    int dy=F5;//电量
    app_dev.setTest1(zt,dy);
    EXPECT_EQ(P_0,getPower(app_dev))<<"初始化";

////----------------------[ 2-> 6>> 6]  { 0.00V}  FIRST
    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_100,getPower(app_dev))<<"计算";
////----------------------[ 6-> 6>> 6]  {11.60V}  NO CHANGE
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_F_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_100,getPower(app_dev))<<"计算";

////----------------------[ 6->  >>11]  {      }  RESET
    zt=CHONG;//充放电状态
    dy=C5;//电量
    app_dev.setTest1(zt,dy);

    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_100,getPower(app_dev))<<"计算";

////----------------------[11->11>>11]  {11.60V}  NO CHANGE
    zt=CHONG;//充放电状态
    dy=C5;//电量
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_100,getPower(app_dev))<<"计算";
////----------------------[11->10>>10]  {11.28V}  Charging DOWN
    zt=CHONG;//充放电状态
    dy=C4;//电量
    app_dev.setTest1(zt,dy);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_C_100,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_80,getPower(app_dev))<<"计算";
////----------------------[10->  >> 5]  {      }  RESET
    zt=FANG;//充放电状态
    dy=F3;//电量
    app_dev.setTest1(zt,dy);

    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_80,getPower(app_dev))<<"计算";
////----------------------[ 5-> 4>> 4]  {10.64V}  Discharge DOWN
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_F_80,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_F_60,getPower(app_dev))<<"计算";
////----------------------[ 4->  >> 9]  {      }  RESET
    for (int i = 0; i < POWER_SIZE-5; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_F_60,getPower(app_dev))<<i<<"次";
    }

    zt=CHONG;//充放电状态
    dy=C1;//电量
    app_dev.setTest1(zt,dy);
    app_dev.power_SelectDian();
    EXPECT_EQ(P_C_60,getPower(app_dev))<<"计算";
}

TEST(APP_dev,power_SelectDian_old){
    APP_dev app_dev;
    int zt=FANG;//充放电状态
    int dy=F5;//电量
    app_dev.setTest1(dy,zt);
    EXPECT_EQ(P_0,getPower(app_dev))<<"初始化";

////----------------------2-> 6>> 6   第一次
    app_dev.power_SelectDian();
    EXPECT_EQ(P_0,getPower(app_dev))<<"计算";
////----------------------6-> 6 无变化
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_0,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_0,getPower(app_dev))<<"计算";

////----------------------6-> 11  重置
    zt=CHONG;//充放电状态
    dy=C5;//电量
    app_dev.setTest1(dy,zt);

    app_dev.power_SelectDian();
    EXPECT_EQ(P_0,getPower(app_dev))<<"计算";

////----------------------11->11 无变化
    zt=CHONG;//充放电状态
    dy=C5;//电量
    app_dev.setTest1(dy,zt);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_0,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_0,getPower(app_dev))<<"计算";
////----------------------11->10>>10   充下降
    zt=CHONG;//充放电状态
    dy=C4;//电量
    app_dev.setTest1(dy,zt);

    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_0,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_0,getPower(app_dev))<<"计算";
////----------------------10->  5  重置
    zt=FANG;//充放电状态
    dy=F3;//电量
    app_dev.setTest1(dy,zt);

    app_dev.power_SelectDian();
    EXPECT_EQ(P_0,getPower(app_dev))<<"计算";
////----------------------5-> 4>> 4   放下降
    for (int i = 0; i < POWER_SIZE-1; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_0,getPower(app_dev))<<i<<"次";
    }
    app_dev.power_SelectDian();
    EXPECT_EQ(P_0,getPower(app_dev))<<"计算";
////----------------------4->  9  重置
    for (int i = 0; i < POWER_SIZE-5; ++i) {
        app_dev.power_SelectDian();
        EXPECT_EQ(P_0,getPower(app_dev))<<i<<"次";
    }

    zt=CHONG;//充放电状态
    dy=C1;//电量
    app_dev.setTest1(dy,zt);
    app_dev.power_SelectDian();
    EXPECT_EQ(P_0,getPower(app_dev))<<"计算";
}

TEST(APP_dev,setTest1_float){
    APP_dev app_dev;
    app_dev.setTest1(10.0,9.0);
}