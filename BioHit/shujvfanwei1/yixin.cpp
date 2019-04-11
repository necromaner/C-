//
// Created by necromaner on 2019-03-15.
//

#include "yixin.h"
static bool getdat = false;
void PctGuiThread::AnalyValue() {
    while (!getdat) {//判断是否获得数据
        Delayms(100);
    }

    getdat = false;
    AglDeviceP->agl_calc_vol(AnaFound);                 //计算结果
//    if(isCalc == false || AglDeviceP->isCardError == true)
//    {
//        return;
//    }

//------Add-------------------------------------------------------------------------------------------------------------//
//    TextDat = AglDeviceP->GetConfig("Test_sam");
//    sprintf(dat, "%-18.18s", TextDat.toStdString().data());
//    TextDat = dat;
//    TextShow += TextDat;
//    TextDat = Str_Pre;
//    sprintf(dat, "%-31.31s", TextDat.toLatin1().data());
//    TextDat = dat;
//    TextShow += TextDat;
//------------------------------------------------------------------------------------------------------------------------//
    QString res_ref = AglDeviceP->GetConfig("res_ref");
    TextDat = res_ref;
    sprintf(dat, "%52.52s", TextDat.toLatin1().data());
    TextDat = dat;
    TextShow += TextDat + "\r\n";

    if ((int) AglDeviceP->AglDev.ChxVol == 1)                                          // 如果是单卡 结果显示
    {
        QString Limit;
        bool ok = false;
        double Gas1 = AglDeviceP->AglDev.AdcCalc[0].YSumVol;
        double Ref_Low = AnaFound.XiangMuPm[0].anongduzhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para anongduzhi Error!";
            return;
        }
        double Ref_Hight = AnaFound.XiangMuPm[0].bnongduzhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para bnongduzhi Error!";
            return;
        }
        double C_Low = AnaFound.XiangMuPm[0].czuidizhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para czuidizhi Error!";
            return;
        }
        double C_Hight = AnaFound.XiangMuPm[0].czuigaozhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para czuigaozhi Error!";
            return;
        }
        double Show_Limit = AnaFound.XiangMuPm[0].nongdudizhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para czuigaozhi Error!";
            return;
        }
        double Show_Max = AnaFound.XiangMuPm[0].nongdugaozhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para czuigaozhi Error!";
            return;
        }

        TextDat = AnaFound.XiangMuPm[0].xiangmu;           // "Pepsinogen I";
        sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
        TextDat = dat;
        TextShow += TextDat;
        if (AglDeviceP->Card_index[0] == true) {
//            isPG1Error = true;
            Limit = "";
            OBX_8 = "L";
            OBX_5 = AglDeviceP->GetConfig("res_Err");          // "Error";
            gas1 = OBX_5;
            OBX_4 = AnaFound.XiangMuPm[0].xiangmu;            // "Pepsinogen I";
            OBX_6 = AnaFound.XiangMuPm[0].xiangmudanwei;      // "ng/ml";
            if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                OBX_7 = "<" + AnaFound.XiangMuPm[0].bnongduzhi; // "30-160";
            } else if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                OBX_7 = AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi; // "30-160";
            }
            TextDat = gas1 + " " + Limit;
            sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat;
            QString limt1 = OBX_7;
            TextDat = limt1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei; // "ng/ml";
            sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat + "\r\n";

//            CSV_information += OBX_5 + "#";
        } else {
            if (AglDeviceP->AglDev.AdcCalc[0].CPeakVol < C_Low || AglDeviceP->AglDev.AdcCalc[0].CPeakVol > C_Hight) {
//                isPG1Invalid  = true;
                Limit = "";
                OBX_8 = "L";
                OBX_5 = AglDeviceP->GetConfig("res_invalid");       // "Invalid";
                gas1 = OBX_5;
                OBX_4 = AnaFound.XiangMuPm[0].xiangmu;            // "Pepsinogen I";
                OBX_6 = AnaFound.XiangMuPm[0].xiangmudanwei;      // "ng/ml";
                if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    OBX_7 = "<" + AnaFound.XiangMuPm[0].bnongduzhi; // "30-160";
                } else if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    OBX_7 = AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi; // "30-160";
                }
                TextDat = gas1 + " " + Limit;
                sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat;
                QString limt1 = OBX_7;
                TextDat = limt1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei;; // "ng/ml";
                sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat + "\r\n";

//                CSV_information += OBX_5 + "#";
            } else {
                if (Gas1 < Show_Limit) {
                    Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                    OBX_8 = "L"; // 结果标志L-偏低H-偏高N-正常
                    OBX_5 = "< " + AnaFound.XiangMuPm[0].nongdudizhi;
                    gas1 = OBX_5;
                } else if (Gas1 > Show_Max) {
                    Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                    OBX_8 = "L"; // 结果标志L-偏低H-偏高N-正常
                    OBX_5 = "> " + AnaFound.XiangMuPm[0].nongdugaozhi;
                    gas1 = OBX_5;
                } else {
                    if (Gas1 < Ref_Low) {
                        Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                        OBX_8 = "L"; // 结果标志L-偏低H-偏高N-正常
                        if (Gas1 >= 100) {
                            sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                        } else {
                            sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                        }
                        OBX_5 = (QString) dat;
                        gas1 = dat;
                    } else if (Gas1 > Ref_Hight) {
                        Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                        OBX_8 = "H"; // 结果标志L-偏低H-偏高N-正常
                        if (Gas1 >= 100) {
                            sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                        } else {
                            sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                        }
                        OBX_5 = (QString) dat;
                        gas1 = dat;
                    } else {
                        Limit = " ";  // " *";
                        OBX_8 = "N"; // 结果标志L-偏低H-偏高N-正常
                        if (Gas1 >= 100) {
                            sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                        } else {
                            sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                        }
                        OBX_5 = (QString) dat;
                        gas1 = dat;
                    }
                }

                if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    OBX_4 = AnaFound.XiangMuPm[0].xiangmu;   // "Pepsinogen I";
                    OBX_6 = AnaFound.XiangMuPm[0].xiangmudanwei;  // "ng/ml";
                    OBX_7 = "<" + AnaFound.XiangMuPm[0].bnongduzhi;   // "30-160";
                    TextDat = gas1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // "ng/ml"
                    sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat;
                    QString limt1 = OBX_7;
                    TextDat = limt1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei;   // "ng/ml";
                    sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat + "\r\n";
                } else if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    OBX_4 = AnaFound.XiangMuPm[0].xiangmu;   // "Pepsinogen I";
                    OBX_6 = AnaFound.XiangMuPm[0].xiangmudanwei;  // "ng/ml";
                    OBX_7 = AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi;   // "30-160";
                    TextDat = gas1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // "ng/ml"
                    sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat;
                    QString limt1 = OBX_7;
                    TextDat = limt1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei;   // "ng/ml";
                    sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat + "\r\n";
                }
//                TextShow += "\r\n"+AglDeviceP->GetConfig("report_oper");
//                TextShow += " "+ LoginUserName;
//                TextShow += "       " + AglDeviceP->GetConfig("Repotr_LOT");
//                TextShow += " " + AnaFound.Pihao;
            }
        }
        TextShow += "\r\n" + AglDeviceP->GetConfig("report_oper");
        TextShow += " " + LoginUserName;

        TextShow += "       " + AglDeviceP->GetConfig("Repotr_LOT");
        TextShow += " " + AnaFound.Pihao;
//--------------------------------------------------------------Add to Record CSV---------------------------------------------------------------//
        QString Model = QString::number((int) AglDeviceP->AglDev.ChxVol, 10);
        QDateTime time = QDateTime::currentDateTime();
        QString now = time.toString("yyyy-MM-dd hh:mm:ss") + ";" + Model + ";" + Str_Pre;

        strcpy(RES_Data.Date, now.toLatin1().data());

        QStringList CSVDateList = now.split(";");
        if (CSVDateList.length() != 3) {
            qDebug() << "20398 CSV Date information Error!";
        }

        QString CSVRecordDate = CSVDateList.at(0);

        QString TValue_Str = QString::number(AglDeviceP->AglDev.AdcCalc[0].TPeakVol);
        QString CValue_Str = QString::number(AglDeviceP->AglDev.AdcCalc[0].CPeakVol);

        CSV_information += "1," + LineSam + "," + AnaFound.XiangMuPm[0].xiangmu + "," + OBX_5 + "," +
                           AnaFound.XiangMuPm[0].xiangmudanwei + "," + OBX_7 + ","
                           + TValue_Str + "," + CValue_Str + "," + AnaFound.Pihao + "," + CSVRecordDate + ";";
//------------------------------------------------------------------------------------------------------------------------------------------------------//
    } else if ((int) AglDeviceP->AglDev.ChxVol == 4)          // 如果是4卡 结果显示
    {
        CSV_information += "4," + LineSam + ",";
        double Gas1 = AglDeviceP->AglDev.AdcCalc[0].YSumVol;
        double Gas2 = AglDeviceP->AglDev.AdcCalc[1].YSumVol;
        double Gas3 = AglDeviceP->AglDev.AdcCalc[2].YSumVol;
        double Gas4 = AglDeviceP->AglDev.AdcCalc[3].YSumVol;

        double Gas1_Gas2 = 0;
        if (Gas2 == 0) {
            Gas1_Gas2 = 0;
        } else {
            Gas1_Gas2 = Gas1 / Gas2;
        }

        bool ok = false;
        double Ref_Hight[4] = {0};
        double Ref_Low[4] = {0};

        double C_Hight[4] = {0};
        double C_Low[4] = {0};

        double Show_Limit[4] = {0};
        double Show_Max[4] = {0};

        for (int i = 0; i < 4; i++) {
            Ref_Low[i] = AnaFound.XiangMuPm[i].anongduzhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para anongduzhi Error!";
                return;
            }
            Ref_Hight[i] = AnaFound.XiangMuPm[i].bnongduzhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para bnongduzhi Error!";
                return;
            }
            C_Low[i] = AnaFound.XiangMuPm[i].czuidizhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para czuidizhi Error!";
                return;
            }
            C_Hight[i] = AnaFound.XiangMuPm[i].czuigaozhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para czuigaozhi Error!";
                return;
            }
            Show_Limit[i] = AnaFound.XiangMuPm[i].nongdudizhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para czuigaozhi Error!";
                return;
            }
            Show_Max[i] = AnaFound.XiangMuPm[i].nongdugaozhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para czuigaozhi Error!";
                return;
            }
        }

        QString Limit;
        bool isPG1Error = false;
        bool isPG2Error = false;

        bool isPG1Invalid = false;
        bool isPG2Invalid = false;
        bool isG17Invalid = false;
        bool isHpInvalid = false;
