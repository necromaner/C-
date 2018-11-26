#include "UdpClient.h"
#include <time.h>
UdpClient::UdpClient() {
    test=false;
}
void UdpClient::udpStart(){
    printf("*------------start------------*\n");
    test=true;
    tt=time(nullptr);
/*1.socket()*/
    this->ss = socket(AF_INET, SOCK_DGRAM, 0);//tcp
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(ADDRESS);

//    /*2.connect()*/
//    if (connect(this->ss, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) < 0) {
//        printf("*            -UDP-            *\n");
//        this->ss = socket(AF_INET, SOCK_DGRAM, 0);
//    } else {
//        printf("*            -TCP-            *\n");
//    }
}
UdpClient::~UdpClient() {
    if(test){
        end();
        Clean();
        printf("*-------------end-------------*\n");
    }
}
void UdpClient::end(){
    printf("*-----------------------------*\n");
    long long a;
    if(this->fl.size%this->fl.send==0){
        a=this->fl.size/this->fl.send;
    } else{
        a=this->fl.size/this->fl.send+1;
    }
    printf("* Expect send:%10lld      *\n",a);
    printf("* Actual send:%10lld      *\n",sendMAX);
    printf("* Resend rates:%9.3f%%     *\n",(((double)(sendMAX-a))/(double)a)*100);
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
std::string UdpClient::times(int s) {
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
std::string UdpClient::speed(long long s,int d,int num){
    std::string sl[7]={SPEED_B,SPEED_K,SPEED_M,SPEED_G,SPEED_T,SPEED_P,SPEED_E};
    std::string  speeds="";
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
bool UdpClient::Clean(){
    x.erase(x.begin(), x.end());
    close(this->ss);
    delete[] buf;
    delete[] block;
    return 1;
}
void UdpClient::setFile(const std::string &file1,const std::string &file2) {
    UdpClient::file1 = file1;
    UdpClient::file2 = file2;
}
const FileInformation &UdpClient::getFl() const {
    return fl;
}
char *UdpClient::getBlock() const {
    return block;
}
char *UdpClient::getBuf() const {
    return buf;
}
long long UdpClient::file_size(std::string filename) {//获取文件大小
    FILE *fp=fopen(filename.c_str(),"r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    long size=ftell(fp);
    fclose(fp);
    return size;
}
void UdpClient::show() const {
    printf("* Send information:           *\n");
    printf("* Name: %-22s*\n",this->fl.name.c_str());
    printf("* size: %-22lld*\n",this->fl.size);
    printf("* Block:%-22d*\n",this->fl.block);
    printf("* Send: %-22d*\n",this->fl.send);
    printf("*-----------------------------*\n");
    printf("* Analysis:                   *\n");
    if(this->fl.size%this->fl.send==0){
        printf("* Send number:%-16lld*\n",this->fl.size/this->fl.send);
    } else{
        printf("* Send number:%-16lld*\n",this->fl.size/this->fl.send+1);
    }
    if(this->fl.size%this->fl.block==0){
        printf("* Read number:%-16lld*\n",this->fl.size/this->fl.block);

    } else{
        printf("* Read number:%-16lld*\n",this->fl.size/this->fl.block+1);
    }
}
void UdpClient::show(Data data){
    printf(" 发送数据：\n");
    printf(" buf: \n%s\n",data.buf);
    printf(" num: %d\n",data.num);
    printf(" md5:%s\n",data.md5.c_str());
}
int UdpClient::FLAG(char* buf){
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
int UdpClient::sendFLAG(char* flag){
    char buf[BUFSIZ]={0};
    strcpy(buf, flag);
    buf[strlen(buf)] = '\0';
    sendto(ss, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
    return FLAG(buf);
}
int UdpClient::receiveFLAG(){
    char buf[BUFSIZ]={0};
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    printf("接收到：%s\n",buf);
    return FLAG(buf);
}

void UdpClient::setFile1(const std::string &file1) {
    UdpClient::file1 = file1;
}
void UdpClient::setFile2(const std::string &file2) {
    UdpClient::file2 = file2;
}
void UdpClient::setFl(const std::string &name,long long size,int block,int send) {
    UdpClient::fl.name = name;
    UdpClient::fl.size = size;
    UdpClient::fl.block = block;
    UdpClient::fl.send = send;
}

inline long long UdpClient::serial() {
    if (this->fl.size % this->fl.block == 0) {
        return this->fl.size / this->fl.block;
    } else {
        return this->fl.size / this->fl.block + 1;
    }
}
std::map<int,int> UdpClient::initialization(long long num,long long is){
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
char * UdpClient::Message(){//接收消息
    bzero(buf, MAX_SEND);
    recvfrom(ss, buf, MAX_SEND, 0, (struct sockaddr *) &server_addr, &len);
    return buf;
}
char * UdpClient::Message(char *message){//发送消息
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
    return message;
}


FileInformation UdpClient::Information(){//发送文件信息
    FILE *fp;
    if ((fp = fopen(file().c_str(), "r")) == NULL) {
        this->fl={"文件不存在",BEGIN,BEGIN,BEGIN};
    } else{
        this->fl={file2,file_size(file()),MAX_BLOCK,MAX_SEND};
    }
    fclose(fp);
    sendto(ss,(char*)&fl,sizeof(fl)+1,0,(struct sockaddr*)&server_addr,len);
    return fl;
}

char *UdpClient::readFile(int num){//读取文件
    bzero(block, MAX_BLOCK);
    FILE *fp;
    fp = fopen(file().c_str(), "rb+");
    fseek(fp, num*fl.block, SEEK_SET);
    fread(block, sizeof(char), (size_t )fl.block, fp);
    fclose(fp);
    return block;
}
void UdpClient::sendFile() {
    long long is;
    is=serial();
    for (int i = 0; i < is; ++i) {
        initialization(i,is-1);
        int errorNum=BEGIN;
        while (x.size()!=BEGIN&&errorNum++<MAX_RESEND){
            sendBlock(i);
            receiveX();
            //用boost::serialization把容器序列化到一个buf,然后发送出去，在另外一端在boost::serialization来重建容器
            //https://blog.csdn.net/breaksoftware/article/details/80775489

        }
    }
}
void UdpClient::sendBlock(int num){
//    printf("*-----------------------------*\n");
    readFile(num);
    std::map<int,int>::iterator i;
    for (i = x.begin(); i != x.end(); ++i) {
        if(i->first==40){
            continue;
        }
//        if(i->first==41){
//            continue;
//        }
//        if(i->first==42){
//            continue;
//        }
//        if(i->first>2&&i->first<95){
//            continue;
//        }
//        printf("*--block:%9d",num);
        sendBuf(i->first);
    }
    sendFLAG((char*)FINISH_FLAG);
}
Data UdpClient::sendBuf(int num){//发送数据
//    printf("-buf:%3d----*%9lld|\n",num,this->sendMAX);
    ++this->sendMAX;
    bzero(buf, MAX_SEND);
    Data data;
    memcpy(data.buf,&block[num*MAX_SEND],MAX_SEND);
    data.num=num;
    data.md5="md5";
    sendto(ss,(char*)&data,sizeof(data)+1,0,(struct sockaddr*)&server_addr,len);
    return data;
}

bool UdpClient::receiveX(){
    while (true){
        recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
        if (strstr(buf, FINISH_FLAG) != NULL) {
            break;
        }

        printf("-----%s------\n",buf);

    }
    x.erase(x.begin(), x.end());
//    printf("x.size=%d\n",(int)x.size());
    return true;
}
std::map<int,int> UdpClient::char_To_Map(char* buf){
    std::map<int,int> x;

}
std::vector<std::string> UdpClient::split(const std::string& str, const std::string& delim) {
    std::vector<std::string> res;
    if("" == str) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char * strs = new char[str.length() + 1] ; //不要忘了
    strcpy(strs, str.c_str());

    char * d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while(p) {
        std::string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }

    return res;
}
void UdpClient::test1() { //空字符串
    printf("******test1****** \n");
    std::string s = "1:2";

    std::vector<std::string> res = split(s, ":");
    for (int i = 0; i < res.size(); ++i)
    {
        printf("---%s---\n",res[i].c_str());
    }
}
void UdpClient::TEXT_Send(int min,int max) {

    FILE *fp;
    fp = fopen(file().c_str(), "rb+");
    fseek(fp, 0, SEEK_SET);

    int x=199;
    char* buf = new char[x];
    fseek(fp, 0, SEEK_SET);
    fread(buf, sizeof(char), 9200, fp);
    printf("接收到:\n%s\n",buf);
    sendto(ss, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
    bzero(buf, strlen(buf));
    delete[] buf;
    fclose(fp);
}
