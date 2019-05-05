//
// Created by necromaner on 2018/12/10.
//

#include "Udp.h"
Udp::Udp() {
    test=false;
//    fl.send=0;
//    fl.size=0;
//    fl.block=0;
//    fl.name="";
    isEnd=false;
    statusRe=false;
    statusNow=false;
}
Udp::~Udp() {
    if(test){
//        end();
//        Clean();
        printf("*-------------end-------------*\n");
    }
}
void Udp::Message(){//接收消息
    bzero(buf, MAX_SEND_MAX);
    recvfrom(ss, buf, MAX_SEND_MAX, 0, (struct sockaddr *) &server_addr, &len);
}
void Udp::Message(char *message){//发送消息
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
}
void Udp::Message(char *message, unsigned long length){
    sendto(ss, message, length + 1, 0, (struct sockaddr *) &server_addr, len);
}

void Udp::setFile(const std::string &file1) {
    printf("0.设置文件路径\n");
    file.setFile1(file1);
}
void Udp::udpStart(){
    printf("1.启动udp服务器\n");
    test=true;
    this->ss = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    if (bind(this->ss, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("创建套接字失败，服务器启动失败\n");
        exit(1);
    }
}
void Udp::input_Name(const std::string &file22){
    file.setFile2(file22);
}
bool Udp::File_Information() {
    printf("  5.发送文件信息\n");
    FileInformation fl;
    FILE *fp;
    if ((fp = fopen(file.getFileName().c_str(), "r")) == nullptr) {
        printf("  文件不存在\n");
        fl = {"文件不存在", ZERO, ZERO, ZERO};
        file.setFile(ZERO, ZERO, ZERO);
    } else {
        fl = {file.getFile2(), file.file_Size(), MAX_BLOCK, MAX_SEND};
        file.setFile(fl.size, fl.block, fl.send);
    }
    fclose(fp);
    Data data;
    data.flag=INFDS;
    data.block_Num=ZERO;
    data.send_Num=ZERO;
    data.md5="md5";
    memcpy(data.buf,&fl,sizeof(FileInformation));
    Message((char *) &data, sizeof(data));
    return true;
}

void Udp::show() const {
    printf("  名称: %s\n",file.getFile2().c_str());
    printf("  大小: %lld\n",file.getSize());
    printf("  块数: %lld\n",file.getBlock());
    printf("  发送大小: %lld\n",file.getSend());
}
bool Udp::input_RE(long long block_Num,char *bufs) {//将收到的发送序号添加到接收区
    statusRe=true;
    other.map_Insert(mapRe,block_Num,bufs,CUT2);
    printf("  接收到:%lld|%s\n",block_Num,bufs);
    statusRe=false;
    return true;
}
void Udp::input_Thread(){//输入线程
    while (true){
        Message();
        Data data;
        memcpy(&data, buf, sizeof(Data));
        switch (data.flag){
            case INFDS:{//接收文件名
                printf("1.接收文件名\n");
                //1.接收文件信息
                input_Name(data.buf);
                //2.发送文件信息
                if(!File_Information())
                    return;
                show();
                break;
            }
            case blockdata:{//接收回传
//                printf("6.接收回传 \n");
                input_RE(data.block_Num,data.buf);
                //接收回传添加到接收区
                break;
            }
            case fileEnd:{//文件接收完成
                printf("3.文件接收完成\n");
                isEnd=true;//结束
                return;
            }
            case error:{
                //错误信息
                break;
            }
        }
    }
}
void Udp::RE_Thread() {//自动把接收区内容添加到发送区
    while (!(mapRe.empty() && mapWhit.empty() && mapNow.empty() && isEnd)) {
        //1.接收区->等待区
        if (!statusRe && !mapRe.empty()) {//不在接收回传中且接收区不为空
//            printf("  1.接收区：%lu 等待区:%lu 发送区:%lu\n", mapRe.size(), mapWhit.size(), mapNow.size());
            std::map<int, std::string>::iterator iter;
            for (iter = mapRe.begin(); iter != mapRe.end(); iter++) {
                other.map_Insert(mapWhit, iter->first, iter->second, CUT2);
            }
            mapRe.clear();
//            printf("  2.接收区：%lu 等待区:%lu 发送区:%lu\n", mapRe.size(), mapWhit.size(), mapNow.size());
        }
        //2.等待区->发送区
        if (!statusNow && !mapWhit.empty() && mapNow.empty()) {//不在发送文件中且等待区不为空且发送区为空
            mapNow = other.map_String_To_Set(mapWhit, CUT2, CUT3);
            mapWhit.clear();
//            printf("  3.接收区：%lu 等待区:%lu 发送区:%lu\n", mapRe.size(), mapWhit.size(), mapNow.size());
        }
        usleep(1000);
    }
    printf("所有区域都为空RE_Thread\n");
}
void Udp::Send_Thread() {//自动把发送区内容发送到客户端
    while (!(mapRe.empty() && mapWhit.empty() && mapNow.empty() && isEnd)) {
        statusNow = true;//开始使用发送区
        if (!mapNow.empty()) {//发送区不为空，发送数据
            //1.发送数据
            std::string a;
//            std::cin>>a;
            std::map<int, std::set<int>>::iterator maps1;
            for (maps1 = mapNow.begin(); maps1 != mapNow.end(); maps1++) {//发送接收区到每个块
                //1.读区文件获取数据块
                long long blockNum1=maps1->first;
                std::set<int> send_Num1s=maps1->second;
                printf("7.发送块:%lld\n",blockNum1);
//                printf("  发送序号:");
                block=file.readFile(blockNum1);
                if(block== nullptr){
                    printf("打开文件失败\n");
                    continue;
                }
                //2.循环set发送对应分割内容
                std::set<int>::iterator iter;
                for (iter = send_Num1s.begin(); iter != send_Num1s.end(); iter++) {//发送接收区到每个块
                    int size1=file.getNowBufSize(blockNum1,*iter);
                    if(size1>=0){
                        //发送块序为 maps->first 分割序号为 *iter 的数据
                        Data data;
                        data.flag=blockdata;
                        data.block_Num=blockNum1;
                        data.send_Num=*iter;
//                        printf("  从坐标%d开始读区%d\n",*iter*MAX_SEND,size1);
                        memcpy(data.buf, &block[*iter*MAX_SEND],size1);
                        Message((char *) &data, sizeof(data));
//                        printf("%s\n",data.buf);
//                        printf("%s\n",block);
//                        printf("%d ",*iter);
                    }else{
                        printf("ERROR2:%d\n",size1);
                    }
                }
//                printf("\n");
            }
            if(mapWhit.empty()){
                Data data;
                data.flag = fileEnd;
                data.block_Num = 0;
                data.send_Num = 0;
                data.md5 = "md5";
                sprintf(data.buf, "");
                Message((char *) &data, sizeof(data));
            }

            //2.清空发送区
            mapNow.clear();
        }
        statusNow = false;//发送区使用结束
    }
}
