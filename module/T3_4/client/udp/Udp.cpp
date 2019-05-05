#include <iostream>
#include "Udp.h"
Udp::Udp() {
    test=false;
    for (int i = 0; i < RESIVE; ++i) {
        re.isnum[i]=false;
    }
    tttt=0;
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
    printf("2.启动udp客户端连接服务器\n");
    test=true;
    this->ss = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(ADDRESS);
}
void Udp::fileName(const std::string& name){
    printf("3.发送文件名\n");
    file.setFile2(name);
    Data data;
    data.flag=INFDS;
    data.block_Num=ZERO;
    data.send_Num=ZERO;
    data.md5="md5";
    sprintf(data.buf,"%s",name.data());
    Message((char *) &data, sizeof(data));
}


void Udp::setBlock_No(){
    for (int i = 0; i < file.getBlockMaxNum()+1; ++i) {
        block_No.insert(i);
    }
}
void Udp::eraseBlock_No(long long int num){//删除块序号
    block_No.erase(num);
}
bool Udp::File_Information(){
    printf("7.接收文件信息\n");
    Message();
    Data data;
    memcpy(&data, buf, sizeof(data));
    FileInformation fl;
    memcpy(&fl,&data.buf, sizeof(FileInformation));
    int Error=file.setFile(fl.size,fl.block,fl.send);
    if(Error<0){
        printf("  文件信息设置失败；错误代码:%d\n",Error);
        return false;
    }
    setBlock_No();
    file.newFile();
    return true;
}

void Udp::show() const {
    printf("  名称: %s\n",file.getFile2().c_str());
    printf("  大小: %lld\n",file.getSize());
    printf("  块数: %lld\n",file.getBlock());
    printf("  发送大小: %lld\n",file.getSend());
}

void Udp::thread_Main() {

    std::map<int, std::vector<int>> maps;

    printf("8.主线程:发送需要接收文件块序及块分割的序号\n");
    while (true) {
        //3.检查序号
        if (!setRE()) {
            std::cout << "结束！！！！！！1" << std::endl;
            break;
        }

        //1.发送序号
        sendRE();
        //2.接收文件
        receiveData();
    }
    printf("跳出\n");
    std::string a;
//    std::cin >> a;
    Data data;
    data.flag = fileEnd;
    data.block_Num = 0;
    data.send_Num = 0;
    data.md5 = "md5";
    sprintf(data.buf, "");
    Message((char *) &data, sizeof(data));
}
//6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6
std::set<int> Udp::getNowBlock(int num){
    int size=file.get_Buf_Num(num)+1;
    std::set<int> qw;
    for (int i = 0; i < size; ++i) {
        qw.insert(i);
    }
    return qw;
}
std::set<int> Udp::setSet_int(long long int num) {
    std::set<int> sss;
    for (int i = 0; i < num; ++i) {
        sss.insert(i);
    }
    return sss;
}
bool Udp::setRE() {//添加RE
    bool isSet = false;
    //1.检查需要接收的块是否为空
    if (block_No.empty()) {
        if (!re.isnum[0] && !re.isnum[1] && !re.isnum[2]) {//如果接收区所有内容都接收成功
            return false;
        }
        return true;
    }
    //2.如果文件接收完成添加新的到接收区，并删除添加的接收的块
    for (int i = 0; i < RESIVE; ++i) {
        if (!re.isnum[i]) {//false
            long long int num = *block_No.begin();
            re.num[i] = num;
            re.isnum[i] = true;
            re.data[i] = getNowBlock(num);
            block_No.erase(block_No.begin());//删除
        }
        isSet = true;
        if (block_No.empty()) {
            break;
        }
    }
    printf("%lld %lld %lld\n",re.num[0],re.num[1],re.num[2]);
    return isSet;
}
void Udp::sendRE() {
    Other other1;
    for (int i = 0; i < RESIVE; ++i) {
        if (re.isnum[i]) {
            std::string setString = other1.set_To_String(re.data[i], CUT2, CUT3);//转换成短序号
            if(setString=="COMPLETE"){
                printf("ERROR5:数组为空\n");
            }else{
                std::vector<std::string> setStrings = stringVector_SIZE(setString);//短序号根据发送大小进行切割
                for (int j = 0; j < setStrings.size(); ++j) {//发送切割后的短序号
                    Data data;
                    data.flag = blockdata;
                    data.block_Num = re.num[i];
                    data.send_Num = 0;
                    data.md5 = "md5";
                    sprintf(data.buf, "%s", setStrings[j].c_str());
                    Message((char *) &data, sizeof(data));
                }
            }
        }
    }
}
void Udp::receiveData(){
    //1.接收文件
    while (true){
        Message();
        Data data;
        memcpy(&data, buf, sizeof(Data));
        if(data.flag==blockdata){
            //2。检查文件
            //3。存入文件
            bool aaa=true;
            for (int i = 0; i < RESIVE; ++i) {
                if (data.block_Num == re.num[i]) {
                    re.data[i].erase(data.send_Num);
                    memcpy(re.maps[i][data.send_Num],data.buf,MAX_SEND);
                    aaa = false;
                }
                tttt++;
            }
            if(aaa){
                printf("ERROR3:没有找到块序！ %lld [%lld %lld %lld]\n",data.block_Num,re.num[0],re.num[1],re.num[2]);
            }
        } else if(data.flag==fileEnd){
//            printf("本次发送结束\n");
            break;
        }
    }
    //4。检查块是否满
    for (int i = 0; i < RESIVE; ++i) {
        if(re.data[i].empty()&&re.isnum[i]==true){
            std::map<int, std::set<int>>::iterator maps1;
            std::map<int,char[MAX_SEND]>::iterator it;
            int i=0;
            for(it=re.maps[i].begin ();it!=re.maps[i].end ();it++)
            {
//                printf("连接坐标%d\n",it->first);
//                memcpy(block+i*it->first,it->second,MAX_SEND);
//                printf("%s",it->second);
            }
//            printf("\n");
            printf("块%lld接收完成\n",re.num[i]);
            re.isnum[i]=false;
        }
    }
}

std::vector<std::string> Udp::stringVector_SIZE(std::string s) {
    std::vector<std::string> cuts;
    int begin = 0;
    int cutSize = MAX_SEND - 1;
    long long int maxSize = s.length();
    while (1) {
        if (begin + cutSize >= maxSize) {
            cuts.push_back(s.substr(begin));
            break;
        }
        int end = begin + cutSize;
        while (end > begin) {
            if (s[end] == CUT2) {
                cuts.push_back(s.substr(begin, end - begin));
                begin = end + 1;
                break;
            }
            end--;
        }
    }
    return cuts;
}