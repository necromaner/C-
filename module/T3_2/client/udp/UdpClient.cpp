#include "UdpClient.h"
////------------------内联函数--------------------////
inline std::string UdpClient::file() {
    return file1 + file2;
}
inline long long UdpClient::MAX_Block_Num() {
    if (this->fl.size % this->fl.block == 0)
        return this->fl.size / this->fl.block;
    else
        return this->fl.size / this->fl.block + 1;
}
inline int UdpClient::MAX_endbuf() {
    return (int) ((this->fl.size % this->fl.block) % this->fl.send);
}
inline int UdpClient::MIN_Buf_Num() {
    if (((this->fl.size % this->fl.block) % this->fl.send) == 0)
        return (int) ((this->fl.size % this->fl.block) / this->fl.send);
    else
        return (int) ((this->fl.size % this->fl.block) / this->fl.send) + 1;
}
inline long long UdpClient::serial() {
    if (this->fl.size % this->fl.block == 0) {
        return this->fl.size / this->fl.block;
    } else {
        return this->fl.size / this->fl.block + 1;
    }
}
////------------------清空数据--------------------////
void UdpClient::Clean_Set_Y(){
    UdpClient::y.erase(UdpClient::y.begin(), UdpClient::y.end());
}
void UdpClient::Clean_buf(){
    bzero(buf, MAX_SEND);
}
void UdpClient::Clean_block(){
    bzero(block, MAX_BLOCK);
}
////-----------------构造--析构-------------------////
UdpClient::UdpClient() {
    test=false;
}
UdpClient::~UdpClient() {
    if(test){
        end();
        Clean();
        printf("*-------------end-------------*\n");
    }
}
void UdpClient::udpStart(){
    printf("*------------start------------*\n");
    test=true;
    tt=getCurrentTime();
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
void UdpClient::end(){
    printf("*-----------------------------*\n");
    long long a;
    if(this->fl.size%this->fl.send==0){
        a=this->fl.size/this->fl.send;
    } else{
        a=this->fl.size/this->fl.send+1;
    }
    printf("* Expect send:%10lld      *\n",a);
    printf("* Actual send:%10lld      *\n",SR_NUM);
    printf("* Resend rates:%9.3f%%     *\n",(((double)(SR_NUM-a))/(double)a)*100);
    tm* t= localtime(&tt);
    printf("* Begin: %d-%02d-%02d %02d:%02d:%02d  *\n",
           t->tm_year + 1900,
           t->tm_mon + 1,
           t->tm_mday,
           t->tm_hour,
           t->tm_min,
           t->tm_sec);
    time_t tt1 = getCurrentTime();
    tm* t1= localtime(&tt1);
    printf("* End:   %d-%02d-%02d %02d:%02d:%02d  *\n",
           t1->tm_year + 1900,
           t1->tm_mon + 1,
           t1->tm_mday,
           t1->tm_hour,
           t1->tm_min,
           t1->tm_sec);
    printf("* Time : %-15s      *\n",times((long long)tt1-(long long)tt).c_str());
    printf("* Speed: %-11s          *\n",speed(fl.size,(int)tt1-(int)tt).c_str());
}
int64_t UdpClient::getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
std::string UdpClient::times(long long s) {
    std::string ss = "";
    int s1=s;
    ////-----------days
    int days=s1 / TIME_D;
    if (s1 >= TIME_D) {
        ss += std::to_string(days);
        ss += "d ";
    }
    s1 = s1 % TIME_D;

    ////-----------hours
    int hours=s1 / TIME_H;
    if (s1 >= TIME_H) {
        if (s1 < TIME_H * TIME_10)
            ss += "0";
        ss += std::to_string(hours);
    } else
        ss += "00";
    ss += ":";
    s1 = s1 % TIME_H;

    ////-----------minutes
    int minutes=s1 / TIME_M;
    if (s1 >= TIME_M) {
        if (s1 < TIME_M * TIME_10)
            ss += "0";
        ss += std::to_string(s1 / TIME_M);
    } else
        ss += "00";
    ss += ":";
    s1 = s1 % TIME_M;

    ////-----------seconds
    int seconds=s1 / TIME_S;
    if(s1 % TIME_S>500&&s>TIME_M)
        s1++;
    if (s1 >= TIME_S) {
        if (s1 < TIME_S * TIME_10)
            ss += "0";
        ss += std::to_string(s1 / TIME_S);
    } else
        ss += "00";
    s1 = s1 % TIME_S;

    ////-----------milliseconds
    int milliseconds=s1 / TIME_MS;
    if(s<TIME_M){
        ss+=".";
        if(s1<TIME_MS*TIME_10)
            ss+="00";
        else if(s1<TIME_MS*TIME_10*TIME_10)
            ss+="0";
        ss+=std::to_string(s1 / TIME_MS);
    }
    return ss;
}
std::string UdpClient::speed(long long s,long long d){

    if(s>=0&&d>=0)
        return speed(s,d,0);
    else
        return "  ERROR   ";
}
std::string UdpClient::speed(long long s,long long d,int num){
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
    y.erase(y.begin(), y.end());
    close(this->ss);
    delete[] buf;
    delete[] block;
    return 1;
}
////-------------------test---------------------////
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
void UdpClient::TEXT_Send(int min,int max) {
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
char *UdpClient::getBuf() const {
    return buf;
}
const FileInformation &UdpClient::getFl() const {
    return fl;
}
char *UdpClient::getBlock() const {
    return block;
}
void UdpClient::Clean_test(){
    bzero(buf, MAX_SEND);
    bzero(block, MAX_BLOCK);
    y.erase(y.begin(), y.end());
    file1="";
    file2="";
    fl.name= "";
    fl.block=0;
    fl.size=0;
    fl.send=0;
}
////-------------------收  发---------------------////
char * UdpClient::Message(){//接收消息
    bzero(buf, MAX_SEND);
    recvfrom(ss, buf, MAX_SEND, 0, (struct sockaddr *) &server_addr, &len);
    return buf;
}
char * UdpClient::Message(char *message){//发送消息
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
    return message;
}
////-------------------命  令---------------------////
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
////------------------文件信息--------------------////
void UdpClient::setFile(const std::string &file1,const std::string &file2) {
    UdpClient::file1 = file1;
    UdpClient::file2 = file2;
}
long long UdpClient::file_size(std::string filename) {//获取文件大小
    FILE *fp=fopen(filename.c_str(),"r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    long size=ftell(fp);
    fclose(fp);
    return size;
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
////------------------发送文件--------------------////
std::set<int> UdpClient::initialization_set(long long num,long long is){
    y.erase(y.begin(),y.end());
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
        y.insert(i);
    }
    return y;
}
void UdpClient::sendFile() {
    long long is;
    is=serial();
    for (int i = 0; i < is; ++i) {
        initialization_set(i,is-1);
        int errorNum=BEGIN;
//        std::set<int>::iterator it;
//        for(it=y.begin ();it!=y.end ();it++)
//        {
//            printf("%d--",*it);
//        }
//        printf("\n");
        while (y.size()!=BEGIN&&errorNum++<MAX_RESEND){
//            sendBlock(i);
//            receiveY();
            Clean_Set_Y();
        }
    }
}
void UdpClient::sendBlock(int num){
//    printf("*-----------------------------*\n");
    readFile(num);
    std::set<int>::iterator i;
    for (i = y.begin(); i != y.end(); ++i) {
//        if(i->first==40){
//            continue;
//        }
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
//        sendBuf(*i);
    }
    sendFLAG((char*)FINISH_FLAG);
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
Data UdpClient::sendBuf(int num) {//发送数据
//    printf("-buf:%3d----*%9lld|\n",num,this->sendMAX);
    ++this->SR_NUM;
    bzero(buf, MAX_SEND);
    Data data;
    memcpy(data.buf, &block[num * MAX_SEND], MAX_SEND);
    bzero(data.buf, MAX_SEND);
    memcpy(data.buf, "1234567890", MAX_SEND);
    data.num = num;
    data.md5 = "md5";
    sendto(ss, (char *) &data, sizeof(data) + 1, 0, (struct sockaddr *) &server_addr, len);
    return data;
}
////------------------消息回传--------------------////
bool UdpClient::receiveY() {
    y.erase(y.begin(), y.end());
    while (true) {
        bzero(buf, MAX_SEND);
        recvfrom(ss, buf, MAX_SEND_MAX, 0, (struct sockaddr *) &server_addr, &len);
        if (strstr(buf, FINISH_FLAG) != NULL) {
            break;
        }

        Data data;
        data=receiveBuf();
//        memcpy(&data, buf, sizeof(data) + 1);
        printf("--%s--\n", buf);

//        buf[0] = ' ';
//        string_To_Set(buf,CUT);
//        std::set<int>::iterator it;
//        printf("*-%-27s-*", buf);
//        for (it = y.begin(); it != y.end(); it++) {
//            printf("-%d--", *it);
//        }
        printf("\n");
    }
//    x.erase(x.begin(), x.end());
    return true;
}
Data UdpClient::receiveBuf(){
    Data data;
    memcpy(&data, buf, sizeof(data) + 1);
    printf("--%d--\n", data.num);

//    show(data);
    return data;
}
std::set<int> UdpClient::string_To_Set(const std::string& str, const std::string& delim) {
    if ("" == str) return y;
    char *strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());
    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());
    char *p = strtok(strs, d);
    while (p) {
        int s = atoi(p);
        y.insert(s);
        p = strtok(NULL, d);
    }
    return y;
}

