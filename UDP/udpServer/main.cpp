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
int file_size2(char* filename)
{
    struct stat statbuf;
    stat(filename,&statbuf);
    int size=statbuf.st_size;
    
    return size;
}
int file_size(string filename)
{
    FILE *fp=fopen(filename.c_str(),"r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    int size=ftell(fp);
    fclose(fp);
    
    return size;
}
string parseFilepath(string filepath)//获取文件名
{
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
            string file="/Users/necromaner/program/C-/UDP/test/send/123.zip";
            if ((fp = fopen(file.c_str(), "r")) == NULL) {
                perror("打不开文件\n");
                exit(0);
            } else
                printf("-|1.打开文件\n");
            //2.发送文件信息
            printf("-|2.发送文件信息:\n");//文件名/文件大小/每次发送大小
            printf("    文件名：%s，每次发送大小%d字节\n",parseFilepath(file).c_str(),MAXLINE);
            printf("    大小：%d字节,需要发送%d次\n",file_size(file),file_size(file)/MAXLINE+1);
    
            
            while (1){
                char md5[32];
                bzero(buf, MAXLINE);
                sprintf(buf, "%s/%d/%d", parseFilepath(file).c_str(),file_size(file),MAXLINE);
                sendto(ss, buf, sizeof(buf), 0, (struct sockaddr *) &server_addr, len);
                printf("发送传输信息：%s\n",buf);
                sprintf(buf,"%s",MD5(buf).c_str());
                sendto(ss, buf, sizeof(buf), 0, (struct sockaddr *) &server_addr, len);
                printf("发送 MD5 为：%s\n",buf);
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
            
            
            
            //2。读取并发送
            printf("-|3.读取并发送");
            int num=0;
            while ((fread(buf, sizeof(char), MAXLINE, fp)) > 0) {
                num++;
//                printf("大小：%d\n",sizeof(buf));
                send_len = sendto(ss, buf, sizeof(buf), 0, (struct sockaddr *) &server_addr, len);
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