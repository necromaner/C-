////
//// Created by necromaner on 2018-12-26.
////
//
//
//
//
//
//#include "APP_dev.h"
//#define CMD_PORT_SELECTED 0x0C
//#define CMD_BIT_SELECTED 0x0D
//int AdcDev;
//void APP_dev::Rank_Data(float *arr, int lengh) {
//    int m = lengh;
//    float Temp_data = 0;
//    for (int i = 0; i < lengh; i++) {
//        m--;
//        for (int j = 0; j < m; j++) {
//            if (arr[j] >= arr[j + 1]) {
//                Temp_data = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = Temp_data;
//            }
//        }
//    }
//}
//float APP_dev::GetMeanVal(float *DataBuf, int DataNumber, float Paramater) {
//    if (NULL == DataBuf || Paramater >= 1.0) {
//        return -1;
//    }
//    float SUM_Data = 0.0;
//    int Data_Start = (int) (DataNumber * Paramater) - 1;      //1 10*0.2-1
//    int Data_End = (int) (DataNumber * (1 - Paramater)) + 1;  //9 10*0.8+1
//    for (int i = Data_Start; i <= Data_End; i++) {//1+2+3+4+5+6+7+8+9=45
//        SUM_Data += DataBuf[i];
//    }
//    return (SUM_Data / Data_End);
//}
//
//
//APP_dev::APP_dev()  {
//    AdcDev=1;
//    yx_power=0;
//    test0=0;
//    test1=0;
//    isMotorStart= false;
//    isPrinterRun= false;
//    isDoorMove= false;
//}
//
//void APP_dev::setTest(int test0,int test1) {
////    printfPower();
//    APP_dev::test0 = test0;
//    APP_dev::test1 = test1;
//    Timer_SelectDian();
//}
//
//double APP_dev::getYx_power() const {
//    return yx_power;
//}
//void APP_dev::printfPower(){
//    printf("%4.2f-%4.2f-%4.2f-%4.2f-%4.2f-%4.2f-%4.2f-%4.2f-%4.2f-%4.2f\n",Power[0],Power[1],Power[2],Power[3],Power[4],Power[5],Power[6],Power[7],Power[8],Power[9]);
//}
///*
// *
//3164
//3102
//3040
//2947
//0
//3431
//3360
//3326
//3254
// */
///*
// * 电池状态：
// * 充电
// *      放电->充电✅（直接通过上一次电量进行变换）
// *          电量不变✅
// *          电量改变❌✅
// *              电量增大❌✅
// *                  电量增大一格❌✅
// *                  电量增大多格❌✅
// *              电量降低❌✅
// *                  电量降低一格❌✅
// *                  电量降低多格❌✅
// *      连续充电✅
// *          正充电✅
// *              电量不变✅(通过检测当前电量是否之前有记录过判断)（正常充电）
// *              电量增加✅
// *                  电量增加一格✅（正常充电）
// *                  电量增加多格✅❌（不正常充电）
// *                      100->20 40 60 ->40 60 80
// *                      80->20 40     ->40 60
// *                      60->20        ->40
// *
// *          负充电✅（充电速度<放电速度)
// *              电量减少一格✅（正常放电）
// *                  20->40        ->40
// *                  40->60        ->60
// *                  60->80        ->80
// *                  80->100       ->100
// *              电量减少多格❌✅（不正常放电）
// *                  20->60 80 100 ->40 60 80
// *                  40->80 100    ->60 80
// *                  60->100       ->80
// * 放电✅
// *      充电->放电✅（直接通过上一次电量进行变换）
// *          电量不变✅
// *          电量改变❌✅
// *              电量增大❌✅
// *                  电量增大一格❌✅
// *                  电量增大多格❌✅
// *              电量降低❌✅
// *                  电量降低一格❌✅
// *                  电量降低多格❌✅
// *      连续放电✅
// *          正放电✅
// *              电量不变✅(通过检测当前电量是否之前有记录过判断)（正常放电）
// *              电量降低✅
// *                  电量降低一格✅（正常放电）
// *                  电量降低多格❌✅（不正常放电）
// *                      60->100        ✅->80
// *                      40->80 100     ✅->60 80
// *                      20->60 80 100  ✅->40 60 80
// *          负放电❌✅(通过检测当前电量是否之前有记录过判断)
// *              电量增加一格❌✅（不正常放电）
// *              电量增加多格❌✅（不正常放电）
// * 注:电量为显示格数
// *    ❌为异常不正常情况
// *    ✅为功能实现
// *
// * 获取通道：
// * 充电
// *      放电->充电              [下一次通道1]
// *      连续充电
// *          电量增加或不变       [下一次通道0]
// *          电量减少            [下一次通道1]
// * 放电
// *      放电->充电              [下一次通道1]
// *      连续充电
// *          电量增加            [下一次通道1]
// *
// *          电量减少或不变
// *              连续减少或不变   [下一次通道0]
// *              跳跃减少        [下一次通道1]
// */
//void APP_dev::Timer_SelectDian() {
//    if (AdcDev > 0) {
//        float ibuffer;
//        static float dValue0 = 0;                     //0通道模数转换 0通道用于检测充放电状态
//        static float dValue1 = 0;                     //1通道模数转换 1通道用于判断电量范围
//        double Value_Temp = 0;                        //电池平均值 放电状态时使用
//        double Value_Value = 0;                       //电压平均值 充电状态时使用
//
//        static bool isChangePower = false;            //充电状态
//        static bool isChangeDianchi = false;          //电池状态
//
//        static bool electricity_100 = false;            //电量100
//        static bool electricity_80 = false;             //电量80
//        static bool electricity_60 = false;             //电量60
//        static bool electricity_40 = false;             //电量40
//        static bool electricity_20 = false;             //电量20
//
//        static bool initializePower = true;            //初始化Power
//
//        static bool Read0 = false;                    //程序启动时采集通道1 从1通道开始，交替采集
//        if (0 == iCount_Power && initializePower) {
////            for (int i = 0; i < 10; ++i) {
////                Power[i] = 0;
////            }
//            memset(Power, 0, 10);//memset将某一块内存中的内容全部设置为指定的值
//            initializePower = false;
//        }
//        if (isMotorStart || isPrinterRun || isDoorMove) {  // 电机正在运动时，停止采集电压
//            return;
//        }
//        if (Read0) { // 读通道0 ADC值 ,并且分析通道1与通道0的值
//
//            ////--------采集数据---------////
////            ioctl(AdcDev, CMD_BIT_SELECTED, 12);
////            ioctl(AdcDev, CMD_PORT_SELECTED, 0); //设置通道0
////            int ret = read(AdcDev, &ibuffer, sizeof(ibuffer)); //读ad转换后的数据
//            int ret = 1;
//            ibuffer = test0;
//            if (ret > 0) {
//                dValue0 = (float) ((ibuffer * 3.3) / 4095 * 4);//模数换算
//                char cData[30];
//                sprintf(cData, "dV1:%5.2fV   dV0:%5.2fV\n", dValue1, dValue0);
////                pc_wr_data(cData);
//                printf("%s", cData);
//
////                //1.3.1.1最低值赋给Low_Data （暂无实际用处）
////                if (Low_Data >= dValue0) {
////                    Low_Data = dValue0;
////                }
////                //1.3.1.2最高值赋给Hight_Data （暂无实际用处）
////                if (Hight_Data <= dValue0) {
////                    Hight_Data = dValue0;
////                }
//            }
//            if (dValue0 >= 10) {
//                if (!isChangePower) {
//                    iCount_Power = 0;          //当前次数
//                    initializePower = true;    //下次是否初始化Power
//
//                    isChangeDianchi = false;    //电池状态 否
//                    isChangePower = true;       //充电状态 是
//
//                    electricity_20 = false;    //20电量
//                    electricity_40 = false;    //40电量
//                    electricity_60 = false;    //60电量
//                    electricity_80 = false;    //80电量
//                    electricity_100 = false;   //100电量
//                    if (yx_power > 0 && yx_power <= 1) {//根据之前电量直接转换对应电量
//                        yx_power += 1;
//                        switch ((int) (yx_power * 10)) {
//                            case 20:
//                                electricity_100 = true;
//                            case 18:
//                                electricity_80 = true;
//                            case 16:
//                                electricity_60 = true;
//                            case 14:
//                                electricity_40 = true;
//                            case 12:
//                                electricity_20 = true;
//                                break;
//                        }
//                    } else {//第一次判断电量
//                        if (10.2 <= dValue1) {                               //充电100
//                            electricity_100 = true;
//                            yx_power = 2.0;
//                        } else if (10 <= dValue1 && dValue1 < 10.2) {        //充电80
//                            electricity_80 = true;
//                            yx_power = 1.8;
//                        } else if (9.8 <= dValue1 && dValue1 < 10) {         //充电60
//                            electricity_60 = true;
//                            yx_power = 1.6;
//                        } else if (9.5 <= dValue1 && dValue1 < 9.8) {        //充电40
//                            electricity_40 = true;
//                            yx_power = 1.4;
//                        } else if (dValue1 < 9.5) {                          //充电20
//                            electricity_20 = true;
//                            yx_power = 1.2;
//                        }
//                    }
////                    return;
//                }
//                    //1.3.2.1一直为充电状态
//                else {
//                    //1.3.2.1.1检测到连续充电10次求电压平均值
//                    if (iCount_Power < 9) {//读取前9次数据
//                        Power[iCount_Power] = dValue1;
//                        iCount_Power++;
//                    }
//                        ////----------连续检测状态为充电---------////
//                        //1.3.2.1.2连续检测电池状态为充电10次
//                    else if (9 == iCount_Power) {
//                        ////----------状态归位---------////
//                        iCount_Power = 0;
//                        initializePower = true;
//                        ////-------------------------////
//
//                        ////----------求平均值---------////
//                        Power[iCount_Power] = dValue1;//读取第十个数据
//
//                        Rank_Data(Power, 10);//从小到大排序Power，排序前10个数
//                        Value_Value = GetMeanVal(Power, 10, 0.2);//Value_Value：电压平均值 充电状态时使用
//                        if (10.2 <= Value_Value) {                           //充电100
//                            if (!electricity_80 && electricity_60) {         //从60充到100
//                                electricity_80 = true;
//                                yx_power = 1.8;
//                            } else if (!electricity_80 && electricity_40) {  //从40充到100
//                                electricity_60 = true;
//                                yx_power = 1.6;
//                            } else if (!electricity_80 && electricity_20) {  //从20充到100
//                                electricity_40 = true;
//                                yx_power = 1.4;
//                            } else {                                         //从80或100充到100
//                                electricity_100 = true;
//                                yx_power = 2.0;
//                                return;
//                            }
//
//                        } else if (10 <= Value_Value && Value_Value < 10.2) {//充电80
//                            if (electricity_100) {                           //从100充到80 降低
//                                electricity_100=false;
//                                electricity_80 = true;
//                                yx_power = 1.8;
//                            } else {
//                                if (!electricity_60 && electricity_40) {      //从40充到80
//                                    electricity_60 = true;
//                                    yx_power = 1.6;
//                                } else if (!electricity_60 && electricity_20) {//从20充到80
//                                    electricity_40 = true;
//                                    yx_power = 1.4;
//                                } else {                                       //从60或80充到80
//                                    electricity_80 = true;
//                                    yx_power = 1.8;
//                                    return;
//                                }
//                            }
//                        } else if (9.8 <= Value_Value && Value_Value < 10) { //充电60
//                            if (electricity_100) {                           //从100充到60 降低
//                                electricity_100=false;
//                                electricity_80 = true;
//                                yx_power = 1.8;
//                            } else if (electricity_80) {                     //从80充到60 降低
//                                electricity_80=false;
//                                electricity_60 = true;
//                                yx_power = 1.6;
//                            } else {
//                                if (!electricity_40 && electricity_20) {     //从20充到60
//                                    electricity_40 = true;
//                                    yx_power = 1.4;
//                                } else {                                     //从40或60充到60
//                                    electricity_60 = true;
//                                    yx_power = 1.6;
//                                    return;
//                                }
//                            }
//                        } else if (9.5 <= Value_Value && Value_Value < 9.8) {//充电40
//                            if (electricity_100) {                           //从100充到40 降低
//                                electricity_100=false;
//                                electricity_80 = true;
//                                yx_power = 1.8;
//                            } else if (electricity_80) {                     //从80充到40 降低
//                                electricity_80=false;
//                                electricity_60 = true;
//                                yx_power = 1.6;
//                            } else if (electricity_60) {                     //从60充到40 降低
//                                electricity_60 = false;
//                                electricity_40 = true;
//                                yx_power = 1.4;
//                            } else {                                         //从20或40充到40
//                                electricity_40 = true;
//                                yx_power = 1.4;
//                                return;
//                            }
//                        } else if (Value_Value < 9.5) {                      //充电20
//                            if (electricity_100) {                           //从100充到20 降低
//                                electricity_100=false;
//                                electricity_80 = true;
//                                yx_power = 1.8;
//                            } else if (electricity_80) {                     //从80充到20 降低
//                                electricity_80=false;
//                                electricity_60 = true;
//                                yx_power = 1.6;
//                            } else if (electricity_60) {                     //从60充到20 降低
//                                electricity_60=false;
//                                electricity_40 = true;
//                                yx_power = 1.4;
//                            } else if (electricity_40) {                     //从40充到20 降低
//                                electricity_40=false;
//                                electricity_20 = true;
//                                yx_power = 1.2;
//                            } else {                                         //从20充到20
//                                electricity_20 = true;
//                                yx_power = 1.2;
//                                return;
//                            }
//                        }
//                    }
//                }
//
//            }
//            else {
//                if (!isChangeDianchi) {
//                    iCount_Power = 0;          //当前次数
//                    initializePower = true;    //下次是否初始化Power
//
//                    isChangeDianchi = true;    // 电池状态 是
//                    isChangePower = false;     // 充电状态 否
//
//                    electricity_20 = false;    //20电量
//                    electricity_40 = false;    //40电量
//                    electricity_60 = false;    //60电量
//                    electricity_80 = false;    //80电量
//                    electricity_100 = false;   //100电量
//                    if (yx_power > 1 && yx_power <= 2) {//根据之前电量直接转换对应电量
//                        yx_power -= 1;
//                        switch ((int) (yx_power * 10)) {
//                            case 2:
//                                electricity_20 = true;
//                            case 4:
//                                electricity_40 = true;
//                            case 6:
//                                electricity_60 = true;
//                            case 8:
//                                electricity_80 = true;
//                            case 10:
//                                electricity_100 = true;
//                                break;
//                        }
//                    } else {
//                        if (11.06 <= dValue1) {                          //放电100
//                            electricity_100 = true;
//                            yx_power = 1.00;
//                        } else if (10.83 <= dValue1 && dValue1 < 11.06) {//放电80
//                            electricity_80 = true;
//                            yx_power = 0.8;
//                        } else if (10.72 <= dValue1 && dValue1 < 10.83) {//放电60
//                            electricity_60 = true;
//                            yx_power = 0.6;
//                        } else if (10.49 <= dValue1 && dValue1 < 10.72) {//放电40
//                            electricity_40 = true;
//                            yx_power = 0.4;
//                        } else if (dValue1 < 10.49) {                    //放电20
//                            electricity_20 = true;
//                            yx_power = 0.2;
//                        }
//                    }
////                    return;
//                }
//                else {
//                    if (iCount_Power < 9) {//读取前9次数据
//                        Power[iCount_Power] = dValue1;
//                        iCount_Power++;
//                    }
//                    else if (9 == iCount_Power) {
//                        iCount_Power = 0;
//                        initializePower = true;
//                        Power[iCount_Power] = dValue1;//读取第十个数据
//
//                        Rank_Data(Power, 10);//从小到大排序Power，排序前10个数
//                        Value_Temp = GetMeanVal(Power, 10, 0.2);//Value_Temp：电池平均值 放电状态时使用
//                        if (11.06 <= Value_Temp) {                           //放电100
//                            if (electricity_20 || electricity_40 || electricity_60 || electricity_80) {//放电电量升高error
//                            } else {                                         //从100降到100
//                                electricity_100 = true;
//                                yx_power = 1.00;
//                                return;
//                            }
//                        } else if (10.83 <= Value_Temp && Value_Temp < 11.06) {//电池电量80
//                            if (electricity_20 || electricity_40 || electricity_60) {//放电电量升高error
//                            } else {                                           //从100或80降到80
//                                electricity_80 = true;
//                                yx_power = 0.8;
//                                return;
//                            }
//                        } else if (10.72 <= Value_Temp && Value_Temp < 10.83) {//电池电量60
//                            if (electricity_20 || electricity_40) {            //放电电量升高error
//                            } else {
//                                if (!electricity_80 && electricity_100) {      //从100降到60
//                                    electricity_80 = true;
//                                    yx_power = 0.8;
//                                } else {                                       //从80或60降到60
//                                    electricity_60 = true;
//                                    yx_power = 0.6;
//                                    return;
//                                }
//                            }
//                        } else if (10.49 <= Value_Temp && Value_Temp < 10.72) {//电池电量40
//                            if (electricity_20) {                              //放电电量升高error
//                            } else {
//                                if (!electricity_60 && electricity_80) {       //从80降到40
//                                    electricity_60 = true;
//                                    yx_power = 0.6;
//                                } else if (!electricity_60 && electricity_100) {//从100降到40
//                                    electricity_80 = true;
//                                    yx_power = 0.8;
//                                } else {                                        //从60或40降到40
//                                    electricity_40 = true;
//                                    yx_power = 0.4;
//                                    return;
//                                }
//                            }
//                        } else if (Value_Temp < 10.49) {                   //电池电量20
//                            if (!electricity_40 && electricity_60) {       //从60降到20
//                                electricity_40 = true;
//                                yx_power = 0.4;
//                            } else if (!electricity_40 && electricity_80) {//从80降到20
//                                electricity_60 = true;
//                                yx_power = 0.6;
//                            } else if (!electricity_40 && electricity_100) {//从100降到20
//                                electricity_80 = true;
//                                yx_power = 0.8;
//                            } else {                                        //从40或20降到20
//                                electricity_20 = true;
//                                yx_power = 0.2;
//                                return;
//                            }
//                        }
//                    }
//                }
//            }
//            Read0 = false;
//        }
//            //1.3读通道1
//        else {
//
//            ////--------采集数据---------////
////            ioctl(AdcDev, CMD_BIT_SELECTED, 12);
////            ioctl(AdcDev, CMD_PORT_SELECTED, 1); //设置通道1
////            int ret = read(AdcDev, &ibuffer, sizeof(ibuffer)); //读ad转换后的数据
//            int ret = 1;
//            ibuffer = test1;
//            ////-------------------------////
//            //1.3.1如果读取到ad转换后的数
//            if (ret > 0) {
//                dValue1 = (float) ((ibuffer * 3.3) / 4095 * 4);//模数换算
//            }
//            Read0 = true;
//        }
//    }
//}
