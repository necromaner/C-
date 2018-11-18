#include "UdpClient.h"

UdpClient::UdpClient() {
    printf("*------------start------------*\n");
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


    printf("*-----------------------------*\n");
    long long a;
    if(this->fl.size%this->fl.send==0){
        a=this->fl.size/this->fl.send;
    } else{
        a=this->fl.size/this->fl.send+1;
    }
    printf("* Resend rates:%9.3f%%     *\n",(((double)(sendMAX-a))/(double)a)*100);
    close(this->ss);
//    x.clear();
//    vector<int>().swap(x);


//    vector<Contestant> v;
//    string s;
//    vector<Contestant>().swap(v); // 清除v而且最小化它的容量
//    string().swap(s); // 清除s而且最小化它的容量

    delete[] buf;
    delete[] block;




    printf("*-------------end-------------*\n");
}
void UdpClient::setFile(const string &file1,const string &file2) {
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
long long UdpClient::file_size(string filename) {//获取文件大小
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
char *UdpClient::sendFLAG(char* flag){
    char buf[BUFSIZ]={0};
    strcpy(buf, flag);
    buf[strlen(buf)] = '\0';
    sendto(ss, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
}
char *UdpClient::receiveFLAG(){
    char buf[BUFSIZ]={0};
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    printf("接收到：%s\n",buf);
}
map<int,int> UdpClient::initialization(long long num,long long is){
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
        this->fl={"文件不存在",0,0,0};
    } else{
        this->fl={file2,file_size(file()),MAX_BLOCK,MAX_SEND};
    }
    fclose(fp);
    sendto(ss,(char*)&fl,sizeof(fl)+1,0,(struct sockaddr*)&server_addr,len);
    return fl;
}

char * UdpClient::readFile(int num){//读取文件
    bzero(block, MAX_BLOCK);
    FILE *fp;
    fp = fopen(file().c_str(), "rb+");
    fseek(fp, num*fl.block, SEEK_SET);
    fread(block, sizeof(char), (size_t )fl.block, fp);
    fclose(fp);
    return block;
}
Data  UdpClient::sendBuf(int num){//发送数据
    printf("-buf:%3d----*%9lld|\n",num,++this->sendMAX);
    bzero(buf, MAX_SEND);
    Data data;
    memcpy(data.buf,&block[num*MAX_SEND],MAX_SEND);
    data.num=num;
    data.md5="md5";
    sendto(ss,(char*)&data,sizeof(data)+1,0,(struct sockaddr*)&server_addr,len);
    return data;
}
void UdpClient::sendBlock(int num){
    printf("*-----------------------------*\n");
    readFile(num);
    for (int i = 0; i < x.size(); ++i) {
//        if(i==1){
//            continue;
//        }
        printf("*--block:%9d",num);
        sendBuf(x[i]);
    }
    sendFLAG((char*)FINISH_FLAG);
}

void UdpClient::sendFile() {
    long long is;
    if(this->fl.size%this->fl.block==0){
        is=this->fl.size/this->fl.block;
    } else{
        is=this->fl.size/this->fl.block+1;
    }
    for (int i = 0; i < is; ++i) {
        initialization(i,is-1);
        int errorNum=0;
        while (x.size()!=0&&errorNum++<100){
            sendBlock(i);
            //用boost::serialization把容器序列化到一个buf,然后发送出去，在另外一端在boost::serialization来重建容器
            //https://blog.csdn.net/breaksoftware/article/details/80775489
            x.erase(x.begin(), x.end());
        }
    }
}