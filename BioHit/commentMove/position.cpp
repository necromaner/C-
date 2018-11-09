//
// Created by 温亚奇 on 2018/11/7.
//

#include "position.h"


Position::Position(){
    this->s="";
}
Position::~Position(){

}
Position::Position(string s2){
    this->s=s2+"\n";
}
const string &Position::getS() const {
    return s;
}
void Position::setS(const string &s) {
    Position::s = s+"\n";
}

string Position::mobile(int x){
    string s1="";
    int y=0;
    int num=0;

    int begin=0;
    bool cc= false;
    int cx=0;
    while (s[num]){
        if(s[num]=='\n'){

            if(!cc){
                s1=s1+this->s.substr(num-y,y);
            }
            begin=num;
            s1=s1+this->s.substr(num-cx,cx);
            cx=0;
            y=0;
            cc=false;
        }
        if(s[num]=='/'&&s[num+1]=='/'){
            s1=s1+this->s.substr(begin,y);
            for (int i = 0; i < x-y; ++i) {
                s1=s1+" ";
            }
            cc=true;
        }
        if(cc){
            cx++;
        }
        y++;
        num++;
    }


    printf("%s\n",s1.c_str());
    return s;
}