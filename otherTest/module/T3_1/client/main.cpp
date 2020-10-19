#include <gtest/gtest.h>
#include "UdpClient.h"
long long file_size(string filename) {
    FILE *fp=fopen(filename.c_str(),"r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    long long size=ftell(fp);
    fclose(fp);
    return size;
}
string name(string filename) {
    int pos=filename.find_last_of('/');
    return filename.substr(pos+1);
}
void sendFlag(char* flag) {
    char buf[BUFSIZ]={0};
    socklen_t len = sizeof(server_addr);
    strcpy(buf, flag);
    buf[strlen(buf)] = '\0';//strlen()用来计算字符串的长度
    sendto(sc, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
}
void receiveFlag(){
    char buf[BUFSIZ]={0};
    socklen_t len1 = sizeof(server_addr);
    recvfrom(sc, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len1);
    printf("接收到：%s\n",buf);
}
void sendData(int j,char *block,FileInformation fl) {
    int xs;
    if (j == fl.size / fl.block)
        xs = (int) (fl.size % fl.block) / fl.max + 1;
    else
        xs = fl.block / fl.max;
    for (int i = 0; i < xs; ++i) {
        Data data;
        strncpy(data.buf, block + i * fl.max, fl.max);
        data.num1 = j;
        data.num2 = i;
        data.md5 = "md5";
        socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
        sendto(sc, (char *) &data, sizeof(data) + 1, 0, (struct sockaddr *) &server_addr, len);
        printf("发送序号：%d---%s\n", data.num2, data.buf);
    }
    sendFlag((char *) FINISH_FLAG);
}
void open(int i,string file,FileInformation fl){
    char block[fl.block];
    FILE *fp;
    fp = fopen(file.c_str(), "r");
    fseek(fp, i*fl.block, SEEK_SET);
    fread(block, sizeof(char), (size_t) fl.block, fp);
    fclose(fp);
    printf("%s\n",block);
    sendData(i,block,fl);
}
FileInformation sendInformation(string file){
    long long x=file_size(file);
    string file2=name(file);
    FileInformation fl={file2,x,1000,100};
    socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
    sendto(sc,(char*)&fl,sizeof(fl)+1,0,(struct sockaddr*)&server_addr,len);
    printf("发送：文件名：%s;大小：%lld字节,块大小%d,每次发送大小：%d字节\n",fl.name.c_str(),fl.size,fl.block,fl.max);
    receiveFlag();
    return fl;
}
void udp(){
    FILE *fp;
    string file1="/Users/necromaner/test/send/";
    string file2="1.zip";
    string file=file1+file2;
    if ((fp = fopen(file.c_str(), "r")) == NULL) {
        perror("打不开文件\n");
        exit(0);
    }
    fclose(fp);
    FileInformation fl=sendInformation(file);
    for (int i = 0; i < fl.size/fl.block+1; ++i) {
        open(i,file,fl);
    }
}



void udpClient(){
    sc = socket(AF_INET, SOCK_STREAM, 0);//tcp
    printf("1.socket()\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sc, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) < 0) {
        printf("2.connect()-UDP连接\n");
        sc = socket(AF_INET, SOCK_DGRAM, 0);
    } else {
        printf("2.connect()-TCP连接\n");
    }
    string file1="/Users/necromaner/test/send/";
    string file2="4.zip";
    string file=file1+file2;
    udp();
}
int main(int argc, char ** argv) {
    udpClient();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}