#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <zconf.h>
#include <cstring>
#include <string>
#include <sys/stat.h>
using namespace std;
#include "Md5.hpp"

int file_size(string filename) {
    FILE *fp=fopen(filename.c_str(),"r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    int size=ftell(fp);
    fclose(fp);
    
    return size;
}
string parseFilepath(string filepath){//获取文件名
    if (!filepath.empty())
    {
        int locfilename = filepath.find_last_of('/');
        return filepath.substr(locfilename + 1, locfilename-1);
    }
}
string MD5(char* buf){
    string answer="";
    unsigned char encrypt[]="";
    unsigned char decrypt[16];
    sprintf(reinterpret_cast<char *>(encrypt),buf);
    MD5_CTX md5;
    
    MD5Init(&md5);
    MD5Update(&md5, encrypt, (int)strlen((char *)encrypt));//只是个中间步骤
    MD5Final(&md5, decrypt);//32位
    for (int i = 0; i<16; i++){
        
        char firstNum[32] = {0};
        sprintf(firstNum, "%02x", decrypt[i]);
        answer.push_back(firstNum[0]);
        answer.push_back(firstNum[1]);
    }
    return answer;
}

struct Data{
    char buf[BUFSIZ];
    int num;
    string md5;
};
#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
#define    MAXLINE        1024
#define    PORT           8888
int main() {
    /*1.socket()*/
    int ss = socket(AF_INET, SOCK_DGRAM, 0);
    printf("1.socket()\n");
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    
    /*2.bind()*/
    if (bind(ss, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        
        printf("创建套接字失败!\n");
        exit(1);
    } else
        printf("2.bind()\n");
//--------------------------------------------------------------------------------
    char buf[BUFSIZ];
    FILE *fp;
    int count = 1;
    
    while (1) {
        bzero(buf, BUFSIZ);
        /*3.recvfrom()*/
        socklen_t len = sizeof(server_addr);
        if (recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len) <= 0) {
            printf("接收数据失败!\n");
            exit(1);
        }
        printf("3.recvfrom()\n");
        
        if (!strcmp(buf, "exit")) {
            break;
        }
        printf("client:%s\n", buf);
        if (!strcmp(buf, "send")) {
            printf("-|开始发送文件\n");
            int send_len;
            //1。打开文件
            string file="/Users/necromaner/program/C-/UDP/test/send/send.txt";
            if ((fp = fopen(file.c_str(), "r")) == NULL) {
                perror("打不开文件\n");
                exit(0);
            } else
                printf("-|1.打开文件\n");
            //2.发送文件信息
            printf("-|2.发送文件信息:\n");//文件名/文件大小/每次发送大小
            printf("    文件名：%s，每次发送大小%d字节\n",parseFilepath(file).c_str(),MAXLINE);
            printf("    大小：%d字节,需要发送%d次\n",file_size(file),file_size(file)/MAXLINE+1);
    
//--------------------------------------------------------------------------------
    
            while (1){
                char md5[32];
                bzero(buf, MAXLINE);
                char buf1[BUFSIZ];
                sprintf(buf1, "%s/%d/%d", parseFilepath(file).c_str(),file_size(file),MAXLINE);
                sprintf(buf,"%s/%s",MD5(buf).c_str(),buf1);
                sendto(ss, buf, sizeof(buf), 0, (struct sockaddr *) &server_addr, len);
                printf("发送传输信息：%s\n",buf);
                sprintf(md5,"%s",buf);
                bzero(buf, MAXLINE);
                if (recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len) <= 0) {
                    printf("接收数据失败!\n");
                    exit(1);
                }
                if(!strcmp(buf, "相同")){
                    printf("传输正确，开始发送文件\n");
                    break;
                } else
                    printf("传输不正确，开始发送文件\n");
            }


//--------------------------------------------------------------------------------
    
            //2。读取并发送
            printf("-|3.读取并发送");
            int num=0;;
            bzero(buf, MAXLINE);
            while ((fread(buf, sizeof(char), MAXLINE-40, fp)) > 0) {
                num++;
                string xxx=to_string(num);
                for (int i = 0; i < 10-xxx.size(); ++i) {
                    xxx="0"+xxx;
                }
                printf("发送数据为：%s\n",buf);
                char md5[32];
                char buf1[BUFSIZ];
                sprintf(buf1,"%s/%s/%s",buf,xxx.c_str(),"d41d8cd98f00b204e9800998ecf8427e");
                send_len = sendto(ss, buf1, sizeof(buf1), 0, (struct sockaddr *) &server_addr, len);
        
                printf("发送长度为：%d\n",send_len);
                if (send_len < 0) {
                    perror("发送失败\n");
                    exit(0);
                }
                bzero(buf, MAXLINE);
            }
            
            
            printf("%d次\n",num);
            bzero(buf, MAXLINE);
            //3。发送结束命令
            strcpy(buf, FINISH_FLAG);
            buf[strlen(buf)] = '\0';//strlen()用来计算字符串的长度
            sendto(ss, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
            printf("-|4.发送结束命令：%s\n",buf);
            
            printf("-|发送完成\n\n");
            break;
        } else {
            sprintf(buf, "已收到%d条文字信息\n", count);
            count++;

            /*4.sendto()*/
            sendto(ss, buf, sizeof(buf), 0, (struct sockaddr *) &server_addr, len);
            printf("send:%s\n", buf);
        }

    }
    
    /*5.close()*/
    close(ss);
    printf("5.close()\n");
    
}