//--------------------------PG1-------------------------//
        TextDat = AnaFound.XiangMuPm[0].xiangmu;           // "Pepsinogen I";
        CSV_information += TextDat + ",";
        sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
        TextDat = dat;
        TextShow += TextDat;

        if (AglDeviceP->Card_index[0] == true) {
            isPG1Error = true;
            Limit = "";
            OBX_8 = "L";
            OBX_5 = AglDeviceP->GetConfig("res_Err");          // "Error";
            gas1 = OBX_5;
            OBX_4 = AnaFound.XiangMuPm[0].xiangmu;            // "Pepsinogen I";
            OBX_6 = AnaFound.XiangMuPm[0].xiangmudanwei;      // "ng/ml";
            if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                OBX_7 = "<" + AnaFound.XiangMuPm[0].bnongduzhi; // "30-160";
            } else if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                OBX_7 = AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi; // "30-160";
            }
            TextDat = gas1 + " " + Limit;
            sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat;
            QString limt1 = OBX_7;
            TextDat = limt1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei; // "ng/ml";
            sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat + "\r\n";

//            CSV_information += OBX_5 + "#";
        } else {
            if (AglDeviceP->AglDev.AdcCalc[0].CPeakVol < C_Low[0] ||
                AglDeviceP->AglDev.AdcCalc[0].CPeakVol > C_Hight[0]) {
                isPG1Invalid = true;
                Limit = "";
                OBX_8 = "L";
                OBX_5 = AglDeviceP->GetConfig("res_invalid");       // "Invalid";
                gas1 = OBX_5;
                OBX_4 = AnaFound.XiangMuPm[0].xiangmu;            // "Pepsinogen I";
                OBX_6 = AnaFound.XiangMuPm[0].xiangmudanwei;      // "ng/ml";
                if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    OBX_7 = "<" + AnaFound.XiangMuPm[0].bnongduzhi; // "30-160";
                } else if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    OBX_7 = AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi; // "30-160";
                }
                TextDat = gas1 + " " + Limit;
                sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat;
                QString limt1 = OBX_7;
                TextDat = limt1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei;; // "ng/ml";
                sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat + "\r\n";

//                CSV_information += OBX_5 + "#";
            } else {
                if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    if (Gas1 < Show_Limit[0]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "L";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5 = "< " + AnaFound.XiangMuPm[0].nongdudizhi;
                        gas1 = OBX_5;
                    } else if (Gas1 > Show_Max[0]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "H";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5 = "> " + AnaFound.XiangMuPm[0].nongdugaozhi;
                        gas1 = OBX_5;
                    } else {
                        if (Gas1 > Ref_Hight[0]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                            OBX_8 = "H";                              // 结果标志L-偏低H-偏高N-正常
                            if (Gas1 >= 100) {
                                sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5 = (QString) dat;
                            gas1 = dat;
                        } else {
                            Limit = " "; // " *";
                            OBX_8 = "N";                              // 结果标志L-偏低H-偏高N-正常
                            if (Gas1 >= 100) {
                                sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5 = (QString) dat;
                            gas1 = dat;
                        }
                    }

                    OBX_4 = AnaFound.XiangMuPm[0].xiangmu;   // "Pepsinogen I";
                    OBX_6 = AnaFound.XiangMuPm[0].xiangmudanwei;  // "ng/ml";
                    OBX_7 = "<" + AnaFound.XiangMuPm[0].bnongduzhi;   // "30-160";

                    TextDat = gas1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // "ng/ml"
                    sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat;
                    QString limt1 = OBX_7;

                    TextDat = limt1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei;   // "ng/ml";
                    sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat + "\r\n";
                } else if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    if (Gas1 < Show_Limit[0]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "L";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5 = "< " + AnaFound.XiangMuPm[0].nongdudizhi;
                        gas1 = OBX_5;
                    } else if (Gas1 > Show_Max[0]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "H";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5 = "> " + AnaFound.XiangMuPm[0].nongdugaozhi;
                        gas1 = OBX_5;
                    } else {
                        if (Gas1 < Ref_Low[0]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                            OBX_8 = "L"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas1 >= 100) {
                                sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5 = (QString) dat;
                            gas1 = dat;
                        } else if (Gas1 > Ref_Hight[0]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                            OBX_8 = "H"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas1 >= 100) {
                                sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5 = (QString) dat;
                            gas1 = dat;
                        } else {
                            Limit = " ";  // " *";
                            OBX_8 = "N"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas1 >= 100) {
                                sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas1); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5 = (QString) dat;
                            gas1 = dat;
                        }
                    }

                    OBX_4 = AnaFound.XiangMuPm[0].xiangmu;   // "Pepsinogen I";
                    OBX_6 = AnaFound.XiangMuPm[0].xiangmudanwei;  // "ng/ml";
                    OBX_7 = AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi;   // "30-160";

                    TextDat = gas1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // "ng/ml"
                    sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat;
                    QString limt1 = OBX_7;

                    TextDat = limt1 + " " + AnaFound.XiangMuPm[0].xiangmudanwei;   // "ng/ml";
                    sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat + "\r\n";
                }
            }
        }

        QString TValue_Str = QString::number(AglDeviceP->AglDev.AdcCalc[0].TPeakVol);
        QString CValue_Str = QString::number(AglDeviceP->AglDev.AdcCalc[0].CPeakVol);
        CSV_information +=
                OBX_5 + "," + AnaFound.XiangMuPm[0].xiangmudanwei + "," + OBX_7 + "," + TValue_Str + "," + CValue_Str +
                ",";
//----------------------------PG2------------------------//
        TextDat = AnaFound.XiangMuPm[1].xiangmu;  // "Pepsinogen II";
        CSV_information += TextDat + ",";
        sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
        TextDat = dat;
        TextShow += TextDat;

        if (AglDeviceP->Card_index[1] == true) {
            isPG2Error = true;
            Limit = "";
            OBX_8_1 = "L";
            OBX_5_1 = AglDeviceP->GetConfig("res_Err");  // "Error";
            gas1 = OBX_5_1;
            OBX_4_1 = AnaFound.XiangMuPm[1].xiangmu; // "Pepsinogen II";
            OBX_6_1 = AnaFound.XiangMuPm[1].xiangmudanwei;  // "ng/ml";
            if ("<A" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                OBX_7 = "<" + AnaFound.XiangMuPm[1].bnongduzhi; // "3-15";
            } else if ("A-B" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                OBX_7 = AnaFound.XiangMuPm[1].anongduzhi + "-" + AnaFound.XiangMuPm[1].bnongduzhi; // "3-15";
            }

            TextDat = gas1 + " " + Limit;
            sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat;
            QString limt2 = OBX_7_1;
            TextDat = limt2 + " " + AnaFound.XiangMuPm[1].xiangmudanwei;   // "ng/ml";
            sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat + "\r\n";

//            CSV_information += OBX_5_1 + "#";
        } else {
            if (AglDeviceP->AglDev.AdcCalc[1].CPeakVol < C_Low[1] ||
                AglDeviceP->AglDev.AdcCalc[1].CPeakVol > C_Hight[1]) {
                isPG2Invalid = true;
                Limit = "";
                OBX_8_1 = "L";
                OBX_5_1 = AglDeviceP->GetConfig("res_invalid");  // "Invalid";
                gas1 = OBX_5_1;
                OBX_4_1 = AnaFound.XiangMuPm[1].xiangmu; // "Pepsinogen II";
                OBX_6_1 = AnaFound.XiangMuPm[1].xiangmudanwei;  // "ng/ml";
                if ("<A" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                    OBX_7_1 = "<" + AnaFound.XiangMuPm[1].bnongduzhi; // "3-15";
                } else if ("A-B" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                    OBX_7_1 = AnaFound.XiangMuPm[1].anongduzhi + "-" + AnaFound.XiangMuPm[1].bnongduzhi; // "3-15";
                }

                TextDat = gas1 + " " + Limit;
                sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat;
                QString limt2 = OBX_7_1;
                TextDat = limt2 + " " + AnaFound.XiangMuPm[1].xiangmudanwei;  // "ng/ml";
                sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat + "\r\n";

//                CSV_information += OBX_5_1 + "#";
            } else {
                if ("<A" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                    if (Gas2 < Show_Limit[1]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "L";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_1 = "< " + AnaFound.XiangMuPm[1].nongdudizhi;
                        gas2 = OBX_5_1;
                    } else if (Gas2 > Show_Max[1]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "H";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_1 = "> " + AnaFound.XiangMuPm[1].nongdugaozhi;
                        gas2 = OBX_5_1;
                    } else {
                        if (Gas2 > Ref_Hight[1]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                            OBX_8_1 = "H";                              // 结果标志L-偏低H-偏高N-正常
                            if (Gas2 >= 100) {
                                sprintf(dat, "%-4.2f", Gas2); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas2); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_1 = (QString) dat;
                            gas2 = dat;
                        } else {
                            Limit = " "; // " *";
                            OBX_8_1 = "N";                              // 结果标志L-偏低H-偏高N-正常
                            if (Gas2 >= 100) {
                                sprintf(dat, "%-4.2f", Gas2); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas2); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_1 = (QString) dat;
                            gas2 = dat;
                        }
                    }

                    OBX_4_1 = AnaFound.XiangMuPm[1].xiangmu;   // "Pepsinogen I";
                    OBX_6_1 = AnaFound.XiangMuPm[1].xiangmudanwei;  // "ng/ml";
                    OBX_7_1 = "<" + AnaFound.XiangMuPm[1].bnongduzhi;   // "30-160";

                    TextDat = gas2 + " " + AnaFound.XiangMuPm[1].xiangmudanwei + Limit;  // "ng/ml"
                    sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat;
                    QString limt1 = OBX_7_1;
                    TextDat = limt1 + " " + AnaFound.XiangMuPm[1].xiangmudanwei;   // "ng/ml";
                    sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat + "\r\n";
                } else if ("A-B" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                    if (Gas2 < Show_Limit[1]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "L";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_1 = "< " + AnaFound.XiangMuPm[1].nongdudizhi;
                        gas2 = OBX_5_1;
                    } else if (Gas2 > Show_Max[1]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "H";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_1 = "> " + AnaFound.XiangMuPm[1].nongdugaozhi;
                        gas2 = OBX_5_1;
                    } else {
                        if (Gas2 < Ref_Low[1]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                            OBX_8_1 = "L"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas2 >= 100) {
                                sprintf(dat, "%-4.2f", Gas2); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas2); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_1 = (QString) dat;
                            gas2 = dat;
                        } else if (Gas2 > Ref_Hight[1]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                            OBX_8_1 = "H"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas2 >= 100) {
                                sprintf(dat, "%-4.2f", Gas2); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas2); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_1 = (QString) dat;
                            gas2 = dat;
                        } else {
                            Limit = " ";  // " *";
                            OBX_8 = "N"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas2 >= 100) {
                                sprintf(dat, "%-4.2f", Gas2); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas2); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5 = (QString) dat;
                            gas2 = dat;
                        }
                    }

                    qDebug() << "========= " << gas2;

                    OBX_4_1 = AnaFound.XiangMuPm[1].xiangmu;   // "Pepsinogen I";
                    OBX_6_1 = AnaFound.XiangMuPm[1].xiangmudanwei;  // "ng/ml";
                    OBX_7_1 = AnaFound.XiangMuPm[1].anongduzhi + "-" + AnaFound.XiangMuPm[1].bnongduzhi;   // "30-160";

                    TextDat = gas2 + " " + AnaFound.XiangMuPm[1].xiangmudanwei + Limit;  // "ng/ml"
                    sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat;
                    QString limt1 = OBX_7_1;
                    TextDat = limt1 + " " + AnaFound.XiangMuPm[1].xiangmudanwei;   // "ng/ml";
                    sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat + "\r\n";
                }
            }
        }
        TValue_Str = QString::number(AglDeviceP->AglDev.AdcCalc[1].TPeakVol);
        CValue_Str = QString::number(AglDeviceP->AglDev.AdcCalc[1].CPeakVol);
        CSV_information +=
                OBX_5_1 + "," + AnaFound.XiangMuPm[1].xiangmudanwei + "," + OBX_7_1 + "," + TValue_Str + "," +
                CValue_Str + ",";
