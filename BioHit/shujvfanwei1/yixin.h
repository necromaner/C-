//
// Created by necromaner on 2019-03-15.
//

#ifndef SHUJVFANWEI1_YIXIN_H
#define SHUJVFANWEI1_YIXIN_H

#include <string>
#include <iostream>
#define QString std::string
#define qDebug() std::cout

typedef struct
{
    QString Head;//YX-
    QString Pihao;//批号
    QString Yiweima;//一维码
    QString Xiangmushuliang;//项目数量
    QString PiLiang;//批量
    QString youxiaoshijian;//有效时间
    QString yanshi;//有效时间
    XiangMuPmStr XiangMuPm[4];
} TwoCodeStr;//二维码参数结构


class PctGuiThread{
public:

    TwoCodeStr AnaFound;
    QString TextDat;
    char dat[50];
    QString TextShow;
    QString OBX_4;  // PG1 项目名称
    QString OBX_5;  // PG1 结果浓度
    QString OBX_6;  // PG1 结果值的单位
    QString OBX_7;  // PG1 参考范围
    QString OBX_8;  // PG1 结果标志L-偏低H-偏高N-正常

    QString OBX_4_1; // PG2 项目名称
    QString OBX_5_1; // PG2 结果浓度
    QString OBX_6_1; // PG2 结果值的单位
    QString OBX_7_1; // PG2参考范围
    QString OBX_8_1; // PG2 结果标志L-偏低H-偏高N-正常

    QString OBX_4_b; // PG1/2 项目名称
    QString OBX_5_b; // PG1/2 结果浓度
    QString OBX_6_b; // PG1/2 结果值的单位
    QString OBX_7_b; // PG1/2 参考范围
    QString OBX_8_b; // PG1/2 结果标志L-偏低H-偏高N-正常

    QString OBX_4_2; // G17 项目名称
    QString OBX_5_2; // G17 结果浓度
    QString OBX_6_2; // G17 结果值的单位
    QString OBX_7_2; // G17 参考范围
    QString OBX_8_2; // G17 结果标志L-偏低H-偏高N-正常

    QString OBX_4_3; // Hp 项目名称
    QString OBX_5_3; // Hp 结果浓度
    QString OBX_6_3; // Hp 结果值的单位
    QString OBX_7_3; // Hp 参考范围
    QString OBX_8_3; // Hp 结果标志L-偏低H-偏高N-正常


    QString gas;
    QString gas1;
    QString gas2;
    QString gas3;
    QString gas4;


    Results RES_Data;

    QString CSV_information;

    QString LineSam;


    QString Str_line;


    QString SamIDShow;
    QString Str_Pre;

    QString TC_Value;

    QString LoginUserName;
    QString Str_Flag;

    TextEdit *ResText;

    QwtPlot  *AqwtplotP;               //坐标系A
    QwtPlot  *BqwtplotP;
    QwtPlot  *CqwtplotP;
    QwtPlot  *DqwtplotP;
    QwtPlotCurve * AyvLine;         //原值曲线
    QwtPlotCurve * ByvLine;         //原值曲线
    QwtPlotCurve * CyvLine;
    QwtPlotCurve * DyvLine;

    APP_dev *AglDeviceP;






    void AnalyValue();

    void Delayms(uint del);
};

#endif //SHUJVFANWEI1_YIXIN_H
