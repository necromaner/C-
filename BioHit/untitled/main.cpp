#include <QString>
#include <QtTest>
#include <agl_dev.h>
#include <yixin.h>
class Test1 : public QObject
{
    Q_OBJECT
public:
    Test1();

    void t1();
    void t2();
private Q_SLOTS:
            void t3();
};

Test1::Test1()
{
}

void Test1::t1()
{
    APP_dev app;
    QString xx1;

//    xx1="@DX 716 | @C_Distance -251 | unmodified";
//    QCOMPARE(xx1,app.TEST41(0,true));
//    xx1="@DX 361 | @C_Distance 107 | unmodified";
//    QCOMPARE(xx1,app.TEST41(1,true));
//    xx1="@DX 358 | @C_Distance 112 | unmodified";
//    QCOMPARE(xx1,app.TEST41(2,true));
//    xx1="@DX 358 | @C_Distance 101 | unmodified";
//    QCOMPARE(xx1,app.TEST41(3,true));

//    xx1="unmodified |     0-    0-  0.0-  0.0- 1508- 1148- 45.0- 29.0-  0.0";
//    QCOMPARE(xx1,app.TEST41(0,false));
//    xx1="unmodified |     0-    0-  0.0-  0.0- 1150-  789-152.0-350.0-  0.0";
//    QCOMPARE(xx1,app.TEST41(1,false));
//    xx1="unmodified |     0-    0-  0.0-  0.0- 1145-  787-909.0-2075.0-  0.0";
//    QCOMPARE(xx1,app.TEST41(2,false));
//    xx1="unmodified |     0-    0-  0.0-  0.0- 1156-  798-4497.0-11507.0-  0.0";
//    QCOMPARE(xx1,app.TEST41(3,false));


//    xx1="[@K1 11.25] [@B1 0] [@K2 -16] [@B2 109] [@K3 123] [@B3 -586] [@K4 198] [@B4 -1036] [@K5 559] [@B5 -3563] [@K6 1166] [@B6 -8419] [@K7 2422] [@B7 -19723] [@K8 7010] [@B8 -65603] |[0]      0-    0-  0.0-  0.0- 1508- 1148- 45.0- 29.0-  0.0 |[1]      0-    0-  0.0-  0.0- 1150-  789-152.0-350.0-  0.0 |[2]      0-    0-  0.0-  0.0- 1145-  787-909.0-2075.0-  0.0 |[3]      0-    0-  0.0-  0.0- 1156-  798-4497.0-11507.0-  0.0 |";
//    QCOMPARE(xx1,app.TEST61(true,false));



//    xx1="unmodified |[0]      0-    0-  0.0-  0.0- 1508- 1148-  9.4-  9.4-   0.00000 |[1]      0-    0-  0.0-  0.0- 1150-  789-  9.4-  9.4-   0.00000 |[2]      0-    0-  0.0-  0.0- 1145-  787-  9.5-  9.7-   0.00000 |[3]      0-    0-  0.0-  0.0- 1156-  798- 10.0- 11.0-   0.00000 |";
//    QCOMPARE(xx1,app.TEST61(false,false,1));
//    xx1="unmodified |[0]      0-    0-  0.0-  0.0- 1508- 1148-  9.4-  9.4-   7.31702 |[1]      0-    0-  0.0-  0.0- 1150-  789-  9.4-  9.4-   1.06953 |[2]      0-    0-  0.0-  0.0- 1145-  787-  9.5-  9.7-  10.35303 |[3]      0-    0-  0.0-  0.0- 1156-  798- 10.0- 11.0-   0.00000 |";
//    QCOMPARE(xx1,app.TEST61(false,false,2));
//    xx1="unmodified |[0]      0-    0-  0.0-  0.0- 1508- 1148-  9.4-  9.4-   0.00100 |[1]      0-    0-  0.0-  0.0- 1150-  789-  9.4-  9.4-   0.00100 |[2]      0-    0-  0.0-  0.0- 1145-  787-  9.5-  9.7-   0.00100 |[3]      0-    0-  0.0-  0.0- 1156-  798- 10.0- 11.0-   0.00100 |";
//    QCOMPARE(xx1,app.TEST61(false,false,3));

//    xx1="[@K1 11.25] [@B1 0] [@K2 -16] [@B2 109] [@K3 123] [@B3 -586] [@K4 198] [@B4 -1036] [@K5 559] [@B5 -3563] [@K6 1166] [@B6 -8419] [@K7 2422] [@B7 -19723] [@K8 7010] [@B8 -65603] |[0]      0-    0-  0.0-  0.0- 1508- 1148- 45.0- 29.0-   0.00000 |[1]      0-    0-  0.0-  0.0- 1150-  789-152.0-350.0-   6.58417 |[2]      0-    0-  0.0-  0.0- 1145-  787-909.0-2075.0-  47.91656 |[3]      0-    0-  0.0-  0.0- 1156-  798-4497.0-11507.0-20000.00000 |";
//    QCOMPARE(xx1,app.TEST61(true,false,1));
//    xx1="[@K1 11.25] [@B1 0] [@K2 -16] [@B2 109] [@K3 123] [@B3 -586] [@K4 198] [@B4 -1036] [@K5 559] [@B5 -3563] [@K6 1166] [@B6 -8419] [@K7 2422] [@B7 -19723] [@K8 7010] [@B8 -65603] |[0]      0-    0-  0.0-  0.0- 1508- 1148- 45.0- 29.0-  12.03958 |[1]      0-    0-  0.0-  0.0- 1150-  789-152.0-350.0-  23.29991 |[2]      0-    0-  0.0-  0.0- 1145-  787-909.0-2075.0-  42.98836 |[3]      0-    0-  0.0-  0.0- 1156-  798-4497.0-11507.0-20000.00000 |";
//    QCOMPARE(xx1,app.TEST61(true,false,2));
//    xx1="[@K1 11.25] [@B1 0] [@K2 -16] [@B2 109] [@K3 123] [@B3 -586] [@K4 198] [@B4 -1036] [@K5 559] [@B5 -3563] [@K6 1166] [@B6 -8419] [@K7 2422] [@B7 -19723] [@K8 7010] [@B8 -65603] |[0]      0-    0-  0.0-  0.0- 1508- 1148- 45.0- 29.0-   0.00100 |[1]      0-    0-  0.0-  0.0- 1150-  789-152.0-350.0-   0.00100 |[2]      0-    0-  0.0-  0.0- 1145-  787-909.0-2075.0-   0.00100 |[3]      0-    0-  0.0-  0.0- 1156-  798-4497.0-11507.0-   0.00100 |";
//    QCOMPARE(xx1,app.TEST61(true,false,3));


}
void Test1::t2(){
//    PctGuiThread pct;
//    QString xx1;
//    QString xx2;
//    pct.AglDeviceP.set1_QRCode(1,&pct.AnaFound);
//    pct.AglDeviceP.SHOW_twoCodeStr(&pct.AnaFound);
//    pct.AglDeviceP.set2_ChxBuf();
//    pct.AglDeviceP.set3_Map();
//    pct.AglDeviceP.set4_List();
//    pct.AglDeviceP.set5_Other(false,false);
//    pct.AnalyValue();
//    xx1="unmodified |[0]      0-    0-  0.0-  0.0- 1508- 1148-  9.4-  9.4-   1.11000 |[1]      0-    0-  0.0-  0.0- 1150-  789-  9.4-  9.4-   4.44000 |[2]      0-    0-  0.0-  0.0- 1145-  787-  9.5-  9.7-   5.55000 |[3]      0-    0-  0.0-  0.0- 1156-  798- 10.0- 11.0-   9.99000 |";
//    QCOMPARE(xx1,pct.AglDeviceP.AglGET2(false));
////    qDebug()<<pct.CSV_information;
//    xx2="4,190318001,PGI,1.11,ng/ml,<10,9.36262,9.36491,PGII,< 10,ng/ml,<20,9.40842,9.38017,PGI/II,0.25,0-1,G17,Invalid,EIU,<9,11,10,HP,5.55,pmol/L,0-7,9.65449,9.48816,YX-18081003,1949-10-01 14:01:23;";
//    QCOMPARE(xx2,pct.CSV_information);
}
void Test1::t3() {
    PctGuiThread pct;
    pct.AglDeviceP.AglDev.ChxVol = 4;
    pct.AglDeviceP.set3_Map();
    pct.AnaFound.Pihao = "YX-18081003";
    pct.Str_Pre = "WB";
    pct.LoginUserName = "Admin";
    pct.SamIDShow = "T1";


    ////----------------Error-----------------////

    pct.t3_test("Error", 55, 20, 30, 1);

    ////---------------Invalid----------------////
    pct.t3_test("Invalid", 55, 2, 30, 0);

    ////----------------<SHOW-----------------////
    pct.t3_test("< SHOW", 15, 20, 30, 0);

    ////---------------< Print----------------////

    pct.t3_test("< Print", 25, 20, 30, 0);

    ////----------------normal----------------////

    pct.t3_test("normal", 55, 20, 30, 0);

    ////---------------> Print----------------////

    pct.t3_test("> Print", 85, 20, 30, 0);

    ////---------------->SHOW-----------------////

    pct.t3_test("> SHOW", 95, 20, 30, 0);
}

QTEST_APPLESS_MAIN(Test1)

#include "tst_test1.moc"