//--------------------------PG1/PG2------------------------//
        TextDat = AglDeviceP->GetConfig("Print_Item3");  // "Pepsinogen I/II";
        CSV_information += TextDat + ",";
        sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
        TextDat = dat;
        TextShow += TextDat;

        double dizhi1_2 = Ref_Low[0] / Ref_Hight[1];
        double gaozhi1_2 = Ref_Hight[0] / Ref_Low[1];

        QString dizhi_str = QString::number((int) dizhi1_2);
        QString gaozhi_str = QString::number((int) gaozhi1_2);
        if (isPG1Error == true || isPG2Error == true) {
            Limit = "";
            OBX_8_b = "L";
            OBX_5_b = AglDeviceP->GetConfig("res_Err");  // "Error";
            gas1 = OBX_5_b;

            OBX_4_b = AglDeviceP->GetConfig("Print_Item3"); // "Pepsinogen I/II";
            OBX_6_b = " ";
            OBX_7_b = dizhi_str + "-" + gaozhi_str; // "3-20";

            TextDat = gas1 + Limit;
            sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat;
            QString limt3 = OBX_7_b;
            TextDat = limt3;
            sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat + "\r\n";
        } else {
            //--------------------------------------------------PGI/II Invalid-------------------------------------------------//
            if (isPG1Invalid == true || isPG2Invalid == true) {
                Limit = "";
                OBX_8_b = "L";
                OBX_5_b = AglDeviceP->GetConfig("res_invalid");  // "Invalid";
                gas1 = OBX_5_b;

                OBX_4_b = AglDeviceP->GetConfig("Print_Item3");  // "Pepsinogen I/II";
                OBX_6_b = " ";
                OBX_7_b = dizhi_str + "-" + gaozhi_str; // "3-20";

                TextDat = gas1 + Limit;
                sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat;
                QString limt3 = OBX_7_b;
                TextDat = limt3;
                sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat + "\r\n";
            } else {
                if (0 == Gas1_Gas2) {
                    Limit = "";
                    OBX_8_b = "L";
                    OBX_5_b = AglDeviceP->GetConfig("res_invalid");  // "Invalid";
                    gas1 = OBX_5_b;

                    OBX_4_b = AglDeviceP->GetConfig("Print_Item3");  // "Pepsinogen I/II";
                    OBX_6_b = " ";
                    OBX_7_b = dizhi_str + "-" + gaozhi_str; // "3-20";

                    TextDat = gas1 + Limit;
                    sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat;
                    QString limt3 = OBX_7_b;
                    TextDat = limt3;
                    sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat + "\r\n";
                } else if (Gas1_Gas2 < dizhi1_2) {
                    Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                    OBX_8_b = "L"; // 结果标志L-偏低H-偏高N-正常
                    if (Gas1 >= 100) {
                        sprintf(dat, "%-4.2f", Gas1_Gas2); //sprintf(dat, "%-4.4f", Gas1);
                    } else {
                        sprintf(dat, "%-4.2f", Gas1_Gas2); //sprintf(dat, "%-4.4f", Gas1);
                    }
                    OBX_5_b = (QString) dat;
                    gas2 = dat;
                } else if (Gas1_Gas2 > gaozhi1_2) {
                    Limit = "" + AglDeviceP->GetConfig("DORR");  // " *";
                    OBX_8_b = "H"; // 结果标志L-偏低H-偏高N-正常
                    if (Gas1_Gas2 >= 100) {
                        sprintf(dat, "%-4.2f", Gas1_Gas2); //sprintf(dat, "%-4.4f", Gas1);
                    } else {
                        sprintf(dat, "%-4.2f", Gas1_Gas2); //sprintf(dat, "%-4.4f", Gas1);
                    }
                    OBX_5_b = (QString) dat;
                    gas2 = dat;
                } else {
                    Limit = " ";  // " *";
                    OBX_8_b = "N"; // 结果标志L-偏低H-偏高N-正常
                    if (Gas1_Gas2 >= 100) {
                        sprintf(dat, "%-4.2f", Gas1_Gas2); //sprintf(dat, "%-4.4f", Gas1);
                    } else {
                        sprintf(dat, "%-4.2f", Gas1_Gas2); //sprintf(dat, "%-4.4f", Gas1);
                    }
                    OBX_5_b = (QString) dat;
                    gas2 = dat;
                }

                OBX_4_b = AglDeviceP->GetConfig("Print_Item3");   // "Pepsinogen I";
                OBX_6_b = "";  // "ng/ml";
                OBX_7_b = dizhi_str + "-" + gaozhi_str;   // "30-160";

                TextDat = gas2 + " " + Limit;  // "ng/ml"
                sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat;
                QString limt1 = OBX_7_b;
                TextDat = limt1 + " ";   // "ng/ml";
                sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat + "\r\n";
            }
//               CSV_information += OBX_5_b + "#";
        }
        CSV_information += OBX_5_b + "," + OBX_7_b + ",";

        //----------------------------G17--------------------------//
        TextDat = AnaFound.XiangMuPm[3].xiangmu;  // "Gastrin-17";
        CSV_information += TextDat + ",";
        sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
        TextDat = dat;
        TextShow += TextDat;

        if (AglDeviceP->Card_index[3] == true) {
            Limit = "";
            OBX_8_2 = "L";
            OBX_5_2 = AglDeviceP->GetConfig("res_Err");  // "Error";
            gas3 = OBX_5_2;

            OBX_4_2 = AnaFound.XiangMuPm[3].xiangmu;  // "Gastrin-17B";
            OBX_6_2 = AnaFound.XiangMuPm[3].xiangmudanwei;  // "pmol/l";
            if ("A-B" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                OBX_7_2 = AnaFound.XiangMuPm[3].anongduzhi + "-" + AnaFound.XiangMuPm[3].bnongduzhi;  // "1-7";
            } else if ("<A" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                OBX_7_2 = "<" + AnaFound.XiangMuPm[3].bnongduzhi;  // "1-7";
            }


            TextDat = gas3 + " " + Limit;
            sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat;
            QString limt4 = OBX_7_2;

            TextDat = limt4 + " " + AnaFound.XiangMuPm[3].xiangmudanwei;  // "pmol/l";
            sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat + "\r\n";

//          CSV_information += OBX_5_2 + "#";
        } else {
            if (AglDeviceP->AglDev.AdcCalc[3].CPeakVol < C_Low[3] ||
                AglDeviceP->AglDev.AdcCalc[3].CPeakVol > C_Hight[3]) {
                isG17Invalid = true;
                Limit = "";
                OBX_8_2 = "L";
                OBX_5_2 = AglDeviceP->GetConfig("res_invalid");  // "Invalid";
                gas3 = OBX_5_2;

                OBX_4_2 = AnaFound.XiangMuPm[3].xiangmu;  // "Gastrin-17B";
                OBX_6_2 = AnaFound.XiangMuPm[3].xiangmudanwei;  // "pmol/l";
                if ("A-B" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                    OBX_7_2 = AnaFound.XiangMuPm[3].anongduzhi + "-" + AnaFound.XiangMuPm[3].bnongduzhi;  // "1-7";
                } else if ("<A" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                    OBX_7_2 = "<" + AnaFound.XiangMuPm[3].bnongduzhi;  // "1-7";
                }

                TextDat = gas3 + " " + Limit;
                sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat;
                QString limt4 = OBX_7_2;

                TextDat = limt4 + " " + AnaFound.XiangMuPm[3].xiangmudanwei; // "pmol/l";
                sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat + "\r\n";

//                CSV_information += OBX_5_2 + "#";
            } else {
                if ("A-B" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                    if (Gas4 < Show_Limit[3]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "L";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_2 = "< " + AnaFound.XiangMuPm[3].nongdudizhi;
                        gas3 = OBX_5_2;
                    } else if (Gas4 > Show_Max[3]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "H";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_2 = "> " + AnaFound.XiangMuPm[3].nongdugaozhi;
                        gas3 = OBX_5_2;
                    } else {
                        if (Gas4 < Ref_Low[3]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                            OBX_8_1 = "L"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas4 >= 100) {
                                sprintf(dat, "%-4.2f", Gas4); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas4); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_2 = (QString) dat;
                            gas3 = dat;
                        } else if (Gas4 > Ref_Hight[3]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                            OBX_8_2 = "H"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas4 >= 100) {
                                sprintf(dat, "%-4.2f", Gas4); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas4); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_2 = (QString) dat;
                            gas3 = dat;
                        } else {
                            Limit = " ";  // " *";
                            OBX_8_2 = "N"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas4 >= 100) {
                                sprintf(dat, "%-4.2f", Gas4); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas4); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_2 = (QString) dat;
                            gas2 = dat;
                        }
                    }

                    OBX_4_2 = AnaFound.XiangMuPm[3].xiangmu;   // "Pepsinogen I";
                    OBX_6_2 = AnaFound.XiangMuPm[3].xiangmudanwei;  // "ng/ml";
                    OBX_7_2 = "<" + AnaFound.XiangMuPm[3].bnongduzhi;   // "30-160";

                    TextDat = gas3 + " " + AnaFound.XiangMuPm[3].xiangmudanwei + Limit;  // "ng/ml"
                    sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat;
                    QString limt1 = OBX_7_2;
                    TextDat = limt1 + " " + AnaFound.XiangMuPm[3].xiangmudanwei;   // "ng/ml";
                    sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat + "\r\n";
                } else if ("<A" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                    if (Gas4 < Show_Limit[3]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "L";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_2 = "< " + AnaFound.XiangMuPm[3].nongdudizhi;
                        gas3 = OBX_5_2;
                    } else if (Gas4 > Show_Max[3]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "H";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_2 = "> " + AnaFound.XiangMuPm[3].nongdugaozhi;
                        gas3 = OBX_5_2;
                    } else {
                        if (Gas4 > Ref_Hight[3]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                            OBX_8_2 = "H";                              // 结果标志L-偏低H-偏高N-正常
                            if (Gas4 >= 100) {
                                sprintf(dat, "%-4.2f", Gas4); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas4); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_2 = (QString) dat;
                            gas3 = dat;
                        } else {
                            Limit = " "; // " *";
                            OBX_8_2 = "N";                              // 结果标志L-偏低H-偏高N-正常
                            if (Gas4 >= 100) {
                                sprintf(dat, "%-4.2f", Gas4); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas4); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_2 = (QString) dat;
                            gas3 = dat;
                        }

                    }

                    OBX_4_2 = AnaFound.XiangMuPm[3].xiangmu;   // "Pepsinogen I";
                    OBX_6_2 = AnaFound.XiangMuPm[3].xiangmudanwei;  // "ng/ml";
                    OBX_7_2 = AnaFound.XiangMuPm[3].anongduzhi + "-" + AnaFound.XiangMuPm[3].bnongduzhi;   // "30-160";

                    TextDat = gas3 + " " + AnaFound.XiangMuPm[1].xiangmudanwei + Limit;  // "ng/ml"
                    sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat;
                    QString limt1 = OBX_7_1;

                    TextDat = limt1 + " " + AnaFound.XiangMuPm[3].xiangmudanwei;   // "ng/ml";
                    sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat + "\r\n";
                }
