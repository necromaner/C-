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
    close(this->ss);
    delete[] buf;
    delete[] block;



    printf("*-----------------------------*\n");


    printf("*-------------end-------------*\n");
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
void UdpServer::show(Data data){//接收到的数据
    printf(" 接收数据：\n");
    printf(" buf: \n%s\n",data.buf);
    printf(" num: %d\n",data.num);
    printf(" md5:%s\n",data.md5.c_str());
}
char *UdpServer::sendFLAG(char* flag){
    char buf[BUFSIZ]={0};
    strcpy(buf, flag);
    buf[strlen(buf)] = '\0';
    sendto(ss, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
}
char *UdpServer::receiveFLAG(){
    char buf[BUFSIZ]={0};
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    printf("接收到：%s\n",buf);
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
    bzero(buf, MAX_SEND);
    recvfrom(ss, buf, MAX_SEND, 0, (struct sockaddr *) &server_addr, &len);
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
    return fl;
}



Data UdpServer::receiveBuf(){
    Data data;
    memcpy(&data, buf, sizeof(data) + 1);
    printf("-buf:%3d----*%9lld|\n",data.num,++this->receiveMAX);
//    show(data);
    return data;
}

char *UdpServer::manage(int num){
    char ss[6][MAX_SEND];
    
    memcpy(ss[0], receiveBuf().buf, MAX_SEND);
    for (int i = 1; i < 6; ++i) {
        bzero(ss[i], MAX_SEND);
        memcpy(ss[i], receiveBuf().buf, MAX_SEND);
    }
    for (int j = 0; j < 6; ++j) {
        memcpy(&block[j*MAX_SEND], ss[j], MAX_SEND);
    }
    return block;
}
char *UdpServer::writeFile(int num){
    FILE *fp;
//    fp=fopen(file().c_str(),"rb+");//可以在中间进行插入
//    fseek(fp, num*fl.block, SEEK_SET);
    
    fp=fopen(file().c_str(),"rb+");
//    if (num == serial()) {
//        fwrite(block, sizeof(char), (size_t) fl.size % fl.block, fp);
//    } else {
//        fwrite(block, sizeof(char), (size_t) fl.block, fp);
//    }
    
    printf("位置%d写入：\n%s\n",num*fl.block,block);
    if (fwrite("hello", sizeof(char), 2, fp) != 1) {
        printf("写入失败");
        
    }
    fclose(fp);
    return block;
}


void UdpServer::receiveBlock(int num){
    printf("*-----------------------------*\n");
    while (1){
        recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
        if (strstr(buf, FINISH_FLAG) != NULL) {
            break;
        }
        printf("*--block:%9d",num);
        Data data;
        data=receiveBuf();
        writeBuf(num,data);
    }
}
void UdpServer::writeBuf(int num,Data data) {
    int n = (int)x.erase(data.num);//如果刪除了會返回1，否則返回0
    fseek(fp, num * fl.block + data.num * fl.send, SEEK_SET);
    fwrite(data.buf, sizeof(char), (size_t) fl.send, fp);
}
void UdpServer::receiveFile(){
    long long is;
    if(this->fl.size%this->fl.block==0){
        is=this->fl.size/this->fl.block;
    } else{
        is=this->fl.size/this->fl.block+1;
    }
    fp=fopen(file().c_str(),"rb+");
    for (int i = 0; i < is; ++i) {
        initialization(i,is-1);
        int errorNum=0;
        while (x.size()!=0&&errorNum++<100){
            receiveBlock(i);
            x.erase(x.begin(), x.end());
        }
    }
    fclose(fp);
}