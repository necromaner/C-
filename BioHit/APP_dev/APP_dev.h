//
// Created by necromaner on 2018-12-26.
//

#ifndef BIOHIT_APP_DEV_H
#define BIOHIT_APP_DEV_H

#include <unistd.h>//read
#include <sys/ioctl.h>//ioctl
#include <string.h>//memset
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
#define POWER_SIZE 10
#define CHARGING_100 11
#define CHARGING_80 10
#define CHARGING_60 9
#define CHARGING_40 8
#define CHARGING_20 7

#define DISCHARGE_100 6
#define DISCHARGE_80 5
#define DISCHARGE_60 4
#define DISCHARGE_40 3
#define DISCHARGE_20 2
#define DISCHARGE_10 1

#define CHONG_4 11.5
#define CHONG_3 11
#define CHONG_2 10.5
#define CHONG_1 10

#define FANG_4 11.5
#define FANG_3 11
#define FANG_2 10.5
#define FANG_1 10
#define FANG_0 9.5
#define FANG_MIN 9.0

#define ZTERROR1 -1
#define ZT0 0
#define ZT1 1
#define ZT2 2
#define ZT3 3
#define ZT4 4
#define Clion
#define TEST
#ifdef TEST
#define TEST_POWER
#endif
#define AdcMaxCycle        (1800)//bytes
typedef struct {
    //项目
    string xiangmu;//项目名称
    string xiangmudanwei;//项目单位
    string czuidizhi;//C线极限低值
    string czuigaozhi;//C线极限高值
//    QString cqidian;//C线起点
//    QString czhongdian;//C线终点
//    QString tqidian;//T线起点
//    QString tzhongdian;//T线终点
    string WB_Para;// 全血系数
    string Equation_Limit;//方程最低值
    string Equation_Max;//方程最高值
    string NOP;                //数组0为批号显示的项目，其余保留
    string anongduzhi;//浓度参考值A
    string bnongduzhi;//浓度参考值B
    string cankaoxingshi;//浓度参考显示形式
    string nongdudizhi;//浓度极限低值
    string nongdugaozhi;//浓度极限高值
    string jisuanfangshi;//计算方式
    string jisuanfangfa;//计算浓度方法
    string canshua;//参数A
    string canshub;//参数B
    string canshuc;//参数C
    string canshud;//参数D
} XiangMuPmStr;//二维码里面的项目参数
typedef struct {
    string Head;//YX-
    string Pihao;//批号
    string Yiweima;//一维码
    string Xiangmushuliang;//项目数量
    string PiLiang;//批量
    string youxiaoshijian;//有效时间
    string yanshi;//有效时间
    XiangMuPmStr XiangMuPm[4];
} TwoCodeStr;//二维码参数结构
enum AppStaStr{
    NOP_DEV=0x00,//空闲
    AGL_DEV =0x01,//荧光设备标识
    CGR_DEV=0x02,//金标设备标识
};
typedef struct {
    int Tstart;
    int Tend;
    int Cstart;
    int Cend;
} TlineClinePosStr;//C line and T line Pos
typedef struct {
    int MinPos;//荧光曲线的谷底位置
    int MaxPos;//荧光曲线的峰值位置
    double MinVol;//荧光曲线最小值
    double MaxVol;//荧光曲线最大值
    int CPeakPos;//曲线中C线位置
    int TPeakPos;//曲线中T线位置
    double CPeakVol;//C值
    double TPeakVol; //T值
    double YSumVol;//荧光结果浓度
}   AdcCalcStr;//荧光计算结果
typedef struct {
    bool state;//虚拟荧光设备状态
    char Version[64];//虚拟荧光版本
    char LedCurrent;//荧光灯的电流
    char PdTemperature;//光敏温度
    char LedTemperature;//荧光灯的温度
    char OutIntState;//出仓，入仓状态
    char AdcState;//荧光采集是否完成状态。

    char MotorDX;//X轴电机参数
    char MotorDY;//Y轴电机参数
    char LedSetVol;//荧光灯的设定电流
    char ChxVol;//荧光设置的通道个数

    double ChxBuf[4][2000];//荧光采集的初始值
    double BakBuf[4][2000];//荧光采集的本底值
    double VolBuf[4][2000]; //荧光采集的最终值
    TwoCodeStr TwoDimCode;//二维码参数
    AdcCalcStr AdcCalc[4];//荧光计算结果
}   AglDevStr;//虚拟荧光设备
typedef struct FoundPeakVol
{
    int Location;
    double ReadData;
}FoundPeakVol;




class APP_dev {
public:
    APP_dev();
////-------------------电池-----------------////
private:
    char output[200];
    char output1[60];
    char output2[30];
    char output3[110];
    bool isMotorStart;
    bool isDoorMove;
    bool isPrinterRun;
    int batteryStop;
    bool power_Stop();
    int power_State();
    void power_Electricity(int state);
    float power_average_MIN_MAX(float x);
public:
    int yx_power;//2.00 ,1.00,0.75,0.50，0.2
    void power_SelectDian();
    ////-----------TEST--------------////
    int test0;//测试用
    int test1;//测试用
    void setTest1(int test0, int test1);
    void setTest1(double test0, double test1);
    int setYx_power(int yx_power);
    void setStop(bool isMotorStart, bool isPrinterRun, bool isDoorMove, int batteryStop);
    int getYx_power() const;
////---------------------------------------////


////--------------荧光计算--------------------////
//public:
//    AglDevStr  AglDev;//虚拟荧光
//    AppStaStr  AppSta;//虚拟设备标识，AGL ，CGR
//    bool Card_index[4];
//    int iPeakTimes;
//    bool isCalibration;//校准
//    bool isTestContrl;//测试控制
//
//
//    bool agl_calc_buf(TlineClinePosStr TcPos,double *bufP,int Length,AdcCalcStr &CalcVol);//荧光数据的分析
//    bool agl_calc_vol(TwoCodeStr TwoDimCode);
//
//    void Rank_Data(FoundPeakVol *arr, int lengh);

};


#endif //BIOHIT_APP_DEV_H