//                CSV_information += OBX_5_2 + "#";
            }
        }
        TValue_Str = QString::number(AglDeviceP->AglDev.AdcCalc[3].TPeakVol);
        CValue_Str = QString::number(AglDeviceP->AglDev.AdcCalc[3].CPeakVol);
        CSV_information +=
                OBX_5_2 + "," + AnaFound.XiangMuPm[3].xiangmudanwei + "," + OBX_7_2 + "," + TValue_Str + "," +
                CValue_Str + ",";
//------------------------------Hp--------------------------//
        TextDat = AnaFound.XiangMuPm[2].xiangmu; // "H.pylori";
        CSV_information += TextDat + ",";
        sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
        TextDat = dat;
        TextShow += TextDat;

        if (AglDeviceP->Card_index[2] == true) {
            Limit = "";
            OBX_8_3 = "N";
            OBX_5_3 = AglDeviceP->GetConfig("res_Err");  // "Error";
            gas4 = OBX_5_3;

            OBX_4_3 = AnaFound.XiangMuPm[2].xiangmu;                            // "H.pylori";
            OBX_6_3 = AnaFound.XiangMuPm[2].xiangmudanwei;                 // "EIU";

            if ("A-B" == AnaFound.XiangMuPm[2].cankaoxingshi) {
                OBX_7_3 = AnaFound.XiangMuPm[2].anongduzhi + "-" + AnaFound.XiangMuPm[2].bnongduzhi;  // "1-7";
            } else if ("<A" == AnaFound.XiangMuPm[2].cankaoxingshi) {
                OBX_7_3 = "<" + AnaFound.XiangMuPm[2].bnongduzhi;  // "1-7";
            }

            TextDat = gas4 + " " + Limit;
            sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat;
            QString limt5 = OBX_7_3;

            TextDat = limt5 + " " + AglDeviceP->GetConfig("HP_Unit"); // "EIU";
            sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
            TextDat = dat;
            TextShow += TextDat + "\r\n";

//          CSV_information += OBX_5_3 + "#";
        } else {
            if (AglDeviceP->AglDev.AdcCalc[2].CPeakVol > C_Hight[2] ||
                AglDeviceP->AglDev.AdcCalc[2].CPeakVol < C_Low[2]) {
                isHpInvalid = true;
                Limit = "";
                OBX_8_3 = "N";
                OBX_5_3 = AglDeviceP->GetConfig("res_invalid");  // "Invalid";
                gas1 = OBX_5_3;

                OBX_4_3 = AnaFound.XiangMuPm[2].xiangmu;                            // "H.pylori";
                OBX_6_3 = AnaFound.XiangMuPm[2].xiangmudanwei;                 // "EIU";

                if ("A-B" == AnaFound.XiangMuPm[2].cankaoxingshi) {
                    OBX_7_3 = AnaFound.XiangMuPm[2].anongduzhi + "-" + AnaFound.XiangMuPm[2].bnongduzhi;  // "1-7";
                } else if ("<A" == AnaFound.XiangMuPm[2].cankaoxingshi) {
                    OBX_7_3 = "<" + AnaFound.XiangMuPm[2].bnongduzhi;  // "1-7";
                }

                TextDat = gas1 + " " + Limit;
                sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat;
                QString limt5 = OBX_7_3;

                TextDat = limt5 + " " + AnaFound.XiangMuPm[2].xiangmudanwei;; // "EIU";
                sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                TextDat = dat;
                TextShow += TextDat + "\r\n";

//                CSV_information += OBX_5_3 + "#";
            } else {
                if ("A-B" == AnaFound.XiangMuPm[2].cankaoxingshi) {
                    if (Gas3 < Show_Limit[2]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "L";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_3 = "< " + AnaFound.XiangMuPm[2].nongdudizhi;
                        gas1 = OBX_5_3;
                    } else if (Gas3 > Show_Max[2]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "H";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_3 = "> " + AnaFound.XiangMuPm[2].nongdugaozhi;
                        gas1 = OBX_5_3;
                    } else {
                        if (Gas3 < Ref_Low[2]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                            OBX_8_1 = "L"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas3 >= 100) {
                                sprintf(dat, "%-4.2f", Gas3); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas3); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_3 = (QString) dat;
                            gas1 = dat;
                        } else if (Gas3 > Ref_Hight[2]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");  // " *";
                            OBX_8_3 = "H"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas3 >= 100) {
                                sprintf(dat, "%-4.2f", Gas3); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas3); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_3 = (QString) dat;
                            gas1 = dat;
                        } else {
                            Limit = " ";  // " *";
                            OBX_8_3 = "N"; // 结果标志L-偏低H-偏高N-正常
                            if (Gas3 >= 100) {
                                sprintf(dat, "%-4.2f", Gas3); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas3); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_3 = (QString) dat;
                            gas1 = dat;
                        }
                    }

                    OBX_4_3 = AnaFound.XiangMuPm[2].xiangmu;   // "Pepsinogen I";
                    OBX_6_3 = AnaFound.XiangMuPm[2].xiangmudanwei;  // "ng/ml";
                    OBX_7_3 = "<" + AnaFound.XiangMuPm[2].bnongduzhi;   // "30-160";

                    TextDat = gas1 + " " + AnaFound.XiangMuPm[2].xiangmudanwei + Limit;  // "ng/ml"
                    sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat;
                    QString limt1 = OBX_7_3;

                    TextDat = limt1 + " " + AnaFound.XiangMuPm[2].xiangmudanwei;   // "ng/ml";
                    sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat + "\r\n";
                } else if ("<A" == AnaFound.XiangMuPm[2].cankaoxingshi) {
                    if (Gas3 < Show_Limit[2]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "L";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_3 = "< " + AnaFound.XiangMuPm[2].nongdudizhi;
                        gas1 = OBX_5_3;
                    } else if (Gas3 > Show_Max[2]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        OBX_8 = "H";                              // 结果标志L-偏低H-偏高N-正常
                        OBX_5_3 = "> " + AnaFound.XiangMuPm[2].nongdugaozhi;
                        gas1 = OBX_5_3;
                    } else {
                        if (Gas3 > Ref_Hight[2]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                            OBX_8_3 = "H";                              // 结果标志L-偏低H-偏高N-正常
                            if (Gas3 >= 100) {
                                sprintf(dat, "%-4.2f", Gas3); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas3); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_3 = (QString) dat;
                            gas1 = dat;
                        } else {
                            Limit = " "; // " *";
                            OBX_8_3 = "N";                              // 结果标志L-偏低H-偏高N-正常
                            if (Gas3 >= 100) {
                                sprintf(dat, "%-4.2f", Gas3); //sprintf(dat, "%-4.4f", Gas1);
                            } else {
                                sprintf(dat, "%-4.2f", Gas3); //sprintf(dat, "%-4.4f", Gas1);
                            }
                            OBX_5_3 = (QString) dat;
                            gas1 = dat;
                        }
                    }

                    OBX_4_3 = AnaFound.XiangMuPm[2].xiangmu;   // "Pepsinogen I";
                    OBX_6_3 = AnaFound.XiangMuPm[2].xiangmudanwei;  // "ng/ml";
                    OBX_7_3 = AnaFound.XiangMuPm[2].anongduzhi + "-" + AnaFound.XiangMuPm[2].bnongduzhi;   // "30-160";

                    TextDat = gas1 + " " + AnaFound.XiangMuPm[2].xiangmudanwei + Limit;  // "ng/ml"
                    sprintf(dat, "%-19.19s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat;
                    QString limt1 = OBX_7_3;

                    TextDat = limt1 + " " + AnaFound.XiangMuPm[2].xiangmudanwei;   // "ng/ml";
                    sprintf(dat, "%-18.18s", TextDat.toLatin1().data());
                    TextDat = dat;
                    TextShow += TextDat + "\r\n";
                }
            }
        }
        TValue_Str = QString::number(AglDeviceP->AglDev.AdcCalc[2].TPeakVol);
        CValue_Str = QString::number(AglDeviceP->AglDev.AdcCalc[2].CPeakVol);
        QString Model = QString::number((int) AglDeviceP->AglDev.ChxVol, 10);
        QDateTime time = QDateTime::currentDateTime();
        QString now = time.toString("yyyy-MM-dd hh:mm:ss") + ";" + Model + ";" + Str_Pre;
        strcpy(RES_Data.Date, now.toStdString().data());

        QStringList CSVDateList = now.split(";");
        if (CSVDateList.length() != 3) {
            qDebug() << "20398 CSV Date information Error!";
        }

        QString CSVRecordDate = CSVDateList.at(0);

        CSV_information +=
                OBX_5_3 + "," + AnaFound.XiangMuPm[2].xiangmudanwei + "," + OBX_7_3 + "," + TValue_Str + "," +
                CValue_Str + "," + AnaFound.Pihao + "," + CSVRecordDate + ";";

        int PG1NAN = isnan(Gas1);
        int PG1INF = isinf(Gas1);
        int PG2NAN = isnan(Gas2);
        int PG2INF = isinf(Gas2);
        int HpNAN = isnan(Gas3);
        int HpINF = isinf(Gas3);
        int G17NAN = isnan(Gas4);
        int G17INF = isinf(Gas4);

        if (PG1NAN || PG1INF || PG2NAN || PG2INF || HpNAN || HpINF || G17NAN || G17INF) {
            isPG1Invalid = true;
        }

        QString End;
        if (isPG1Invalid == true || isPG2Invalid == true || isG17Invalid == true || isHpInvalid == true) {
            End.clear();
        } else {
            std::string Inter = AglDeviceP->GetInterpapreTation(Gas1, Gas2, Gas4, Gas3, Interpretation_post);
            End = QString::fromStdString(Inter);
            End = "";
        }

        if (End.isEmpty() == false) {
            End = "\r\n" + End + "\r\n";
        }
        TextShow += End + "\r\n";

        TextShow += AglDeviceP->GetConfig("report_oper");
        TextShow += " " + LoginUserName;

        TextShow += "       " + AglDeviceP->GetConfig("Repotr_LOT");
        TextShow += " " + AnaFound.Pihao;

