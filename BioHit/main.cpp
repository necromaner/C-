#include "commentMove/position.h"
#include "add/add.h"
int main() {
    Position position("    QLabel *Label_U;                      // U盘\n"
                      "    QLabel *Label_Q;                      // 电量\n"
                      "    QLabel *Label_time;                // 实时时间\n"
                      "    QLabel *Label_station;            // 状态显示\n"
                      "    QLabel *Label_Control;           // 告知控制状态\n"
                      "    QLabel *Label_title;                 // 主界面不显示");
    position.mobile(30);
    return 0;
}