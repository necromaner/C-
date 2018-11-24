#include "UdpServer.h"
UdpServer::UdpServer() {
    printf("*------------start------------*\n");
    /*1.socket()*/
    this->ss = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    /*2.bind()*/
    if (bind(this->ss, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("*--------创建套接字失败!--------*\n");
        exit(1);
    }
}
UdpServer::~UdpServer() {
    end();
    Clean();
    printf("*-------------end-------------*\n");
}
void UdpServer::end(){
    printf("*-----------------------------*\n");
    long long a;
    if(this->fl.size%this->fl.send==0){
        a=this->fl.size/this->fl.send;
    } else{
        a=this->fl.size/this->fl.send+1;
    }
    printf("* Expect send:%10lld      *\n",a);
    printf("* Actual send:%10lld      *\n",receiveMAX);
    printf("* Resend rates:%9.3f%%     *\n",(((double)(receiveMAX-a))/(double)a)*100);
    tm* t= localtime(&tt);
    printf("* Begin: %d-%02d-%02d %02d:%02d:%02d  *\n",
           t->tm_year + 1900,
           t->tm_mon + 1,
           t->tm_mday,
           t->tm_hour,
           t->tm_min,
           t->tm_sec);
    time_t tt1 = time(nullptr);
    tm* t1= localtime(&tt1);
    printf("* End:   %d-%02d-%02d %02d:%02d:%02d  *\n",
           t1->tm_year + 1900,
           t1->tm_mon + 1,
           t1->tm_mday,
           t1->tm_hour,
           t1->tm_min,
           t1->tm_sec);
    printf("* Time : %-15s      *\n",times((int)tt1-(int)tt).c_str());
    printf("* Speed: %-11s          *\n",speed(fl.size,(int)tt1-(int)tt,0).c_str());
}
std::string UdpServer::times(int s) {
    std::string ss = "";

    if (s >= TIME_D) {
        ss += std::to_string(s / TIME_D);
        s = s % TIME_D;
        ss += "d ";
    }

    if (s >= TIME_H) {
        if (s < TIME_H * TIME_10)
            ss += "0";
        ss += std::to_string(s / TIME_H);
        s = s % TIME_H;
    } else
        ss += "00";
    ss += ":";

    if (s >= TIME_M) {
        if (s < TIME_M * TIME_10)
            ss += "0";
        ss += std::to_string(s / TIME_M);
        s = s % TIME_M;
    } else
        ss += "00";
    ss += ":";

    if (s >= TIME_S) {
        if (s < TIME_S * TIME_10)
            ss += "0";
        ss += std::to_string(s / TIME_S);
        s = s % TIME_S;
    } else
        ss += "00";
    return ss;
}
std::string UdpServer::speed(long long s,int d,int num){
    std::string sl[7]={SPEED_B,SPEED_K,SPEED_M,SPEED_G,SPEED_T,SPEED_P,SPEED_E};
    std::string  speeds;
    speeds = "";
    char ss1[10];
    if(d<1)
        d=1;
    s/=d;
    if(s/(SPEED*SPEED)>=1&&num<5)
        return speed(s/SPEED,d,num+1);
    else if((s*4)/(SPEED*3)>=1){
        sprintf(ss1,"%6.2f",(double)s/SPEED);
        num++;
    } else
        sprintf(ss1,"%6.2f",(double)s);
    speeds+=ss1;
    speeds+=" ";
    speeds+=sl[num];
    return speeds;
}
bool UdpServer::Clean(){
    x.erase(x.begin(), x.end());
    close(this->ss);
    delete[] buf;
    delete[] block;
    return 1;
}

char *UdpServer::getBuf() const {
    return buf;
}
const FileInformation &UdpServer::getFl() const {
    return fl;
}
char *UdpServer::getBlock() const {
    return block;
}
void UdpServer::show() const {
    printf("* Receive information:        *\n");
    printf("* Name: %-22s*\n",this->fl.name.c_str());
    printf("* size: %-22lld*\n",this->fl.size);
    printf("* Block:%-22d*\n",this->fl.block);
    printf("* Send: %-22d*\n",this->fl.send);
    printf("*-----------------------------*\n");
    printf("* Analysis:                   *\n");
    if(this->fl.size%this->fl.send==0){
        printf("* Receive number:%-13lld*\n",this->fl.size/this->fl.send);
    } else{
        printf("* Receive number:%-13lld*\n",this->fl.size/this->fl.send+1);
    }
    if(this->fl.size%this->fl.block==0){
        printf("* Write  number :%-13lld*\n",this->fl.size/this->fl.block);

    } else{
        printf("* Write  number :%-13lld*\n",this->fl.size/this->fl.block+1);
    }
}
void UdpServer::show(Data data){//接收到的数据
    printf(" 接收数据：\n");
    printf(" buf: \n%s\n",data.buf);
    printf(" num: %d\n",data.num);
    printf(" md5:%s\n",data.md5.c_str());
}

int UdpServer::FLAG(char* buf){
    if (strstr(buf, FINISH_FLAG) != NULL) {
        return 1;
    } else if(strstr(buf, CORRECT_FLAG)!= NULL){
        return 2;
    } else if(strstr(buf, AFFIRM_FLAG)!= NULL){
        return 3;
    } else{
        return 0;
    }
}
int UdpServer::sendFLAG(char* flag){
    char buf[MAX_SEND_MAX]={0};
    strcpy(buf, flag);
    buf[strlen(buf)] = '\0';
    Message(buf);
//    sendto(ss, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
    return FLAG(buf);
}
int UdpServer::receiveFLAG(){
    char buf[MAX_SEND_MAX]={0};
    recvfrom(ss, buf, MAX_SEND_MAX, 0, (struct sockaddr *) &server_addr, &len);
    printf("接收到：%s\n",buf);
    return FLAG(buf);
}

std::map<int,int> UdpServer::initialization(long long num,long long is){
    x.erase(x.begin(), x.end());
    int length;
    if(num==is){//最后一个块
        int iss=(int)(this->fl.size%this->fl.block);
        if(iss%this->fl.send==0){
            length=iss/this->fl.send;
        } else{
            length=iss/this->fl.send+1;
        }
    } else{
        length=this->fl.block/this->fl.send;
    }
    for (int i = 0; i < length; ++i) {
        x[i]=i;
    }
    return x;
}
//--------------------------------------------------------------------------
char * UdpServer::Message(){//接收消息
    bzero(buf, MAX_SEND_MAX);
    recvfrom(ss, buf, MAX_SEND_MAX, 0, (struct sockaddr *) &server_addr, &len);
    return buf;
}
char * UdpServer::Message(char *message){//发送消息
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
    return message;
}

FileInformation UdpServer::Information(){

    Message();
    memcpy(&this->fl,buf,sizeof(fl)+1);
//    FILE *fp;
    fp=fopen(file().c_str(),"w+");
    fclose(fp);
    tt=time(nullptr);
    return fl;
}

void UdpServer::writeBuf(int num,Data data) {
    int n = (int) x.erase(data.num);//如果刪除了會返回1，否則返回0
    fseek(fp, num * fl.block + data.num * fl.send, SEEK_SET);//写入坐标
    if (num + 1 == MAX_Block_Num() && data.num + 1 == MIN_Buf_Num())
        fwrite(data.buf, sizeof(char), (size_t) END_Buf_Size(), fp);
    else
        fwrite(data.buf, sizeof(char), (size_t) fl.send, fp);
}
void UdpServer::receiveFile(){

    long long is;
    is=MAX_Block_Num();
    fp=fopen(file().c_str(),"rb+");
    for (int i = 0; i < is; ++i) {
        initialization(i,is-1);
        int errorNum=BEGIN;
        while (x.size()!=BEGIN&&errorNum++<MAX_RESEND){
            receiveBlock(i);
            sendX();
        }
    }
    fclose(fp);
}
void UdpServer::receiveBlock(int num){
//    printf("*-----------------------------*\n");
    while (1){
        recvfrom(ss, buf, MAX_SEND_MAX, 0, (struct sockaddr *) &server_addr, &len);
        if (strstr(buf, FINISH_FLAG) != NULL) {
            break;
        }
//        printf("*--block:%9d",num);
        Data data;
        data=receiveBuf();
        writeBuf(num,data);
    }
}
Data UdpServer::receiveBuf(){
    Data data;
    memcpy(&data, buf, sizeof(data) + 1);
//    printf("-buf:%3d----*%9lld|\n",data.num,this->receiveMAX);

    ++this->receiveMAX;
//    show(data);
    return data;
}

bool UdpServer::sendX(){
//    printf("x.size=%d\n",(int)x.size());
    int xs=x.size();
    if(xs>0){
        printf("* Loss: %-10d            *\n",(int)x.size());
        std::map<int,int>::iterator i;
        int yy1=10;
        int yy2=20;
        int array1[3][2]={6};
        int yy[yy1][yy2]={1,2,3,4,5};
        int n1=0;
        int n2=0;
//        for (i = x.begin(); i != x.end(); ++i) {
//            printf("* %d - %d*\n",i->first,i->second);
//            yy[n1][n2]=i->first;
//            if(n2++>99){
//                n2=0;
//                n1++;
//            }
//        }
//        for (int j = 0; j < yy1; ++j) {
//            for (int k = 0; k < yy2; ++k) {
//                if(yy[j][k]!=0){
//                    printf("%3d   ",yy[j][k]);
//                } else
//                    break;
//            }
//        }
//        sendto(ss,(char*)&x,sizeof(x)+1,0,(struct sockaddr*)&server_addr,len);
    }
    sendFLAG((char*)FINISH_FLAG);
    x.erase(x.begin(), x.end());
    return true;
}
void UdpServer::TEXT_Receive(int min,int max) {
    char *buf=new char[10000];
    while (true){
        recvfrom(ss, buf, 10000, 0, (struct sockaddr *) &server_addr, &len);
        printf("接收到:\n%s\n",buf);
        bzero(buf, strlen(buf));
    }
    delete[] buf;
}