//        CSV_information += LoginUserName + "#" + AnaFound.Pihao + "#";
//        if(!(isPG1Invalid == true || isPG2Invalid == true || isG17Invalid == true || isHpInvalid == true))
//        {
//            CSV_information += AglDeviceP->GetCsvInterpretation(Gas1, Gas2, Gas3, Gas4, Interpretation_post);
//        }
    } else if ((int) AglDeviceP->AglDev.ChxVol == 5)          // 如果是5卡 结果显示
    {

    }

//-----Add--------------------------------------------------------------------------------------------------------------------------//
    QString Str_Dat;
    QString SText;
    QString Limit;
    Str_line.clear();

    sprintf(dat, "%-13.13s", (AglDeviceP->GetConfig("Res_Sam")).toStdString().data());
    Str_Dat = dat;
    SText = Str_Dat + SamIDShow;
    Str_line += SText + "\r\n";

    sprintf(dat, "%-13.13s", "Sample");                 // 样本打印乱码
    Str_Dat = dat;
    SText = Str_Dat + Str_Pre;
    Str_line += SText + "\r\n";

    sprintf(dat, "%32.32s", AglDeviceP->GetConfig("Print_Ref").toStdString().data());
    Str_Dat = dat;
    Str_line += Str_Dat + "\r\n";

    if ((int) AglDeviceP->AglDev.ChxVol == 1)    // 打印结果
    {
        //-----------------PG1--------------------//  打印
        SText.clear();
        Str_Dat = AnaFound.XiangMuPm[0].xiangmu;  //"PGI";
        sprintf(dat, "%-8.8s", Str_Dat.toLatin1().data());
        Str_Dat = dat;
        SText += Str_Dat;

        bool ok = false;
        bool isPG1Error = false;
        bool isPG1Invalid = false;
        double Gas1 = AglDeviceP->AglDev.AdcCalc[0].YSumVol;

        double Ref_Low = AnaFound.XiangMuPm[0].anongduzhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para anongduzhi Error!";
            return;
        }
        double Ref_Hight = AnaFound.XiangMuPm[0].bnongduzhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para bnongduzhi Error!";
            return;
        }
        double C_Low = AnaFound.XiangMuPm[0].czuidizhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para czuidizhi Error!";
            return;
        }
        double C_Hight = AnaFound.XiangMuPm[0].czuigaozhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para czuigaozhi Error!";
            return;
        }

        double Show_Limit = AnaFound.XiangMuPm[0].nongdudizhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para czuidizhi Error!";
            return;
        }
        double Show_Max = AnaFound.XiangMuPm[0].nongdugaozhi.toDouble(&ok);
        if (false == ok) {
            qDebug() << "<><><><><><><> QRCode Para czuigaozhi Error!";
            return;
        }

        if (AglDeviceP->Card_index[0] == true) {
            isPG1Error = true;
            Limit = "";
            Str_Dat = AglDeviceP->GetConfig("res_Err") + Limit; // "Error"
            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
            Str_Dat = dat;
            SText += Str_Dat;
            if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                Str_line += SText + AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi +
                            "\r\n";     // "1-7\r\n\r\n";
            } else if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                Str_line += SText + "<" + AnaFound.XiangMuPm[0].bnongduzhi + "\r\n";     // "1-7\r\n\r\n"
            }
        } else {
            if (AglDeviceP->AglDev.AdcCalc[0].CPeakVol < C_Low || AglDeviceP->AglDev.AdcCalc[0].CPeakVol > C_Hight) {
                isPG1Invalid = true;
                Limit = "";
                Str_Dat = AglDeviceP->GetConfig("res_invalid") + Limit; //"Invalid"
                sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                Str_Dat = dat;
                SText += Str_Dat;
                if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    Str_line += SText + AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi +
                                "\r\n";     // "1-7\r\n\r\n";
                } else if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    Str_line += SText + "<" + AnaFound.XiangMuPm[0].bnongduzhi + "\r\n";     // "1-7\r\n\r\n"
                }
            } else {
                if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    QString Show_Str;
                    if (Gas1 < Show_Limit) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = "<" + AnaFound.XiangMuPm[0].nongdudizhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else if (Gas1 > Show_Max) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = ">" + AnaFound.XiangMuPm[0].nongdugaozhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else {
                        if (Gas1 < Ref_Low || Gas1 > Ref_Hight) {
                            Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                            sprintf(dat, "%-4.2f", Gas1);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        } else {
                            Limit = " ";
                            sprintf(dat, "%-4.2f", Gas1);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[0].xiangmudanwei;  // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        }
                    }

                    Str_line += SText + AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi +
                                "\r\n";// "30-160\r\n\r\n";
                } else if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    QString Show_Str;
                    if (Gas1 < Show_Limit) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = "<" + AnaFound.XiangMuPm[0].nongdudizhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else if (Gas1 > Show_Max) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = ">" + AnaFound.XiangMuPm[0].nongdugaozhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else {
                        if (Gas1 > Ref_Hight) {
                            Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                            sprintf(dat, "%-4.2f", Gas1);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        } else {
                            Limit = " ";
                            sprintf(dat, "%-4.2f", Gas1);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[0].xiangmudanwei;  // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        }
                    }
                    Str_line += SText + "<" + AnaFound.XiangMuPm[0].bnongduzhi + "\r\n";// "30-160\r\n\r\n";
                }
            }
        }

        QString Res_inter;
        TC_Value.clear();

        Res_inter = "Operator ID";   // 乱码
        sprintf(dat, "%-13.13s", Res_inter.toLatin1().data());
        Res_inter = dat;
        TC_Value += "\r\n" + Res_inter + LoginUserName;

        Res_inter = AglDeviceP->GetConfig("Print_Lot");
        sprintf(dat, "%-13.13s", Res_inter.toLatin1().data());
        Res_inter = dat;
        TC_Value += "\r\n" + Res_inter + AnaFound.Pihao + "\r\n";

        Str_Flag.clear();
        if (isPG1Error == true) {
            Str_Flag += "T1 = Error";
            Str_Flag += "\r\nC1 = Error";
        } else if (isPG1Invalid == true) {
            Str_Flag += "T1 = Invalid";
            Str_Flag += "\r\nC1 = Invalid";
        } else {
            Str_Flag += "T1 = ";
            double Dou_T0 = AglDeviceP->AglDev.AdcCalc[0].TPeakVol;
            sprintf(dat, "%-4.0f", Dou_T0);    // sprintf(dat, "%-4.2f", Dou_T0);
            Str_Flag += dat;


            Str_Flag += "\r\nC1 = ";
            double Dou_C0 = AglDeviceP->AglDev.AdcCalc[0].CPeakVol;
            sprintf(dat, "%-4.0f", Dou_C0);    // sprintf(dat, "%-4.2f", Dou_C0);
            Str_Flag += dat;
        }
