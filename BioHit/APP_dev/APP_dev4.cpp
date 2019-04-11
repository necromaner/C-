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
//    batteryStop=0;
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
//void APP_dev::setTest1(int test0,int test1) {
//    APP_dev::test0 = test0;
//    APP_dev::test1 = test1;
//}
//void APP_dev::setTest1(double test0, double test1){
//    APP_dev::test0 = (int)((test0*4095)/13.2);
//    APP_dev::test1 = (int)((test1*4095)/13.2);
//    printf("%d-%d\n",APP_dev::test0,APP_dev::test1);
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
//
//void APP_dev::setStop(bool isMotorStart, bool isPrinterRun, bool isDoorMove,int batteryStop) {
//    this->isMotorStart=isMotorStart;
//    this->isPrinterRun=isPrinterRun;
//    this->isDoorMove=isDoorMove;
//    this->batteryStop=batteryStop;
//}
//double APP_dev::average(double num) {
//    static int maxSize = 0;//存储数目
//    static int now = 0;//当前坐标
//    static double nums[POWER_SIZE];
//    nums[now] = num;
//    if (now > 8)
//        now = 0;
//    else
//        now++;
//    if (maxSize < POWER_SIZE)
//        maxSize++;
//    double sum = 0;
//    for (int i = 0; i < maxSize; ++i) {
//        sum += nums[i];
//        printf("%4.1f  ", nums[i]);
//    }
//    printf("\n");
//    return sum / maxSize;
//}
//int APP_dev::setYx_power(int yx_power) {
//    APP_dev::yx_power = yx_power;
//    return APP_dev::yx_power;
//}
//
//
//
//void APP_dev::Timer_SelectDian() {
//    //1.判断是否获取到数据，如果没有获取到数据则结束
//    if (AdcDev > 0) {
//        ////----------------------初始化-----------------------////
//        int ibuffer;
//        static double dValue0 = 0;                      //0通道模数转换 0通道用于检测充放电状态
//        static double dValue1 = 0;                      //1通道模数转换 1通道用于判断电量范围
//        double Value_Temp = 0;                          //电池平均值 放电状态时使用
//        double Value_Value = 0;                         //电压平均值 充电状态时使用
//
//        static bool isChangePower = false;              //充电状态
//        static bool isChangeDianchi = false;            //电池状态
//
//        static bool electricity_100 = false;            //电量100
//        static bool electricity_80 = false;             //电量80
//        static bool electricity_60 = false;             //电量60
//        static bool electricity_40 = false;             //电量40
//        static bool electricity_20 = false;             //电量20
//        static bool electricity_10 = false;             //电量10
//
//        static bool initializePower = true;             //初始化Power
//        static bool lastRead1 = true;                   //上次是否读取Read1
//
//        static bool Read0 = false;                      //程序启动时采集通道1 从1通道开始，交替采集
//        static bool motorEnd=false;
//        int scope=4;                                    //
//        ////-------------------------------------------------////
//        //1.1初始化Power
//        if (0 == iCount_Power && initializePower) {
//            printf("\n +---------|初始化|----------+ \n");
//            //将Power前10个字节设置为0
//            for (int i = 0; i < 10; ++i) {
//                Power[i] = 0;
//            }
////            memset(Power, 0, 10);//memset将某一块内存中的内容全部设置为指定的值
//            initializePower = false;
//        }
//
//        if(isMotorStart){
//            if(batteryStop>0){
//                batteryStop--;
//            }
//            motorEnd=true;
//            return;
//        }else if(motorEnd){
//            if(batteryStop>0){
//                batteryStop--;
//            }
//            Read0=false;
//            motorEnd=false;
//            return;
//
//        }
//        //1.2电机正在运动时，停止采集电压
//        if (isPrinterRun || isDoorMove) {  // 电机正在运动时，停止采集电压
//            if(batteryStop>1){
////                char cData[50];
////                sprintf(cData, "Time is not!\n");
////                pc_wr_data(cData);
//                batteryStop--;
//                return;
//            }else{
//                batteryStop=0;
////                char cData[50];
////                sprintf(cData, "OK!\n");
////                pc_wr_data(cData);
//                isDoorMove=false;
//                isPrinterRun=false;
//                Read0=false;
//                return;
//            }
//        }
//
//        //1.3读通道0 先读1通道，再读0通道，轮流读取 通道0为获取充电放电状态，通道1为获取电池电量
//        if (Read0) { // 读通道0 ADC值 ,并且分析通道1与通道0的值
//            if (!lastRead1) {
//                printf("-|    ");
//            }
//            lastRead1 = false;
//
//            ////--------采集数据---------////
//            ioctl(AdcDev, CMD_BIT_SELECTED, 12);
//            ioctl(AdcDev, CMD_PORT_SELECTED, 1); //设置通道0
//            int ret = read(AdcDev, &ibuffer, sizeof(ibuffer)); //读ad转换后的数据
//            ret = 1;
//            ibuffer = test0;//test0:状态
//            ////-------------------------////
//
//            //1.3.1如果读取到ad转换后的数
//            if (ret > 0) {
//                dValue0 = (float) ((ibuffer * 3.3) / 4095 * 4);//模数换算
//                char cData[50];
//                sprintf(cData, "%5.2f    %5.2f    Power:%2d\n", dValue0, dValue1,yx_power);
////                pc_wr_data(cData);
////                printf("%s", cData);
//            }
//            //1.3.2充电状态
//            if (dValue0 <1) {
//                printf("-充电|");
//                //1.3.2.1电池状态转充电状态
//                if (!isChangePower) {
//                    printf("-|  电池->充电 | |电量:%2d", yx_power);
//                    ////----------状态归位---------////
//                    iCount_Power = 0;          //当前次数
//                    initializePower = true;    //下次是否初始化Power
//
//                    isChangeDianchi = false;    //电池状态 否
//                    isChangePower = true;       //充电状态 是
//
//                    electricity_10 = false;    //20电量
//                    electricity_20 = false;    //20电量
//                    electricity_40 = false;    //40电量
//                    electricity_60 = false;    //60电量
//                    electricity_80 = false;    //80电量
//                    electricity_100 = false;   //100电量
//                    ////-------------------------////
//
//                    ////----------电量判断---------////
//                    if (yx_power >= DISCHARGE_10 && yx_power <= DISCHARGE_100) {//根据之前电量直接转换对应电量
//                        if (yx_power == FANG_0) {
//                            yx_power = CHARGING_20;
//                        } else {
//                            yx_power += 5;
//                        }
//                        switch (yx_power) {
//                            case CHARGING_100:
//                                electricity_100 = true;
//                            case CHARGING_80:
//                                electricity_80 = true;
//                            case CHARGING_60:
//                                electricity_60 = true;
//                            case CHARGING_40:
//                                electricity_40 = true;
//                            case CHARGING_20:
//                                electricity_20 = true;
//                                break;
//                        }
//                        printf("->");
//                    } else {//第一次判断电量
//                        if (CHONG_4 <= dValue1) {                               //充电100
//                            electricity_100 = true;
//                            yx_power = CHARGING_100;
//                        } else if (CHONG_3 <= dValue1 && dValue1 < CHONG_4) {        //充电80
//                            electricity_80 = true;
//                            yx_power = CHARGING_80;
//                        } else if (CHONG_2 <= dValue1 && dValue1 < CHONG_3) {         //充电60
//                            electricity_60 = true;
//                            yx_power = CHARGING_60;
//                        } else if (CHONG_1 <= dValue1 && dValue1 < CHONG_2) {        //充电40
//                            electricity_40 = true;
//                            yx_power = CHARGING_40;
//                        } else if (dValue1 < CHONG_1) {                          //充电20
//                            electricity_20 = true;
//                            yx_power = CHARGING_20;
//                        }
//                        printf("<>");
//                    }
//                    printf("电量:%2d|", yx_power);
//                    printf(" |%d-%d-%d-%d-%d|\n", electricity_20, electricity_40, electricity_60,
//                           electricity_80, electricity_100);
//                    ////-------------------------////
////                    return;
//                }
//                    //1.3.2.1一直为充电状态
//                else {
//                    printf("-|一直充电--%d次|", iCount_Power);
//                    //1.3.2.1.1检测到连续充电10次求电压平均值
//                    if (iCount_Power < POWER_SIZE-1) {//读取前9次数据
//                        printf("\n");
//                        Power[iCount_Power] = (float )dValue1;
//                        iCount_Power++;
//                    }
//                        ////----------连续检测状态为充电---------////
//                        //1.3.2.1.2连续检测电池状态为充电10次
//                    else if (POWER_SIZE-1 == iCount_Power) {
//                        ////----------状态归位---------////
//                        iCount_Power = 0;
//                        initializePower = true;
//                        ////-------------------------////
//
//                        ////----------求平均值---------////
//                        Power[iCount_Power] = (float )dValue1;//读取第十个数据
////                        Rank_Data(Power, POWER_SIZE);//从小到大排序Power，排序前10个数
////                        //GetMeanVal中带入参数 10, 0.2，可以为获得Power[1～9]的平均值
////                        Value_Value = GetMeanVal(Power, POWER_SIZE, 0.2);//Value_Value：电压平均值 充电状态时使用
//                        Value_Value = average_MIN_MAX(Power,POWER_SIZE);
//                        ////-------------------------////
//
//                        printf("电压-%4.1f", Value_Value);
//                        printf("   |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                               electricity_80, electricity_100);
//
//                        ////----------电量判断---------////
//                        if (CHONG_4 <= Value_Value) {                           //充电100
//                            if (!electricity_80 && electricity_60) {         //从60充到100
//                                electricity_80 = true;
//                                yx_power = CHARGING_80;
//                            } else if (!electricity_80 && electricity_40) {  //从40充到100
//                                electricity_60 = true;
//                                yx_power = CHARGING_60;
//                            } else if (!electricity_80 && electricity_20) {  //从20充到100
//                                electricity_40 = true;
//                                yx_power = CHARGING_40;
//                            } else {                                         //从80或100充到100
//                                electricity_100 = true;
//                                yx_power = CHARGING_100;
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量持续增加或不变 当前电量：%2d\n", yx_power);
//                                return;
//                            }
//                            printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                   electricity_80, electricity_100);
//                            printf("  电量跳跃增加 当前电量：%2d\n", yx_power);
//
//                        } else if (CHONG_3 <= Value_Value && Value_Value < CHONG_4) {//充电80
//                            if (electricity_100) {                           //从100充到80 降低
//                                if(Value_Value>(CHONG_4-(CHONG_4-CHONG_3)/scope)){//后scope分之一范围
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("  电量%2d->电量%2d 电压在临界范围，不变\n",CHARGING_80, yx_power);
//                                } else{
//                                    printf("  电量%2d", yx_power);
//                                    electricity_100=false;
//                                    electricity_80 = true;
//                                    yx_power = CHARGING_80;
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("->电量%2d 电量降低\n", yx_power);
//                                }
//                            } else {
//                                if (!electricity_60 && electricity_40) {      //从40充到80
//                                    electricity_60 = true;
//                                    yx_power = CHARGING_60;
//                                } else if (!electricity_60 && electricity_20) {//从20充到80
//                                    electricity_40 = true;
//                                    yx_power = CHARGING_40;
//                                } else {                                       //从60或80充到80
//                                    electricity_80 = true;
//                                    yx_power = CHARGING_80;
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("  电量持续增加或不变 当前电量：%2d\n", yx_power);
//                                    return;
//                                }
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量跳跃增加 当前电量：%2d\n", yx_power);
//                            }
//                        } else if (CHONG_2 <= Value_Value && Value_Value < CHONG_3) { //充电60
//                            if (electricity_100) {                           //从100充到60 降低
//                                electricity_100=false;
//                                electricity_80 = true;
//                                yx_power = CHARGING_80;
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量%2d->电量%2d 电量降低\n",CHARGING_60, yx_power);
//                            } else if (electricity_80) {                     //从80充到60 降低
//                                if(Value_Value>(CHONG_3-(CHONG_3-CHONG_2)/scope)){//后scope分之一范围
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("  电量%2d->电量%2d 电压在临界范围，不变\n", CHARGING_60,yx_power);
//                                } else{
//                                    printf("  电量%2d", yx_power);
//                                    electricity_80=false;
//                                    electricity_60 = true;
//                                    yx_power = CHARGING_60;
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("->电量%2d 电量降低\n", yx_power);
//                                }
//                            } else {
//                                if (!electricity_40 && electricity_20) {     //从20充到60
//                                    electricity_40 = true;
//                                    yx_power = CHARGING_40;
//                                } else {                                     //从40或60充到60
//                                    electricity_60 = true;
//                                    yx_power = CHARGING_60;
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("  电量持续增加或不变 当前电量：%2d\n", yx_power);
//                                    return;
//                                }
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量跳跃增加 当前电量：%2d\n", yx_power);
//                            }
//                        } else if (CHONG_1 <= Value_Value && Value_Value < CHONG_2) {//充电40
//                            if (electricity_100) {                           //从100充到40 降低
//                                electricity_100=false;
//                                electricity_80 = true;
//                                yx_power = CHARGING_80;
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量1.4->电量%2d 电量降低\n", yx_power);
//                            } else if (electricity_80) {                     //从80充到40 降低
//                                electricity_80=false;
//                                electricity_60 = true;
//                                yx_power = CHARGING_60;
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量%2d->电量%2d 电量降低\n", CHARGING_40,yx_power);
//                            } else if (electricity_60) {                     //从60充到40 降低
//                                if(Value_Value>(CHONG_2-(CHONG_2-CHONG_1)/scope)){//后scope分之一范围
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("  电量%2d->电量%2d 电压在临界范围，不变\n", CHARGING_40,yx_power);
//                                } else{
//                                    printf("  电量%2d", yx_power);
//                                    electricity_60 = false;
//                                    electricity_40 = true;
//                                    yx_power = CHARGING_40;
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("->电量%2d 电量降低\n", yx_power);
//                                }
//                            } else {                                         //从20或40充到40
//                                electricity_40 = true;
//                                yx_power = CHARGING_40;
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量持续增加或不变 当前电量：%2d\n", yx_power);
//                                return;
//                            }
//                        } else if (Value_Value < CHONG_1) {                      //充电20
//                            if (electricity_100) {                           //从100充到20 降低
//                                electricity_100=false;
//                                electricity_80 = true;
//                                yx_power = CHARGING_80;
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量%2d->电量%2d 电量降低\n",CHARGING_20, yx_power);
//                            } else if (electricity_80) {                     //从80充到20 降低
//                                electricity_80=false;
//                                electricity_60 = true;
//                                yx_power = CHARGING_60;
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量%2d->电量%2d 电量降低\n",CHARGING_20, yx_power);
//                            } else if (electricity_60) {                     //从60充到20 降低
//                                electricity_60=false;
//                                electricity_40 = true;
//                                yx_power = CHARGING_40;
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量%2d->电量%2d 电量降低\n", CHARGING_20,yx_power);
//                            } else if (electricity_40) {                     //从40充到20 降低
//
//                                if(Value_Value>(CHONG_1-(CHONG_4-CHONG_1)/(3*scope))){//后scope分之一范围
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("  电量%2d->电量%2d 电压在临界范围，不变\n", CHARGING_20,yx_power);
//                                } else{
//                                    printf("  电量%2d", yx_power);
//                                    electricity_40=false;
//                                    electricity_20 = true;
//                                    yx_power = CHARGING_20;
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("->电量%2d 电量降低\n", yx_power);
//                                }
//                            } else {                                         //从20充到20
//                                electricity_20 = true;
//                                yx_power = CHARGING_20;
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量持续增加或不变 当前电量：%2d\n", yx_power);
//                                return;
//                            }
//                        }
//
//                    } else {
//                        printf("\n");
//                    }
//                    ////-------------------------////
//                }
//
//            }
//                //1.3.2放电状态
//            else {
//                printf("-放电|");
//                //1.3.2.1充电状态转电池状态
//                if (!isChangeDianchi) {
//                    printf("-|  充电->电池 | |电量:%2d", yx_power);
//                    ////----------状态归位---------////
//                    iCount_Power = 0;          //当前次数
//                    initializePower = true;    //下次是否初始化Power
//
//                    isChangeDianchi = true;    // 电池状态 是
//                    isChangePower = false;     // 充电状态 否
//
//                    electricity_10 = false;    //20电量
//                    electricity_20 = false;    //20电量
//                    electricity_40 = false;    //40电量
//                    electricity_60 = false;    //60电量
//                    electricity_80 = false;    //80电量
//                    electricity_100 = false;   //100电量
//                    ////-------------------------////
//
//                    ////----------电量判断---------////
//                    if (yx_power >= CHARGING_20 && yx_power <= CHARGING_100) {//根据之前电量直接转换对应电量
//                        yx_power -= 5;
//                        switch (yx_power) {
//                            case DISCHARGE_20:
//                                electricity_20 = true;
//                            case DISCHARGE_40:
//                                electricity_40 = true;
//                            case DISCHARGE_60:
//                                electricity_60 = true;
//                            case DISCHARGE_80:
//                                electricity_80 = true;
//                            case DISCHARGE_100:
//                                electricity_100 = true;
//                                break;
//                        }
//                        printf("->");
//                    } else {
//                        if (FANG_4 <= dValue1) {                          //放电100
//                            electricity_100 = true;
//                            yx_power = DISCHARGE_100;
//                        } else if (FANG_3 <= dValue1 && dValue1 < FANG_4) {//放电80
//                            electricity_80 = true;
//                            yx_power = DISCHARGE_80;
//                        } else if (FANG_2 <= dValue1 && dValue1 < FANG_3) {//放电60
//                            electricity_60 = true;
//                            yx_power = DISCHARGE_60;
//                        } else if (FANG_1 <= dValue1 && dValue1 < FANG_2) {//放电40
//                            electricity_40 = true;
//                            yx_power = DISCHARGE_40;
//                        } else if (dValue1 < FANG_1) {                    //放电20
//                            electricity_20 = true;
//                            yx_power = DISCHARGE_20;
//                        }
//                        printf("<>");
//                    }
//                    printf("电量:%2d|", yx_power);
//                    printf(" |%d-%d-%d-%d-%d|\n", electricity_20, electricity_40, electricity_60,
//                           electricity_80, electricity_100);
//                    ////-------------------------////
////                    return;
//                }
//                    //1.3.2.1一直为放电状态
//                else {
//                    printf("-|一直放电--%d次|", iCount_Power);
//                    //1.3.2.1.1检测到连续充电10次求电压平均值
//                    if (iCount_Power < POWER_SIZE-1) {//读取前9次数据
//                        printf("\n");
//                        Power[iCount_Power] = (float )dValue1;
//                        iCount_Power++;
//                    }
//                        ////----------连续检测状态为放电---------////
//                        //1.3.2.1.2连续检测电池状态为充电10次
//                    else if (POWER_SIZE-1 == iCount_Power) {
//                        ////----------状态归位---------////
//                        iCount_Power = 0;
//                        initializePower = true;
//                        ////-------------------------////
//
//                        ////----------求平均值---------////
//                        Power[iCount_Power] = (float )dValue1;//读取第十个数据
//
////                        Rank_Data(Power, POWER_SIZE);//从小到大排序Power，排序前10个数
////                        //GetMeanVal中带入参数 10, 0.2，可以为获得Power[1～9]的平均值
////                        Value_Temp = GetMeanVal(Power, POWER_SIZE, 0.2);//Value_Temp：电池平均值 放电状态时使用
//                        Value_Temp = average_MIN_MAX(Power,POWER_SIZE);
//                        ////-------------------------////
//
////                        printf(" |电压-%4.1f|", Value_Temp);
//                        printf("  |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                               electricity_80, electricity_100);
//
//                        ////----------电量判断---------////
//                        if (FANG_4 <= Value_Temp) {                           //放电100
//                            if (electricity_10||electricity_20 || electricity_40 || electricity_60 || electricity_80) {//放电电量升高error
//                                printf("  电量%2d->电量%2d 电量升高\n", DISCHARGE_100,yx_power);
//                            } else {                                         //从100降到100
//                                electricity_100 = true;
//                                yx_power = DISCHARGE_100;
//
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量持续降低或不变 当前电量：%2d\n", yx_power);
//                                return;
//                            }
//                        } else if (FANG_3 <= Value_Temp && Value_Temp < FANG_4) {//电池电量80
//                            if (electricity_10||electricity_20 || electricity_40 || electricity_60) {//放电电量升高error
//                                printf("  电量%2d->电量%2d 电量升高\n",DISCHARGE_80, yx_power);
//                            } else {                                           //从100或80降到80
//                                electricity_80 = true;
//                                yx_power = DISCHARGE_80;
//
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量持续降低或不变 当前电量：%2d\n", yx_power);
//                                return;
//                            }
//                        } else if (FANG_2 <= Value_Temp && Value_Temp < FANG_3) {//电池电量60
//                            if (electricity_10||electricity_20 || electricity_40) {            //放电电量升高error
//                                printf("  电量%2d->电量%2d 电量升高\n",DISCHARGE_60, yx_power);
//                            } else {
//                                if (!electricity_80 && electricity_100) {      //从100降到60
//                                    electricity_80 = true;
//                                    yx_power = DISCHARGE_80;
//                                } else {                                       //从80或60降到60
//                                    electricity_60 = true;
//                                    yx_power = DISCHARGE_60;
//
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("  电量持续降低或不变 当前电量：%2d\n", yx_power);
//                                    return;
//                                }
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量跳跃降低 当前电量：%2d\n", yx_power);
//                            }
//                        } else if (FANG_1 <= Value_Temp && Value_Temp < FANG_2) {//电池电量40
//                            if (electricity_10||electricity_20) {                              //放电电量升高error
//                                printf("  电量%2d->电量%2d 电量升高\n", DISCHARGE_40,yx_power);
//                            } else {
//                                if (!electricity_60 && electricity_80) {       //从80降到40
//                                    electricity_60 = true;
//                                    yx_power = DISCHARGE_60;
//                                } else if (!electricity_60 && electricity_100) {//从100降到40
//                                    electricity_80 = true;
//                                    yx_power = DISCHARGE_80;
//                                } else {                                        //从60或40降到40
//                                    electricity_40 = true;
//                                    yx_power =DISCHARGE_40;
//
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("  电量持续降低或不变 当前电量：%2d\n", yx_power);
//                                    return;
//                                }
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量跳跃降低 当前电量：%2d\n", yx_power);
//                            }
//                        } else if (FANG_0 <= Value_Temp && Value_Temp < FANG_1) {                   //电池电量20
//                            if(electricity_10){
//                                if (!electricity_40 && electricity_60) {       //从60降到20
//                                    electricity_40 = true;
//                                    yx_power = DISCHARGE_40;
//                                } else if (!electricity_40 && electricity_80) {//从80降到20
//                                    electricity_60 = true;
//                                    yx_power = DISCHARGE_60;
//                                } else if (!electricity_40 && electricity_100) {//从100降到20
//                                    electricity_80 = true;
//                                    yx_power = DISCHARGE_80;
//                                } else {                                        //从40或20降到20
//                                    electricity_20 = true;
//                                    yx_power = DISCHARGE_20;
//                                    printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                           electricity_80, electricity_100);
//                                    printf("  电量持续降低或不变 当前电量：%2d\n", yx_power);
//                                    return;
//                                }
//                            }
//                            printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                   electricity_80, electricity_100);
//                            printf("  电量跳跃降低 当前电量：%2d\n", yx_power);
////
//                        } else if(FANG_MIN <= Value_Temp && Value_Temp < FANG_0){
//                            if (!electricity_20 && electricity_40) {       //从40降到20
//                                electricity_20 = true;
//                                yx_power = DISCHARGE_20;
//                            } else if (!electricity_40 && electricity_60) {//从60降到20
//                                electricity_40 = true;
//                                yx_power = DISCHARGE_40;
//                            } else if (!electricity_40 && electricity_80) {//从80降到20
//                                electricity_60 = true;
//                                yx_power = DISCHARGE_60;
//                            } else if (!electricity_40 && electricity_100) {//从100降到20
//                                electricity_80 = true;
//                                yx_power = DISCHARGE_80;
//                            } else {                                        //从40或20降到20
//                                electricity_10 = true;
//                                yx_power = DISCHARGE_10;
//                                printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                       electricity_80, electricity_100);
//                                printf("  电量持续降低或不变 当前电量：%2d\n", yx_power);
//                                return;
//                            }
//                            printf(" -> |%d-%d-%d-%d-%d|", electricity_20, electricity_40, electricity_60,
//                                   electricity_80, electricity_100);
//                            printf("  电量跳跃降低 当前电量：%2d\n", yx_power);
//
//                        } else{//电量太低执行关机
//
//                        }
//                    } else {
//                        printf("\n");
//                    }
//                    ////-------------------------////
//                }
//            }
//            Read0 = false;
//        }
//            //1.3读通道1
//        else {
//            lastRead1 = true;
//
//
//            printf("-|电量");
//
//            ////--------采集数据---------////
//            ioctl(AdcDev, CMD_BIT_SELECTED, 12);
//            ioctl(AdcDev, CMD_PORT_SELECTED, 0); //设置通道1
//            int ret = read(AdcDev, &ibuffer, sizeof(ibuffer)); //读ad转换后的数据
//            ret = 1;
//            ibuffer = test1;//test1:电量
//            ////-------------------------////
//            //1.3.1如果读取到ad转换后的数
//            if (ret > 0) {
//                dValue1 = (float) ((ibuffer * 3.3) / 4095 * 4);//模数换算
//            }
//            Read0 = true;
//        }
//    }
//}
//float APP_dev::average_MIN_MAX(float *DataBuf,int size) {
//    if(size<3)
//        return 0;
//    float max=DataBuf[0];
//    float min=DataBuf[0];
//    float sum=0;
//    for (int i = 0; i < size; ++i) {
//        if(DataBuf[i]>max)
//            max=DataBuf[i];
//        else if(DataBuf[i]<min)
//            min=DataBuf[i];
//        sum+=DataBuf[i];
//    }
//    sum=sum-max-min;
//    return sum/(size-2);
//}
//
//
//
//bool APP_dev::power_Stop() {
//    static bool motorEnd = false;
//    if (isMotorStart) {                                            //采集数据
//        if (batteryStop > 0) {                                     //如果之前记录暂停时间
//            batteryStop--;
//        }
//        motorEnd = true;
//        sprintf(output, "-|MotorSTOP  [          ]  {      }  STOP\n");
//        return true;
//    } else if (motorEnd) {                                         //结束后再暂停一次
//        if (batteryStop > 0) {
//            batteryStop--;
//        }
//        motorEnd = false;
//        sprintf(output, "-|MotorSTART [          ]  {      }  STOP\n");
//        return true;
//    }
//    if (isPrinterRun || isDoorMove) {                              //电机正在运动时，停止采集电压
//        if (batteryStop > 1) {
//            batteryStop--;
//            sprintf(output, "-|OtherSTOP  [          ]  {      }  STOP\n");
//            return true;
//        } else {                                                   //结束后再暂停一次
//            batteryStop = 0;
//            isDoorMove = false;
//            isPrinterRun = false;
//            sprintf(output, "-|OtherSTART [          ]  {      }  STOP\n");
//            return true;
//        }
//    }
//    return false;
//}
//int APP_dev::power_State() {                                       //0 退出循环 1 第一次充电 2 第一次放电 3充电 4放电
//////----------------------初始化-----------------------////
//    int ibuffer;
//    double dValue1 = 0;                                            //1通道用于判断电池状态
//    static int state = 0;                                          //充放状态 0初始值 1充电 2放电
//////---------------------采集数据-----------------------////
//    ioctl(AdcDev, CMD_BIT_SELECTED, 12);
//    ioctl(AdcDev, CMD_PORT_SELECTED, 1);                           //设置通道1
//    int ret = read(AdcDev, &ibuffer, sizeof(ibuffer));             //读ad转换后的数据
////    ret = 1;
////    ibuffer = test0;                                             //test0:状态
//    if (ret > 0)
//        dValue1 = (float) ((ibuffer * 3.3) / 4095 * 4);            //模数换算
//    else
//        return ZT0;
//////-------------------第一次状态判断---------------------////
//    if (state == ZT0) {                                            //第一次
//        if (dValue1 <= 1) {                                        //充电
//            state = ZT1;
//            yx_power = CHARGING_20;
//            sprintf(output1, "-|FIRST      [%2d", yx_power);
//            return ZT1;
//        } else if (dValue1 <=3) {                                  //放电                                                //放电
//            state = ZT2;
//            yx_power = DISCHARGE_20;
//            sprintf(output1, "-|FIRST      [%2d", yx_power);
//            return ZT2;
//        } else {                                                   //旧设备
//            ////---------------------采集数据-----------------------////
//            float dValue0 = 0;
//            ioctl(AdcDev, CMD_BIT_SELECTED, 12);
//            ioctl(AdcDev, CMD_PORT_SELECTED, 0);                   //设置通道0
//            int ret = read(AdcDev, &ibuffer, sizeof(ibuffer));     //读ad转换后的数据
////            ret = 1;
////            ibuffer = test1;                                     //test1:电量
//            if (ret > 0) {
//                dValue0 = (float) ((ibuffer * 3.3) / 4095 * 4);    //模数换算
//            }
//            sprintf(output, "-|Old equipment [%5.2f]-[%5.2f]\n", dValue1,dValue0);
//            return ZTERROR1;
//        }
//    }
//////---------------------状态判断-----------------------////
//    if (state == ZT1 && dValue1 <= 1) {                            //状态不变,充电
//        sprintf(output1, "-|CHARGING   [%2d", yx_power);
//        return ZT3;
//    } else if (state == ZT2 && dValue1 > 1) {                      //状态不变,放电
//        sprintf(output1, "-|DISCHARGE  [%2d", yx_power);
//        return ZT4;
//    } else {                                                       //状态改变
//        sprintf(output1, "-|CHANGE     [%2d", yx_power);
//        if (dValue1 <= 1) {                                        //充电
//            state = ZT1;
//            if (yx_power == DISCHARGE_10)                          //低电量
//                yx_power = DISCHARGE_20;
//            yx_power += (CHARGING_20 - DISCHARGE_20);
//        } else {                                                   //放电
//            state = ZT2;
//            yx_power -= (CHARGING_20 - DISCHARGE_20);
//        }
//        sprintf(output2, "->  >>%2d]", yx_power);
//        return ZT0;
//    }
//}
//float APP_dev::power_average_MIN_MAX(float x) {                    //-1 重置 0未满 other 10次平均值
//    static float max = 0;
//    static float min = 100;
//    static int maxSize = 0;                                        //存储数目
//    static float Power1[POWER_SIZE];
//    if (x <= 0) {
//        sprintf(output3,"  {      }  RESET\n--------------------------------\n");
//        max = 0;
//        min = 100;
//        maxSize = 0;
//        return -1;
//    }
//    if (POWER_SIZE < 3)
//        return 0;
//    if (maxSize < POWER_SIZE) {
//        Power1[maxSize] = x;
//        maxSize++;
//    }
//    if (maxSize == POWER_SIZE) {
//        float sum = 0;
//        maxSize = 0;
//        for (int i = 0; i < POWER_SIZE; ++i) {
//            if (Power1[i] > max)
//                max = Power1[i];
//            if (Power1[i] < min)
//                min = Power1[i];
//            sum += Power1[i];
//        }
//        sum = sum - max - min;
//        max = 0;
//        min = 100;
//        return sum / (POWER_SIZE - 2);
//    } else {
//        sprintf(output2,"        ]");
//        sprintf(output3,"  {%5.2fV}  WAIT: %1d\n", x,maxSize);
//        return 0;
//    }
//}
//void APP_dev::power_Electricity(int state) {
//////----------------------初始化-----------------------////
//    int ibuffer;
//    float value = 0;                                               //平均电压     <=0 error
//    float dValue0 = 0;                                             //1通道模数转换 1通道用于判断电量范围
//    int electricity = 0;                                           //0初始值 1 10电量 2 20电量 3 40电量 4 60电量 5 80电量 6 100电量
//    int scope = 4;                                                 //临界范围
//    bool border = false;                                           //是否在临界范围
//////-------------------采集数据转换---------------------////
//    ioctl(AdcDev, CMD_BIT_SELECTED, 12);
//    ioctl(AdcDev, CMD_PORT_SELECTED, 0);                           //设置通道0
//    int ret = read(AdcDev, &ibuffer, sizeof(ibuffer));             //读ad转换后的数据
////    ret = 1;
////    ibuffer = test1;                                               //test1:电量
//    if (ret > 0) {
//        dValue0 = (float) ((ibuffer * 3.3) / 4095 * 4);            //模数换算
//    } else {
//        return;
//    }
//////--------------------获取平均电压--------------------////
//    if (state != ZT1 && state != ZT2) {                            //判断是否为第一次
//        value = power_average_MIN_MAX(dValue0);                    //电压平均值
//        if (value <= 0) {                                          //存储10组数据
//            return;
//        }
//    } else{
//        value=dValue0;
//    }
//////--------------------计算当前电量-----------------------////
//    if (state == ZT3 || state == ZT1) {                            //充电状态
//        if (value >= CHONG_4) {                                    //充电100
//            electricity = CHARGING_100;
//        } else if (value >= (CHONG_4 - (CHONG_4 - CHONG_3) / scope)) {//充电80-100边界
//            border = true;
//            electricity = CHARGING_80;
//        } else if (value >= CHONG_3) {                             //充电80
//            electricity = CHARGING_80;
//        } else if (value >= (CHONG_3 - (CHONG_3 - CHONG_2) / scope)) {//充电60-80边界
//            border = true;
//            electricity = CHARGING_60;
//        } else if (value >= CHONG_2) {                             //充电60
//            electricity = CHARGING_60;
//        } else if (value >= (CHONG_2 - (CHONG_2 - CHONG_1) / scope)) {//充电40-60边界
//            border = true;
//            electricity = CHARGING_40;
//        } else if (value >= CHONG_1) {                             //充电40
//            electricity = CHARGING_40;
//        } else if (value >= (CHONG_1 - (CHONG_4 - CHONG_1) / (3 * scope))) {//充电20-40边界
//            border = true;
//            electricity = CHARGING_20;
//        } else {                                                   //充电20
//            electricity = CHARGING_20;
//        }
//    } else if (state == ZT4 || state == ZT2) {                     //放电状态
//        if (value >= FANG_4) {                                     //放电100
//            electricity = DISCHARGE_100;
//        } else if (value >= FANG_3) {                              //放电80
//            electricity = DISCHARGE_80;
//        } else if (value >= FANG_2) {                              //放电60
//            electricity = DISCHARGE_60;
//        } else if (value >= FANG_1) {                              //放电40
//            electricity = DISCHARGE_40;
//        } else if (value >= FANG_0) {                              //放电20
//            electricity = DISCHARGE_20;
//        } else {                                                   //放电10
//            electricity = DISCHARGE_10;
//        }
//    } else {
//        return;
//    }
//    sprintf(output2, "->%2d", electricity);
//////--------------------计算显示电量-----------------------////
//    if (electricity == yx_power) {                                 //当前电量与实际电量相同
//        sprintf(output3, ">>%2d]  {%5.2fV}  NO CHANGE\n--------------------------------\n", yx_power, value);
//    } else if (state == ZT3) {                                     //充电
//        if (electricity > yx_power) {                              //电量上升
//            yx_power++;
//            sprintf(output3, ">>%2d]  {%5.2fV}  Charging UP\n--------------------------------\n", yx_power, value);
//        } else {                                                   //电量下降
//            if ((border && (yx_power - 1) == electricity)) {
//                sprintf(output3, ">>%2d]  {%5.2fV}  Charging EDGE\n--------------------------------\n", yx_power,
//                        value);
//            } else {
//                yx_power--;
//                sprintf(output3, ">>%2d]  {%5.2fV}  Charging DOWN\n--------------------------------\n", yx_power,
//                        value);
//            }
//        }
//    } else if (state == ZT4) {                                     //放电
//        if (electricity > yx_power) {                              //电量上升
//            sprintf(output3, ">>%2d]  {%5.2fV}  Discharge UP\n--------------------------------\n", yx_power, value);
//        } else {                                                   //电量下降
//            yx_power--;
//            sprintf(output3, ">>%2d]  {%5.2fV}  Discharge DOWN\n--------------------------------\n", yx_power, value);
//        }
//    } else {                                                       //第一次
//        yx_power = electricity;
//        sprintf(output3, ">>%2d]  {%5.2fV}  FIRST\n--------------------------------\n", yx_power, value);
//    }
//}
//void APP_dev::power_SelectDian() {
//    if (AdcDev > 0 && !power_Stop()) {
//        int state = power_State();
//        if (state == 0) {
//            power_average_MIN_MAX(0);
//            sprintf(output, "%s%s%s", output1, output2, output3);
//        } else if (state > 0) {
//            power_Electricity(state);
//            sprintf(output, "%s%s%s", output1, output2, output3);
//        }
//    } else
//        sprintf(output, "There is no data\n");
//
//    printf("%s", output);
////    pc_wr_data(output);
//}
//
