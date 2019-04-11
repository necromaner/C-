#include "APP_dev.h"
#define CMD_PORT_SELECTED 0x0C
#define CMD_BIT_SELECTED 0x0D
int AdcDev;
APP_dev::APP_dev()  {
    AdcDev=1;
    batteryStop=0;
    yx_power=0;
    test0=0;
    test1=0;
    isMotorStart= false;
    isPrinterRun= false;
    isDoorMove= false;
    sprintf(output,"");
}

////-------------------电池-----------------////
bool APP_dev::power_Stop() {
    static bool motorEnd = false;
    if (isMotorStart) {                                            //采集数据
        if (batteryStop > 0) {                                     //如果之前记录暂停时间
            batteryStop--;
        }
        motorEnd = true;
#ifdef TEST_POWER
        sprintf(output, "-|MotorSTOP  --- {     } [          ]  {      }  STOP\n");
#endif
        return true;
    } else if (motorEnd) {                                         //结束后再暂停一次
        if (batteryStop > 0) {
            batteryStop--;
        }
        motorEnd = false;
#ifdef TEST_POWER
        sprintf(output, "-|MotorSTART --- {     } [          ]  {      }  STOP\n");
#endif
        return true;
    }
    if (isPrinterRun || isDoorMove) {                              //电机正在运动时，停止采集电压
        if (batteryStop > 1) {
            batteryStop--;
#ifdef TEST_POWER
            sprintf(output, "-|OtherSTOP  --- {     } [          ]  {      }  STOP\n");
#endif
            return true;
        } else {                                                   //结束后再暂停一次
            batteryStop = 0;
            isDoorMove = false;
            isPrinterRun = false;
#ifdef TEST_POWER
            sprintf(output, "-|OtherSTART --- {     } [          ]  {      }  STOP\n");
#endif
            return true;
        }
    }
    return false;
}
int APP_dev::power_State() {                                       //0 退出循环 1 第一次充电 2 第一次放电 3充电 4放电
////----------------------初始化-----------------------////
    int ibuffer;
    double dValue1 = 0;                                            //1通道用于判断电池状态
    static int state = 0;                                          //充放状态 0初始值 1充电 2放电
////---------------------采集数据-----------------------////
#ifdef Clion
    int ret = 1;
    ibuffer = test0;                                               //test0:状态
    char Ada_Sta;
    if((float) ((ibuffer * 3.3) / 4095 * 4)<1)
        Ada_Sta=1;
    else
        Ada_Sta=0;
#else
    ioctl(AdcDev, CMD_BIT_SELECTED, 12);
    ioctl(AdcDev, CMD_PORT_SELECTED, 1);                           //设置通道1
    int ret = read(AdcDev, &ibuffer, sizeof(ibuffer));             //读ad转换后的数据
    int Ada_Sta=(int)GetPinState(1);                               //充放电判断 0放电 1充电
#endif
    if (ret > 0)
        dValue1 = (float) ((ibuffer * 3.3) / 4095 * 4);            //模数换算
    else
        return ZT0;
////-------------------第一次状态判断---------------------////
    if (state == ZT0) {                                            //第一次
        if (Ada_Sta == 1) {                                        //充电
            state = ZT1;
            yx_power = CHARGING_20;
#ifdef TEST_POWER
            sprintf(output1, "-|FIRST      -%1d- {%5.2f} [%2d", (int)Ada_Sta,dValue1,yx_power);
#endif
            return ZT1;
        } else if (Ada_Sta == 0&&dValue1<4) {                                  //放电
            state = ZT2;
            yx_power = DISCHARGE_20;
#ifdef TEST_POWER
            sprintf(output1, "-|FIRST      -%1d- {%5.2f} [%2d", (int)Ada_Sta,dValue1,yx_power);
#endif
            return ZT2;
        } else {                                                   //旧设备
////---------------------采集数据-----------------------////
            float dValue0 = 0;

#ifdef Clion
            int ret = 1;
            ibuffer = test1;                                     //test1:电量
#else
            ioctl(AdcDev, CMD_BIT_SELECTED, 12);
            ioctl(AdcDev, CMD_PORT_SELECTED, 0);                   //设置通道0
            int ret = read(AdcDev, &ibuffer, sizeof(ibuffer));     //读ad转换后的数据
#endif
            if (ret > 0) {
                dValue0 = (float) ((ibuffer * 3.3) / 4095 * 4);    //模数换算
            }
#ifdef TEST_POWER
            sprintf(output, "-|old equipment -%1d- {%5.2f}-{%5.2f}\n",(int)Ada_Sta, dValue1,dValue0);
#endif
            return ZTERROR1;
        }
    }
////---------------------状态判断-----------------------////
    if (state == ZT1 && Ada_Sta == 1) {                            //状态不变,充电
#ifdef TEST_POWER
        sprintf(output1, "-|CHARGING   -%1d- {%5.2f} [%2d", (int)Ada_Sta,dValue1,yx_power);
#endif
        return ZT3;
    } else if (state == ZT2 && Ada_Sta == 0) {                      //状态不变,放电
#ifdef TEST_POWER
        sprintf(output1, "-|DISCHARGE  -%1d- {%5.2f} [%2d", (int)Ada_Sta,dValue1,yx_power);
#endif
        return ZT4;
    } else {                                                       //状态改变
#ifdef TEST_POWER
        sprintf(output1, "-|CHANGE     -%1d- {%5.2f} [%2d", (int)Ada_Sta,dValue1,yx_power);
#endif
        if (Ada_Sta == 1) {                                        //充电
            state = ZT1;
            if (yx_power == DISCHARGE_10)                          //低电量
                yx_power = DISCHARGE_20;
            yx_power += (CHARGING_20 - DISCHARGE_20);
        } else if(Ada_Sta == 0){                                                   //放电
            state = ZT2;
            yx_power -= (CHARGING_20 - DISCHARGE_20);
        }else{
            yx_power=0;
        }
#ifdef TEST_POWER
        sprintf(output2, "->  >>%2d]", yx_power);
#endif
        return ZT0;
    }
}
float APP_dev::power_average_MIN_MAX(float x) {                    //-1 重置 0未满 other 10次平均值
    static float max = 0;
    static float min = 100;
    static int maxSize = 0;                                        //存储数目
    static float Power1[POWER_SIZE];
    if (x <= 0) {
#ifdef TEST_POWER
        sprintf(output3,"  {      }  RESET\n-----------------------------------------------\n");
#endif
        max = 0;
        min = 100;
        maxSize = 0;
        return -1;
    }
    if (POWER_SIZE < 3)
        return 0;
    if (maxSize < POWER_SIZE) {
        Power1[maxSize] = x;
        maxSize++;
    }
    if (maxSize == POWER_SIZE) {
        float sum = 0;
        maxSize = 0;
        for (int i = 0; i < POWER_SIZE; ++i) {
            if (Power1[i] > max)
                max = Power1[i];
            if (Power1[i] < min)
                min = Power1[i];
            sum += Power1[i];
        }
        sum = sum - max - min;
        max = 0;
        min = 100;
        return sum / (POWER_SIZE - 2);
    } else {
#ifdef TEST_POWER
        sprintf(output2,"        ]");
        sprintf(output3,"  {%5.2fV}  WAIT: %1d\n", x,maxSize);
#endif
        return 0;
    }
}
void APP_dev::power_Electricity(int state) {
////----------------------初始化-----------------------////
    int ibuffer;
    float value = 0;                                               //平均电压     <=0 error
    float dValue0 = 0;                                             //1通道模数转换 1通道用于判断电量范围
    int electricity = 0;                                           //0初始值 1 10电量 2 20电量 3 40电量 4 60电量 5 80电量 6 100电量
    int scope = 4;                                                 //临界范围
    bool border = false;                                           //是否在临界范围
////-------------------采集数据转换---------------------////
#ifdef Clion
    int ret = 1;
    ibuffer = test1;                                               //test1:电量
#else
    ioctl(AdcDev, CMD_BIT_SELECTED, 12);
    ioctl(AdcDev, CMD_PORT_SELECTED, 0);                           //设置通道0
    int ret = read(AdcDev, &ibuffer, sizeof(ibuffer));             //读ad转换后的数据
#endif
    if (ret > 0) {
        dValue0 = (float) ((ibuffer * 3.3) / 4095 * 4);            //模数换算
    } else {
        return;
    }
////--------------------获取平均电压-----------------------////
    if (state != ZT1 && state != ZT2) {                            //判断是否为第一次
        value = power_average_MIN_MAX(dValue0);                    //电压平均值
        if (value <= 0) {                                          //存储10组数据
            return;
        }
    } else {
        value = dValue0;
    }
////--------------------计算当前电量-----------------------////
    if (state == ZT3 || state == ZT1) {                            //充电状态
        if (value >= CHONG_4) {                                    //充电100
            electricity = CHARGING_100;
        } else if (value >= (CHONG_4 - (CHONG_4 - CHONG_3) / scope)) {//充电80-100边界
            border = true;
            electricity = CHARGING_80;
        } else if (value >= CHONG_3) {                             //充电80
            electricity = CHARGING_80;
        } else if (value >= (CHONG_3 - (CHONG_3 - CHONG_2) / scope)) {//充电60-80边界
            border = true;
            electricity = CHARGING_60;
        } else if (value >= CHONG_2) {                             //充电60
            electricity = CHARGING_60;
        } else if (value >= (CHONG_2 - (CHONG_2 - CHONG_1) / scope)) {//充电40-60边界
            border = true;
            electricity = CHARGING_40;
        } else if (value >= CHONG_1) {                             //充电40
            electricity = CHARGING_40;
        } else if (value >= (CHONG_1 - (CHONG_4 - CHONG_1) / (3 * scope))) {//充电20-40边界
            border = true;
            electricity = CHARGING_20;
        } else {                                                   //充电20
            electricity = CHARGING_20;
        }
    } else if (state == ZT4 || state == ZT2) {                     //放电状态
        if (value >= FANG_4) {                                     //放电100
            electricity = DISCHARGE_100;
        } else if (value >= FANG_3) {                              //放电80
            electricity = DISCHARGE_80;
        } else if (value >= FANG_2) {                              //放电60
            electricity = DISCHARGE_60;
        } else if (value >= FANG_1) {                              //放电40
            electricity = DISCHARGE_40;
        } else if (value >= FANG_0) {                              //放电20
            electricity = DISCHARGE_20;
        } else {                                                   //放电10
            electricity = DISCHARGE_10;
        }
    } else {
        return;
    }
#ifdef TEST_POWER
    sprintf(output2, "->%2d", electricity);
#endif
////--------------------计算显示电量-----------------------////
    if (electricity == yx_power) {                                 //当前电量与实际电量相同
#ifdef TEST_POWER
        sprintf(output3, ">>%2d]  {%5.2fV}  NO CHANGE\n-----------------------------------------------\n", yx_power, value);
#endif
    } else if (state == ZT3) {                                     //充电
        if (electricity > yx_power) {                              //电量上升
            yx_power++;
#ifdef TEST_POWER
            sprintf(output3, ">>%2d]  {%5.2fV}  Charging UP\n-----------------------------------------------\n", yx_power, value);
#endif
        } else {                                                   //电量下降
            if ((border && (yx_power - 1) == electricity)) {
#ifdef TEST_POWER
                sprintf(output3, ">>%2d]  {%5.2fV}  Charging EDGE\n-----------------------------------------------\n", yx_power,
                        value);
#endif
            } else {
                yx_power--;
#ifdef TEST_POWER
                sprintf(output3, ">>%2d]  {%5.2fV}  Charging DOWN\n-----------------------------------------------\n", yx_power,
                        value);
#endif
            }
        }
    } else if (state == ZT4) {                                     //放电
        if (electricity > yx_power) {                              //电量上升
#ifdef TEST_POWER
            sprintf(output3, ">>%2d]  {%5.2fV}  Discharge UP\n-----------------------------------------------\n", yx_power, value);
#endif
        } else {                                                   //电量下降
            yx_power--;
#ifdef TEST_POWER
            sprintf(output3, ">>%2d]  {%5.2fV}  Discharge DOWN\n-----------------------------------------------\n", yx_power, value);
#endif
        }
    } else {                                                       //第一次
        yx_power = electricity;
#ifdef TEST_POWER
        sprintf(output3, ">>%2d]  {%5.2fV}  FIRST\n-----------------------------------------------\n", yx_power, value);
#endif
    }
}
void APP_dev::power_SelectDian() {
    if (AdcDev > 0 && !power_Stop()) {
        int state = power_State();
        if (state == 0) {
            power_average_MIN_MAX(0);
#ifdef TEST_POWER
            sprintf(output, "%s%s%s", output1, output2, output3);
#endif
        } else if (state > 0) {
            power_Electricity(state);
#ifdef TEST_POWER
            sprintf(output, "%s%s%s", output1, output2, output3);
#endif
        }
    }
#ifdef TEST_POWER
    else {
        sprintf(output, "There is no data\n");
    }

#ifndef Clion
    pc_wr_data(output);
#endif
    printf("%s", output);
#endif
}



////-----------TEST--------------////
void APP_dev::setTest1(int test0,int test1) {
    APP_dev::test0 = test0;
    APP_dev::test1 = test1;
}
void APP_dev::setTest1(double test0, double test1){
    APP_dev::test0 = (int)((test0*4095)/13.2);
    APP_dev::test1 = (int)((test1*4095)/13.2);
    printf("%d-%d\n",APP_dev::test0,APP_dev::test1);
}
int APP_dev::setYx_power(int yx_power) {
    APP_dev::yx_power = yx_power;
    return APP_dev::yx_power;
}
void APP_dev::setStop(bool isMotorStart, bool isPrinterRun, bool isDoorMove,int batteryStop) {
    this->isMotorStart=isMotorStart;
    this->isPrinterRun=isPrinterRun;
    this->isDoorMove=isDoorMove;
    this->batteryStop=batteryStop;
}
int APP_dev::getYx_power() const {
    return yx_power;
}