//        if(isRoot == true)
//        {
//            Str_line += "\r\n" + Str_Flag + "\r\n";
//        }
//        qDebug() << "Str_line = " << Str_line;
//        qDebug() << "---------------\r\n " << Str_Flag;
//        Str_line += "\r\n" + Str_Flag;
    }

    if ((int) AglDeviceP->AglDev.ChxVol == 4) {
        SText.clear();
        double Gas1 = AglDeviceP->AglDev.AdcCalc[0].YSumVol;
        double Gas2 = AglDeviceP->AglDev.AdcCalc[1].YSumVol;
        double Gas3 = AglDeviceP->AglDev.AdcCalc[2].YSumVol;  // Hp
        double Gas4 = AglDeviceP->AglDev.AdcCalc[3].YSumVol;  // G17

        double Gas1_Gas2 = 0;
        if (Gas2 != 0) {
            Gas1_Gas2 = Gas1 / Gas2;
        }

        double Ref_Hight[4] = {0};
        double Ref_Low[4] = {0};
        double C_Hight[4] = {0};
        double C_Low[4] = {0};
        double Show_Limit[4] = {0};
        double Show_Max[4] = {0};

        bool ok = false;
        for (int i = 0; i < 4; i++) {
            Ref_Low[i] = AnaFound.XiangMuPm[i].anongduzhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para anongduzhi Error!";
                return;
            }
            Ref_Hight[i] = AnaFound.XiangMuPm[i].bnongduzhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para bnongduzhi Error!";
                return;
            }
            C_Low[i] = AnaFound.XiangMuPm[i].czuidizhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para czuidizhi Error!";
                return;
            }
            C_Hight[i] = AnaFound.XiangMuPm[i].czuigaozhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para czuigaozhi Error!";
                return;
            }
            Show_Limit[i] = AnaFound.XiangMuPm[i].nongdudizhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para czuidizhi Error!";
                return;
            }
            Show_Max[i] = AnaFound.XiangMuPm[i].nongdugaozhi.toDouble(&ok);
            if (false == ok) {
                qDebug() << "<><><><><><><> QRCode Para czuigaozhi Error!";
                return;
            }
        }

        bool isPG1Error = false;
        bool isPG2Error = false;
        bool isPG1Invalid = false;
        bool isPG2Invalid = false;
        bool isHpError = false;
        bool isG17Error = false;
        bool isHpInvalid = false;
        bool isG17Invalid = false;

