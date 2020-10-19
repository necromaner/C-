#include "UdpServer.h"
////------------------内联函数--------------------////
inline std::string UdpServer::file() {
    return file1 + fl.name;
}
inline long long UdpServer::MAX_Block_Num() {
    if (this->fl.size % this->fl.block == 0)
        return this->fl.size / this->fl.block;
    else
        return this->fl.size / this->fl.block + 1;
}
inline int UdpServer::MAX_endbuf() {
    return (int) ((this->fl.size % this->fl.block) % this->fl.send);
}
inline int UdpServer::MIN_Buf_Num() {
    if (((this->fl.size % this->fl.block) % this->fl.send) == 0)
        return (int) ((this->fl.size % this->fl.block) / this->fl.send);
    else
        return (int) ((this->fl.size % this->fl.block) / this->fl.send) + 1;
}
////------------------清空数据--------------------////
void UdpServer::Clean_Set_Y(){
    UdpServer::y.erase(UdpServer::y.begin(), UdpServer::y.end());
}
void UdpServer::Clean_buf(){
    bzero(buf, MAX_SEND);
}
void UdpServer::Clean_block(){
    bzero(block, MAX_BLOCK);
}
////-----------------构造--析构-------------------////
UdpServer::UdpServer() {
    test=false;
    fl.send=0;
    fl.size=0;
    fl.block=0;
    fl.name="";
}
UdpServer::~UdpServer() {
    if(test){
//        end();
//        Clean();
        printf("*-------------end-------------*\n");
    }
}
void UdpServer::udpStart(){
    printf("*------------start------------*\n");
    test=true;
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
void UdpServer::end(){
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
    printf("* Speed: %-11s          *\n",speed(fl.size,(int)tt1-(int)tt).c_str());
}
int64_t UdpServer::getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
std::string UdpServer::times(long long s) {
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
std::string UdpServer::speed(long long s,long long d){

    if(s>=0&&d>=0)
        return speed(s,d,0);
    else
        return "  ERROR   ";
}
std::string UdpServer::speed(long long s,long long d,int num){
    std::string sl[7]={SPEED_B,SPEED_K,SPEED_M,SPEED_G,SPEED_T,SPEED_P,SPEED_E};
    std::string  speeds;
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
    y.erase(y.begin(), y.end());
    close(this->ss);
    delete[] buf;
    delete[] block;
    return 1;
}
////-------------------test---------------------////
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
void UdpServer::show(Data data){//数据信息
    printf("--------show(Data)---------\n");
    printf(" 接收数据：\n");
    printf(" buf: \n%s\n",data.buf);
    printf(" num: %d\n",data.num);
    printf(" md5:%s\n",data.md5.c_str());
    printf("---------------------------\n");
}
void UdpServer::setFile1(const std::string &file1) {
    UdpServer::file1 = file1;
}
void UdpServer::setFile2(const std::string &file2) {
    UdpServer::file2 = file2;
}
void UdpServer::setFl(const std::string &name,long long size,int block,int send) {
    UdpServer::fl.name = name;
    UdpServer::fl.size = size;
    UdpServer::fl.block = block;
    UdpServer::fl.send = send;
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
char *UdpServer::getBuf() const {
    return buf;
}
const FileInformation &UdpServer::getFl() const {
    return fl;
}
char *UdpServer::getBlock() const {
    return block;
}
////-------------------收  发---------------------////
char * UdpServer::Message(){//接收消息
    bzero(buf, MAX_SEND_MAX);
    recvfrom(ss, buf, MAX_SEND_MAX, 0, (struct sockaddr *) &server_addr, &len);
    return buf;
}
char * UdpServer::Message(char *message){//发送消息
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
    return message;
}
////-------------------命  令---------------------////
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
////------------------文件信息--------------------////
void UdpServer::setFile(const std::string &file1){
    UdpServer::file1=file1;
}
FileInformation UdpServer::Information(){

    Message();
    memcpy(&this->fl,buf,sizeof(fl)+1);
//    FILE *fp;
//    fp=fopen(file().c_str(),"w+");
//    fclose(fp);
    tt=getCurrentTime();
    return fl;
}
////------------------发送文件--------------------////
std::set<int> UdpServer::initialization_set(long long num,long long is){
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
void UdpServer::receiveFile() {
    long long is;
    is = MAX_Block_Num();
    fp = fopen(file().c_str(), "rb+");
    for (int i = 0; i < is; ++i) {
        initialization_set(i, is - 1);
        int errorNum = BEGIN;//BEGIN=0;
        while (y.size() != BEGIN && errorNum++ < MAX_RESEND) {
            printf("----------------%d-%ld\n", errorNum, y.size());
//            receiveBlock(i);
//            sendY();
            Clean_Set_Y();
        }
        block_num++;
    }
    fclose(fp);
}
void UdpServer::receiveBlock(int num){
    int x=0;
//    printf("*-----------------------------*\n");
    while (1){
        recvfrom(ss, buf, MAX_SEND_MAX, 0, (struct sockaddr *) &server_addr, &len);
        if (strstr(buf, FINISH_FLAG) != NULL) {
            break;
        }
//        printf("*--block:%9d",num);
        Data data;
        x++;
        data=receiveBuf();
        printf("x=%d\n",x);
//        writeBuf(num,data);
    }
}
Data UdpServer::receiveBuf(){
    Data data;
    memcpy(&data, buf, sizeof(data) + 1);
//    printf("-buf:%3d----*%9lld|\n",data.num,this->receiveMAX);
    ++this->SR_NUM;
//    show(data);
    return data;
}
void UdpServer::writeBuf(int num,Data data) {
    int n = (int) y.erase(data.num);//如果刪除了會返回1，否則返回0
//    printf("---%s--%d\n",data.buf,data.num);
    fseek(fp, num * fl.block + data.num * fl.send, SEEK_SET);//写入坐标
    if (num + 1 == MAX_Block_Num() && data.num + 1 == MIN_Buf_Num())
        fwrite(data.buf, sizeof(char), (size_t) MAX_endbuf(), fp);
    else
        fwrite(data.buf, sizeof(char), (size_t) fl.send, fp);
}
////------------------消息回传--------------------////
bool UdpServer::sendY() {
//    printf("x.size=%d\n",(int)x.size());
    int xs = y.size();
    if (xs > 0) {
        bzero(buf, MAX_SEND);
        std::string s = set_To_String(y,CUT);
        printf("* Loss: %-10d            *%5d-%ld\n", (int) y.size(), block_num, s.length());
        printf("*-%-27s-*\n", s.c_str());
        Data data;
        memcpy(data.buf, s.c_str(), MAX_SEND);
        data.num = block_num;
        data.md5 = "md5";
        show(data);
        printf("*-%-27s-*\n", data.buf);
        sendto(ss, (char *) &data, sizeof(data) + 1, 0, (struct sockaddr *) &server_addr, len);
//        sendto(ss, s.c_str(), s.length() + 1, 0, (struct sockaddr *) &server_addr, len);
    }
    sendFLAG((char *) FINISH_FLAG);
//    x.erase(x.begin(), x.end());
    return true;
}
std::string UdpServer::set_To_String(std::set<int> y,const std::string& delim) {

    std::string s = "";
    std::set<int>::iterator it;
    for (it = y.begin(); it != y.end(); it++) {
        char s1[40] = "";
        sprintf(s1, "%d%s", *it,delim.c_str());
        s += s1;
    }
    return s;
}




