#include <map>
#include "Receive.h"
#include "Output.h"
#include "md5.h"
void sendFlag(int sc,sockaddr_in server_addr,char* flag) {
    //发送结束命令
    char buf[BUFSIZ]={0};
    socklen_t len = sizeof(server_addr);
    strcpy(buf, flag);
    buf[strlen(buf)] = '\0';//strlen()用来计算字符串的长度
    sendto(sc, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
}
//接收命令
void receiveFlag(int ss,sockaddr_in server_addr){
    char buf[BUFSIZ]={0};
    socklen_t len = sizeof(server_addr);
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    printf("接收到：%s\n",buf);
}
void printMD5(const string& message) {
    cout << "md5= "
         << MD5(message).toStr() << endl;
}
vector<int> failure(FileInformation fl,vector<int> xx){
    vector<int> s;
    int ss=(int)fl.size/fl.max+1;
    int j=0;
    for (int i = 0; i < ss;) {
        if(i==xx[j]){
            i++;
            j++;
        } else{
            s.push_back(i);
            i++;
        }
    }
    return s;
}

vector<int> write(map<int,char*> mymap,string file,FileInformation fl) {
    vector<int> xx;
    FILE *fp;
    fp = fopen(file.c_str(), "rb+");
    for (auto it = mymap.begin(); it != mymap.end(); it++) {
        xx.push_back(it->first);
        fseek(fp, it->first * fl.max, SEEK_SET);
    
        printf("write %d-",it->first);
        printMD5(it->second);
        if (it->first == (int) fl.size / fl.max) {
            fwrite(it->second, sizeof(char), (size_t) fl.size % fl.max, fp);
        } else {
            fwrite(it->second, sizeof(char), (size_t) fl.max, fp);
        }
    }
    fclose(fp);
    return failure(fl,xx);
}
void receiveData(int sc,sockaddr_in server_addr,FileInformation fl,map<int,char*> &mymap) {
    while (1) {
        socklen_t len = sizeof(server_addr);
        char recvBuf[BUFSIZ] = {0};
        recvfrom(sc, recvBuf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
        Data data;
        if (strstr(recvBuf, FINISH_FLAG) != NULL) {
            break;
        }
        memcpy(&data, recvBuf, sizeof(data) + 1);
        char* buf= new char[fl.max];
        strcpy(buf, data.buf);
        mymap[data.num] = buf;
        printf("rece1 %d-",data.num);
        printMD5(mymap[data.num]);
    }
}




void receiveData(int sc,sockaddr_in server_addr,string file,FileInformation fl) {
    FILE *fp;
    fp = fopen(file.c_str(), "rb+");
    while (1) {
        socklen_t len = sizeof(server_addr);
        char recvBuf[BUFSIZ] = {0};
        recvfrom(sc, recvBuf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
        Data data;
        if (strstr(recvBuf, FINISH_FLAG) != NULL) {
            break;
        }
        memcpy(&data, recvBuf, sizeof(data) + 1);
        printf("rece2 %d-",data.num);
        printMD5(data.buf);
        fseek(fp, data.num * fl.max, SEEK_SET);
        if (data.num == (int) fl.size / fl.max) {
            fwrite(data.buf, sizeof(char), (size_t) fl.size % fl.max, fp);
        } else {
            fwrite(data.buf, sizeof(char), (size_t) fl.max, fp);
        }
    }
    fclose(fp);
}

FileInformation receiveInformation(int sc,sockaddr_in server_addr){
    socklen_t len = sizeof(server_addr);
    char recvBuf[BUFSIZ]={0};
    recvfrom(sc,recvBuf,BUFSIZ,0,(struct sockaddr *) &server_addr,&len);
    FileInformation fl;
    memcpy(&fl,recvBuf,sizeof(fl)+1);
    printf("接收到：文件名：%s;大小：%ld字节,每次发送大小：%d字节\n",fl.name.c_str(),fl.size,fl.max);

    sendFlag(sc,server_addr,(char*)AFFIRM_FLAG);
    return fl;
}


void receive(int sc,sockaddr_in server_addr) {
    sendFlag(sc, server_addr, (char *) AFFIRM_FLAG);
    
    FileInformation fl = receiveInformation(sc, server_addr);
    
    FILE *fp;
    string file1 = "/Users/necromaner/test/receive/";
    string file2 = fl.name;
    string file = file1 + file2;
    fp = fopen(file.c_str(), "w+");
    fclose(fp);
    
    map<int,char*> mymap;
    
    
//    receiveData(sc,server_addr,file,fl);
    receiveData(sc, server_addr, fl,mymap);
    vector<int> xx=write(mymap,file,fl);
    outPut(xx);
    printf("传输完成-end\n");
}