//-----------------PG1--------------------//  打印
        SText.clear();
        Str_Dat = AnaFound.XiangMuPm[0].xiangmu;  //"PGI";
        sprintf(dat, "%-8.8s", Str_Dat.toLatin1().data());
        Str_Dat = dat;
        SText += Str_Dat;

        if (AglDeviceP->Card_index[0] == true) {
            isPG1Error = true;
            Limit = "";
            Str_Dat = AglDeviceP->GetConfig("res_Err") + Limit; // "Error"
            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
            Str_Dat = dat;
            SText += Str_Dat;
            if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                Str_line += SText + AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi +
                            "\r\n";     // "1-7\r\n\r\n";
            } else if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                Str_line += SText + "<" + AnaFound.XiangMuPm[0].bnongduzhi + "\r\n";     // "1-7\r\n\r\n"
            }

        } else {
            if (AglDeviceP->AglDev.AdcCalc[0].CPeakVol < C_Low[0] ||
                AglDeviceP->AglDev.AdcCalc[0].CPeakVol > C_Hight[0]) {
                isPG1Invalid = true;
                Limit = "";
                Str_Dat = AglDeviceP->GetConfig("res_invalid") + Limit; //"Invalid"
                sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                Str_Dat = dat;
                SText += Str_Dat;
                if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    Str_line += SText + AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi +
                                "\r\n";     // "1-7\r\n\r\n";
                } else if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    Str_line += SText + "<" + AnaFound.XiangMuPm[0].bnongduzhi + "\r\n";     // "1-7\r\n\r\n"
                }

            } else {
                QString Show_Str;
                if ("A-B" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    if (Gas1 < Show_Limit[0]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = "<" + AnaFound.XiangMuPm[0].nongdudizhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else if (Gas1 > Show_Max[0]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = ">" + AnaFound.XiangMuPm[0].nongdugaozhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else {
                        if (Gas1 < Ref_Low[0] || Gas1 > Ref_Hight[0]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                            sprintf(dat, "%-4.2f", Gas1);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        } else {
                            Limit = " ";
                            sprintf(dat, "%-4.2f", Gas1);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[0].xiangmudanwei;  // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        }
                    }

                    Str_line += SText + AnaFound.XiangMuPm[0].anongduzhi + "-" + AnaFound.XiangMuPm[0].bnongduzhi +
                                "\r\n";// "30-160\r\n\r\n";
                } else if ("<A" == AnaFound.XiangMuPm[0].cankaoxingshi) {
                    if (Gas1 < Show_Limit[0]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = "<" + AnaFound.XiangMuPm[0].nongdudizhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else if (Gas1 > Show_Max[0]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = ">" + AnaFound.XiangMuPm[0].nongdugaozhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else {
                        if (Gas1 > Ref_Hight[0]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                            sprintf(dat, "%-4.2f", Gas1);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[0].xiangmudanwei + Limit;  // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        } else {
                            Limit = " ";
                            sprintf(dat, "%-4.2f", Gas1);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[0].xiangmudanwei;  // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        }
                    }

                    Str_line += SText + "<" + AnaFound.XiangMuPm[0].bnongduzhi + "\r\n";// "30-160\r\n\r\n";
                }
            }
        }
//---------------------------PG2-----------------------------//
        SText.clear();
        Str_Dat = AnaFound.XiangMuPm[1].xiangmu;  // "PGII";
        sprintf(dat, "%-8.8s", Str_Dat.toLatin1().data());
        Str_Dat = dat;
        SText += Str_Dat;

        if (AglDeviceP->Card_index[1] == true) {
            isPG2Error = true;
            Limit = "";
            Str_Dat = AglDeviceP->GetConfig("res_Err") + Limit;  // "Error"
            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
            Str_Dat = dat;
            SText += Str_Dat;
            if ("A-B" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                Str_line += SText + AnaFound.XiangMuPm[1].anongduzhi + "-" + AnaFound.XiangMuPm[1].bnongduzhi +
                            "\r\n";     // "1-7\r\n\r\n";
            } else if ("<A" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                Str_line += SText + "<" + AnaFound.XiangMuPm[1].bnongduzhi + "\r\n";     // "1-7\r\n\r\n"
            }
        } else {
            if (AglDeviceP->AglDev.AdcCalc[1].CPeakVol < C_Low[1] ||
                AglDeviceP->AglDev.AdcCalc[1].CPeakVol > C_Hight[1]) {
                isPG2Invalid = true;
                Limit = "";
                Str_Dat = AglDeviceP->GetConfig("res_invalid") + Limit; // "Invalid"
                sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                Str_Dat = dat;
                SText += Str_Dat;

                if ("A-B" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                    Str_line += SText + AnaFound.XiangMuPm[1].anongduzhi + "-" + AnaFound.XiangMuPm[1].bnongduzhi +
                                "\r\n";     // "1-7\r\n\r\n";
                } else if ("<A" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                    Str_line += SText + "<" + AnaFound.XiangMuPm[1].bnongduzhi + "\r\n";     // "1-7\r\n\r\n"
                }

            } else {
                QString Show_Str;
                if ("A-B" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                    if (Gas2 < Show_Limit[1]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = "<" + AnaFound.XiangMuPm[1].nongdudizhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[1].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else if (Gas2 > Show_Max[1]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = ">" + AnaFound.XiangMuPm[1].nongdugaozhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[1].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else {
                        if (Gas2 < Ref_Low[1] || Gas2 > Ref_Hight[1]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                            sprintf(dat, "%-4.2f", Gas2);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[1].xiangmudanwei + Limit;  // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        } else {
                            Limit = " ";
                            sprintf(dat, "%-4.2f", Gas2);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[1].xiangmudanwei;       // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        }
                    }

                    Str_line += SText + AnaFound.XiangMuPm[1].anongduzhi + "-" + AnaFound.XiangMuPm[1].bnongduzhi +
                                "\r\n";   // "3-15\r\n\r\n";
                } else if ("<A" == AnaFound.XiangMuPm[1].cankaoxingshi) {
                    if (Gas2 < Show_Limit[1]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = "<" + AnaFound.XiangMuPm[1].nongdudizhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[1].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else if (Gas2 > Show_Max[1]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = ">" + AnaFound.XiangMuPm[1].nongdugaozhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[1].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else {
                        if (Gas2 > Ref_Hight[1]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                            sprintf(dat, "%-4.2f", Gas2);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[1].xiangmudanwei + Limit;  // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        } else {
                            Limit = " ";
                            sprintf(dat, "%-4.2f", Gas2);//sprintf(dat, "%-4.4f", res1);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[1].xiangmudanwei;       // " ng/ml";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        }
                    }

                    Str_line += SText + "<" + AnaFound.XiangMuPm[1].bnongduzhi + "\r\n";   // "3-15\r\n\r\n";
                }
            }
        }
//---------------------------PG1/2-----------------------------//
        SText.clear();

        double dizhi1_2 = Ref_Low[0] / Ref_Hight[1];
        double gaozhi1_2 = Ref_Hight[0] / Ref_Low[1];

        QString dizhi_str = QString::number((int) dizhi1_2);
        QString gaozhi_str = QString::number((int) gaozhi1_2);

        Str_Dat = AglDeviceP->GetConfig("Print_Item3");  // "PGI/II"
        sprintf(dat, "%-8.8s", Str_Dat.toLatin1().data());
        Str_Dat = dat;
        SText += Str_Dat;

        if (isPG1Error == true || isPG2Error == true) {
            Limit = "";
            Str_Dat = AglDeviceP->GetConfig("res_Err") + Limit;     //  "Error"
            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
            Str_Dat = dat;
            SText += Str_Dat;
        } else {
            if (isPG1Invalid == true || isPG2Invalid == true || Gas1_Gas2 == 0) {
                Limit = "";
                Str_Dat = AglDeviceP->GetConfig("res_invalid") + Limit;   // "Invalid"
                sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                Str_Dat = dat;
                SText += Str_Dat;
                Str_line += SText + dizhi_str + "-" + gaozhi_str + "\r\n";
            } else {
                if (Gas1_Gas2 < dizhi1_2 || Gas1_Gas2 > gaozhi1_2) {
                    Limit = " " + AglDeviceP->GetConfig("DORR");
                } else {
                    Limit = " ";
                }
                sprintf(dat, "%-4.2f", Gas1_Gas2);//sprintf(dat, "%-4.4f", Gas1_Gas2);
                Str_Dat = (QString) dat;
                sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                Str_Dat = dat;
                SText += Str_Dat;
                Str_line += SText + dizhi_str + "-" + gaozhi_str + "\r\n";         // "3-20\r\n\r\n";
            }
        }
//----------------------------G17----------------------------//
        SText.clear();
        Str_Dat = AnaFound.XiangMuPm[3].xiangmu;      // "G17";
        sprintf(dat, "%-8.8s", Str_Dat.toLatin1().data());
        Str_Dat = dat;
        SText += Str_Dat;

        if (AglDeviceP->Card_index[3] == true) {
            isG17Error = true;
            Limit = "";
            Str_Dat = AglDeviceP->GetConfig("res_Err") + Limit;     // "Error"
            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
            Str_Dat = dat;
            SText += Str_Dat;
            if ("A-B" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                Str_line += SText + AnaFound.XiangMuPm[3].anongduzhi + "-" + AnaFound.XiangMuPm[3].bnongduzhi +
                            "\r\n";     // "1-7\r\n\r\n";
            } else if ("<A" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                Str_line += SText + "<" + AnaFound.XiangMuPm[3].bnongduzhi + "\r\n";     // "1-7\r\n\r\n"
            }

        } else {
            if (AglDeviceP->AglDev.AdcCalc[3].CPeakVol < C_Low[3] ||
                AglDeviceP->AglDev.AdcCalc[3].CPeakVol > C_Hight[3]) {
                isG17Invalid = true;
                Limit = "";
                Str_Dat = AglDeviceP->GetConfig("res_invalid") + Limit;  // "Invalid"
                sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                Str_Dat = dat;
                SText += Str_Dat;
                if ("A-B" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                    Str_line += SText + AnaFound.XiangMuPm[3].anongduzhi + "-" + AnaFound.XiangMuPm[3].bnongduzhi +
                                "\r\n";     // "1-7\r\n\r\n";
                } else if ("<A" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                    Str_line += SText + "<" + AnaFound.XiangMuPm[3].bnongduzhi + "\r\n";     // "1-7\r\n\r\n"
                }

            } else {
                QString Show_Str;
                if ("A-B" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                    if (Gas4 < Show_Limit[3]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = "<" + AnaFound.XiangMuPm[3].nongdudizhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[3].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else if (Gas4 > Show_Max[3]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = ">" + AnaFound.XiangMuPm[3].nongdugaozhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[3].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else {
                        if (Gas4 < Ref_Low[3] || Gas4 > Ref_Hight[3]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");        // " *";
                            sprintf(dat, "%-4.2f", Gas4);//sprintf(dat, "%-4.4f", Gas4);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[3].xiangmudanwei + Limit; // " pmol/l";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        } else {
                            Limit = " ";
                            sprintf(dat, "%-4.2f", Gas4);//sprintf(dat, "%-4.4f", Gas4);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[3].xiangmudanwei + Limit; // " pmol/l";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        }
                    }
                    Str_line += SText + AnaFound.XiangMuPm[3].anongduzhi + "-" + AnaFound.XiangMuPm[3].bnongduzhi +
                                "\r\n";     // "1-7\r\n\r\n";
                } else if ("<A" == AnaFound.XiangMuPm[3].cankaoxingshi) {
                    if (Gas4 < Show_Limit[3]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = "<" + AnaFound.XiangMuPm[3].nongdudizhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[3].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else if (Gas4 > Show_Max[3]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = ">" + AnaFound.XiangMuPm[3].nongdugaozhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[3].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else {
                        if (Gas4 > Ref_Hight[3]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");        // " *";
                            sprintf(dat, "%-4.2f", Gas4);//sprintf(dat, "%-4.4f", Gas4);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[3].xiangmudanwei + Limit; // " pmol/l";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        } else {
                            Limit = " ";
                            sprintf(dat, "%-4.2f", Gas4);//sprintf(dat, "%-4.4f", Gas4);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[3].xiangmudanwei + Limit; // " pmol/l";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        }
                    }

                    Str_line += SText + "<" + AnaFound.XiangMuPm[3].bnongduzhi + "\r\n";     // "1-7\r\n\r\n"
                }
            }
        }
//----------------------------Hp-------------------------//
        SText.clear();

        Str_Dat = AnaFound.XiangMuPm[2].xiangmu;          // "Hp";
        sprintf(dat, "%-8.8s", Str_Dat.toLatin1().data());
        Str_Dat = dat;
        SText += Str_Dat;
        if (AglDeviceP->Card_index[2] == true) {
            isHpError = true;
            Limit = "";
            Str_Dat = AglDeviceP->GetConfig("res_Err") + Limit;  // "Error"
            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
            Str_Dat = dat;
            SText += Str_Dat;
        } else {
            if (AglDeviceP->AglDev.AdcCalc[2].CPeakVol < C_Low[2] ||
                AglDeviceP->AglDev.AdcCalc[2].CPeakVol > C_Hight[2]) {
                isHpInvalid = true;
                Limit = "";
                Str_Dat = AglDeviceP->GetConfig("res_invalid") + Limit;    // "Invalid"
                sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                Str_Dat = dat;
                SText += Str_Dat;
            } else {
                QString Show_Str;
                if ("A-B" == AnaFound.XiangMuPm[2].cankaoxingshi) {
                    if (Gas3 < Show_Limit[2]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = "<" + AnaFound.XiangMuPm[2].nongdudizhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[2].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else if (Gas3 > Show_Max[2]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = ">" + AnaFound.XiangMuPm[2].nongdugaozhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[2].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else {
                        if (Gas3 < Ref_Low[2] || Gas3 > Ref_Hight[2]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");        // " *";
                            sprintf(dat, "%-4.2f", Gas3);//sprintf(dat, "%-4.4f", Gas3);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[2].xiangmudanwei + Limit;     // " EIU";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        } else {
                            Limit = " ";
                            sprintf(dat, "%-4.2f", Gas3);//sprintf(dat, "%-4.4f", Gas3);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[2].xiangmudanwei;     // " EIU";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        }
                    }

                    Str_line +=
                            SText + AnaFound.XiangMuPm[2].anongduzhi + "-" + AnaFound.XiangMuPm[2].bnongduzhi + "\r\n";
                } else if ("<A" == AnaFound.XiangMuPm[2].cankaoxingshi) {
                    if (Gas3 < Show_Limit[2]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = "<" + AnaFound.XiangMuPm[2].nongdudizhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[2].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else if (Gas3 > Show_Max[2]) {
                        Limit = " " + AglDeviceP->GetConfig("DORR"); // " *";
                        Show_Str = ">" + AnaFound.XiangMuPm[2].nongdugaozhi;
                        Str_Dat = Show_Str + " " + AnaFound.XiangMuPm[2].xiangmudanwei + Limit;  // " ng/ml";
                        sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                        Str_Dat = dat;
                        SText += Str_Dat;
                    } else {
                        if (Gas3 > Ref_Hight[2]) {
                            Limit = " " + AglDeviceP->GetConfig("DORR");        // " *";
                            sprintf(dat, "%-4.2f", Gas3);//sprintf(dat, "%-4.4f", Gas3);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[2].xiangmudanwei + Limit;     // " EIU";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        } else {
                            Limit = " ";
                            sprintf(dat, "%-4.2f", Gas3);//sprintf(dat, "%-4.4f", Gas3);
                            Str_Dat = (QString) dat + " " + AnaFound.XiangMuPm[2].xiangmudanwei;     // " EIU";
                            sprintf(dat, "%-16.16s", Str_Dat.toLatin1().data());
                            Str_Dat = dat;
                            SText += Str_Dat;
                        }
                    }

                    Str_line += SText + "<" + AnaFound.XiangMuPm[2].bnongduzhi + "\r\n";
                }
            }
        }

        int PG1NAN = isnan(Gas1);
        int PG1INF = isinf(Gas1);
        int PG2NAN = isnan(Gas2);
        int PG2INF = isinf(Gas2);
        int HpNAN = isnan(Gas3);
        int HpINF = isinf(Gas3);
        int G17NAN = isnan(Gas4);
        int G17INF = isinf(Gas4);

        if (PG1NAN || PG1INF || PG2NAN || PG2INF || HpNAN || HpINF || G17NAN || G17INF) {
            isPG1Invalid = true;
        }
        QString Res_inter;
        if (isPG1Invalid == true || isPG2Invalid == true || isG17Invalid == true || isHpInvalid == true) {
            Res_inter.clear();
        } else {
            std::string Inter = AglDeviceP->GetInterpapreTation(Gas1, Gas2, Gas4, Gas3, Interpretation_post);
            Res_inter = QString::fromStdString(Inter);
            Res_inter = "";
//            Res_inter = AglDeviceP->agl_calc_string(Gas1, Gas2, Gas3, Gas4, Interpretation_post);
        }
        if (Res_inter.isEmpty() == false) {
            Res_inter = "\r\n" + Res_inter + "\r\n";
        }
//        if("A-B" == AnaFound.XiangMuPm[2].cankaoxingshi)
//        {
//            Str_line += SText + AnaFound.XiangMuPm[2].anongduzhi + "-" + AnaFound.XiangMuPm[2].bnongduzhi+"\r\n";             // "<30\r\n\r\n";
//        }
//        else if("<A" == AnaFound.XiangMuPm[2].cankaoxingshi)
//        {
//            Str_line += SText + "<" +AnaFound.XiangMuPm[2].bnongduzhi+"\r\n";             // "<30\r\n\r\n";
//        }

        Str_line += Res_inter;
//-----------------------------------------Hp over------------------------------------------//
        TC_Value.clear();
//        Res_inter = AglDeviceP->GetConfig("report_oper");
        Res_inter = "Operator ID";   // 乱码
        sprintf(dat, "%-13.13s", Res_inter.toLatin1().data());
        Res_inter = dat;
        TC_Value += "\r\n" + Res_inter + LoginUserName;

        Res_inter = AglDeviceP->GetConfig("Print_Lot");
        sprintf(dat, "%-13.13s", Res_inter.toLatin1().data());
        Res_inter = dat;
        TC_Value += "\r\n" + Res_inter + AnaFound.Pihao + "\r\n";
//-------------------------T1,C1---------------------------------//
        Str_Flag.clear();
        if (isPG1Error == true) {
            Str_Flag += "T1 = Error";
            Str_Flag += "\r\nC1 = Error";
        }
//        else if(isPG1Invalid == true)
//        {
//            Str_Flag += "T1 = Invalid";
//            Str_Flag += "\r\nC1 = Invalid";
//        }
        else {
            Str_Flag += "T1 = ";
            double Dou_T0 = AglDeviceP->AglDev.AdcCalc[0].TPeakVol;
            sprintf(dat, "%-4.0f", Dou_T0);    // sprintf(dat, "%-4.2f", Dou_T0);
            Str_Flag += dat;


            Str_Flag += "\r\nC1 = ";
            double Dou_C0 = AglDeviceP->AglDev.AdcCalc[0].CPeakVol;
            sprintf(dat, "%-4.0f", Dou_C0);    // sprintf(dat, "%-4.2f", Dou_C0);
            Str_Flag += dat;
        }
//--------------------------T2, C2----------------------------//
        if (isPG2Error == true) {
            Str_Flag += "\r\nT2 = Error";
            Str_Flag += "\r\nC2 = Error";
        }
//        else if(isPG2Invalid == true)
//        {
//            Str_Flag += "\r\nT2 = Invalid";
//            Str_Flag += "\r\nC2 = Invalid";
//        }
        else {
            Str_Flag += "\r\nT2 = ";
            double Dou_T1 = AglDeviceP->AglDev.AdcCalc[1].TPeakVol;
            sprintf(dat, "%-4.0f", Dou_T1);    // sprintf(dat, "%-4.2f", Dou_T1);
            Str_Flag += dat;

            Str_Flag += "\r\nC2 = ";
            double Dou_C1 = AglDeviceP->AglDev.AdcCalc[1].CPeakVol;
            sprintf(dat, "%-4.0f", Dou_C1);  // sprintf(dat, "%-4.2f", Dou_C1);
            Str_Flag += dat;
        }
//------------------------------T3,C3--------------------------------//
        if (isHpError == true) {
            Str_Flag += "\r\nT3 = Error";
            Str_Flag += "\r\nC3 = Error";
        }
//        else if(isHpInvalid == true)
//        {
//            Str_Flag += "\r\nT3 = Invalid";
//            Str_Flag += "\r\nC3 = Invalid";
//        }
        else {
            Str_Flag += "\r\nT3 = ";
            double Dou_T2 = AglDeviceP->AglDev.AdcCalc[2].TPeakVol;
            sprintf(dat, "%-4.0f", Dou_T2); //  sprintf(dat, "%-4.2f", Dou_T2);
            Str_Flag += dat;

            Str_Flag += "\r\nC3 = ";
            double Dou_C2 = AglDeviceP->AglDev.AdcCalc[2].CPeakVol;
            sprintf(dat, "%-4.0f", Dou_C2);//   sprintf(dat, "%-4.2f", Dou_C2);
            Str_Flag += dat;
        }
//------------------------------T4, C4------------------------------//
        if (isG17Error == true) {
            Str_Flag += "\r\nT4 = Error";
            Str_Flag += "\r\nC4 = Error";
        }
//        else if(isG17Invalid == true)
//        {
//            Str_Flag += "\r\nT4 = Invalid";
//            Str_Flag += "\r\nC4 = Invalid";
//        }
        else {
            Str_Flag += "\r\nT4 = ";
            double Dou_T3 = AglDeviceP->AglDev.AdcCalc[3].TPeakVol;
            sprintf(dat, "%-4.0f", Dou_T3);//  sprintf(dat, "%-4.2f", Dou_T3);
            Str_Flag += dat;
            Str_Flag += "\r\nC4 = ";
            double Dou_C3 = AglDeviceP->AglDev.AdcCalc[3].CPeakVol;
            sprintf(dat, "%-4.0f", Dou_C3);//  sprintf(dat, "%-4.2f", Dou_C3);
            Str_Flag += dat;
            Str_Flag += "\r\n";
        }
//        if(isRoot == true)
//        {
//            Str_line += "\r\n" + Str_Flag;
//        }
    }

//------------------------------------------------------------------------------------------------------------------------------------//
    ResText->setText(TextShow);
    double ImageX[2000];
    double ImageY[4][2000];
    for (int i = 0; i < 2000; i++) {
        ImageX[i] = i;
        ImageY[0][i] = 0;
        ImageY[1][i] = 0;
        ImageY[2][i] = 0;
        ImageY[3][i] = 0;
    }

    if ((int) AglDeviceP->AglDev.ChxVol == 1) {
        int DX_c = AglDeviceP->GetPasswd("@C_Distance").toInt();
        if (DX_c < 0) {
            for (int i = 0; i < 1800 + DX_c; i++) {
                AglDeviceP->AglDev.VolBuf[0][i] = AglDeviceP->AglDev.VolBuf[0][i - DX_c];
            }
            for (int i = 1800 + DX_c; i < 1800; i++) {
                AglDeviceP->AglDev.VolBuf[0][i] = AglDeviceP->AglDev.VolBuf[0][1799 + DX_c];
            }
        } else if (DX_c > 0) {
            for (int i = 1799; i > DX_c; i--) {
                AglDeviceP->AglDev.VolBuf[0][i] = AglDeviceP->AglDev.VolBuf[0][i - DX_c];
            }
            for (int i = DX_c; i > 0; i--) {
                AglDeviceP->AglDev.VolBuf[0][i] = AglDeviceP->AglDev.VolBuf[0][0];
            }
        }
        double *DatP = &AglDeviceP->AglDev.VolBuf[0][0];
        for (int i = 0; i < 2000; i++) {
            ImageX[i] = i;
            ImageY[0][i] = DatP[i];
        }
        AyvLine->setSamples((double *) ImageX, (double *) (&ImageY[0][0]), 1800);
        AyvLine->attach(AqwtplotP);
        AqwtplotP->replot();
    } else if ((int) AglDeviceP->AglDev.ChxVol == 4) {
        int DX_c = AglDeviceP->GetPasswd("@C_Distance").toInt();
        if (DX_c < 0) {
            for (int i = 0; i < 1800 + DX_c; i++) {
                AglDeviceP->AglDev.VolBuf[0][i] = AglDeviceP->AglDev.VolBuf[0][i - DX_c];
                AglDeviceP->AglDev.VolBuf[1][i] = AglDeviceP->AglDev.VolBuf[1][i - DX_c];
                AglDeviceP->AglDev.VolBuf[2][i] = AglDeviceP->AglDev.VolBuf[2][i - DX_c];
                AglDeviceP->AglDev.VolBuf[3][i] = AglDeviceP->AglDev.VolBuf[3][i - DX_c];
            }
            for (int i = 1800 + DX_c; i < 1800; i++) {
                AglDeviceP->AglDev.VolBuf[0][i] = AglDeviceP->AglDev.VolBuf[0][1799 + DX_c];
                AglDeviceP->AglDev.VolBuf[1][i] = AglDeviceP->AglDev.VolBuf[1][1799 + DX_c];
                AglDeviceP->AglDev.VolBuf[2][i] = AglDeviceP->AglDev.VolBuf[2][1799 + DX_c];
                AglDeviceP->AglDev.VolBuf[3][i] = AglDeviceP->AglDev.VolBuf[3][1799 + DX_c];
            }
        } else if (DX_c > 0) {
            for (int i = 1799; i > DX_c; i--) {
                AglDeviceP->AglDev.VolBuf[0][i] = AglDeviceP->AglDev.VolBuf[0][i - DX_c];
                AglDeviceP->AglDev.VolBuf[1][i] = AglDeviceP->AglDev.VolBuf[1][i - DX_c];
                AglDeviceP->AglDev.VolBuf[2][i] = AglDeviceP->AglDev.VolBuf[2][i - DX_c];
                AglDeviceP->AglDev.VolBuf[3][i] = AglDeviceP->AglDev.VolBuf[3][i - DX_c];
            }
            for (int i = DX_c; i > 0; i--) {
                AglDeviceP->AglDev.VolBuf[0][i] = AglDeviceP->AglDev.VolBuf[0][0];
                AglDeviceP->AglDev.VolBuf[1][i] = AglDeviceP->AglDev.VolBuf[1][0];
                AglDeviceP->AglDev.VolBuf[2][i] = AglDeviceP->AglDev.VolBuf[2][0];
                AglDeviceP->AglDev.VolBuf[3][i] = AglDeviceP->AglDev.VolBuf[3][0];
            }
        }
        double *DatP0 = &AglDeviceP->AglDev.VolBuf[0][0];
        double *DatP1 = &AglDeviceP->AglDev.VolBuf[1][0];
        double *DatP2 = &AglDeviceP->AglDev.VolBuf[2][0];
        double *DatP3 = &AglDeviceP->AglDev.VolBuf[3][0];
        for (int i = 0; i < 2000; i++) {
            ImageX[i] = i;
            ImageY[0][i] = DatP0[i];  //PG1
            ImageY[1][i] = DatP1[i];  //PG2
            ImageY[2][i] = DatP2[i];  //Hp
            ImageY[3][i] = DatP3[i];  //G17
        }

        AyvLine->setSamples((double *) ImageX, (double *) (&ImageY[0][0]), 1800);
        AyvLine->attach(AqwtplotP);

        ByvLine->setSamples((double *) ImageX, (double *) (&ImageY[1][0]), 1800);
        ByvLine->attach(BqwtplotP);

        CyvLine->setSamples((double *) ImageX, (double *) (&ImageY[2][0]), 1800);
        CyvLine->attach(CqwtplotP);

        DyvLine->setSamples((double *) ImageX, (double *) (&ImageY[3][0]), 1800);
        DyvLine->attach(DqwtplotP);

        AqwtplotP->replot();
        BqwtplotP->replot();
        CqwtplotP->replot();
        DqwtplotP->replot();
    }
    qDebug() << "--------------- 18864 绘图完成";
}


void PctGuiThread::Delayms(uint del)        // 延时函数
{
    QTime now = QTime :: currentTime().addMSecs(del);
    while(QTime :: currentTime() < now);
}
