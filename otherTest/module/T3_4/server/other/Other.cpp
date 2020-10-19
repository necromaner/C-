#include "Other.h"
////----------------time/speed----------------////
int64_t Other::getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
std::string Other::theJetLag(time_t beginTime,time_t endTime) {
    std::string ss;
    if (beginTime == ZERO && endTime == ZERO) {
        return " begin=end=0";
    } else if (beginTime < ZERO) {
        return " begin<0    ";
    } else if (endTime == ZERO) {
        return "   end=0    ";
    } else if (beginTime > endTime) {
        return " begin>end  ";
    } else if (endTime < ZERO) {
        return "   end<0    ";
    } else {
        time_t balance = endTime - beginTime;
        if (balance >= TIME_MAX - TIME_HALF) {
            return " >100 days  ";
        } else {
            time_t s1 = balance;
            time_t days = s1 / TIME_D;
            s1 = s1 % TIME_D;
            time_t hours = s1 / TIME_H;
            s1 = s1 % TIME_H;
            time_t minutes = s1 / TIME_M;
            s1 = s1 % TIME_M;
            time_t seconds = s1 / TIME_S;
            s1 = s1 % TIME_S;
            time_t milliseconds = s1 / TIME_MS;
            if (balance >= TIME_M) {
                if (milliseconds >= TIME_HALF) {
                    seconds++;
                    if (seconds == 60) {
                        seconds = 0;
                        minutes++;
                        if (minutes == 60) {
                            minutes = 0;
                            hours++;
                            if (hours == 24) {
                                hours = 0;
                                days++;
                            }
                        }
                    }
                }
                milliseconds = 0;
            }
            if (days > ZERO) {
                ss += std::to_string(days);
                ss += "d ";
            }
            if (hours > ZERO) {
                if (hours < TIME_10)
                    ss += "0";
                ss += std::to_string(hours);
            } else
                ss += "00";
            ss += ":";
            if (minutes > ZERO) {
                if (minutes < TIME_10)
                    ss += "0";
                ss += std::to_string(minutes);
            } else
                ss += "00";
            ss += ":";
            if (seconds > ZERO) {
                if (seconds < TIME_10)
                    ss += "0";
                ss += std::to_string(seconds);
            } else
                ss += "00";
            if (balance < TIME_M) {
                ss += ".";
                if (milliseconds < TIME_10)//[0,10)
                    ss += "00";
                else if (milliseconds < TIME_10 * TIME_10)//[10,100)
                    ss += "0";
                ss += std::to_string(milliseconds);
            }
            char sss[13];
            sprintf(sss, "%12s", ss.c_str());
            ss = sss;
            return ss;
        }
    }
}
std::string Other::date(time_t unix) {
    char ss[20];
    unix/=TIME_S;
    tm* t= localtime(&unix);
    sprintf(ss,"%d/%02d/%02d %02d:%02d:%02d",
            t->tm_year + 1900,
            t->tm_mon + 1,
            t->tm_mday,
            t->tm_hour,
            t->tm_min,
            t->tm_sec);
    return ss;
}
std::string Other::speed(unsigned long long byte, time_t unix) {
    if (unix <= ZERO)
        return "time error";
    if (SPEED_MAX< (byte*TIME_S) / unix)
        return "   >11 P/s";
    return speed((byte * TIME_S) / unix);
}
std::string Other::speed(long long bs) {
    std::string sl[6] = {SPEED_B, SPEED_K, SPEED_M, SPEED_G, SPEED_T, SPEED_P};
    std::string speeds;
    char ss1[7];
    int num = 0;
    double bss;
    //1.求出最大整数
    while ((bs / (SPEED * SPEED)) >= 1 && num < 4) {
        bs /= 1024;
        num++;
    }
    //2.求分数
    bss = bs;
    if (bss >= 1000) {//bss此时范围：[0,1024*1024)
        bss /= 1024;
        num++;
    }
    if (bss >= 1000) {//bss此时范围：[0,1024)
        bss /= 1024;
        num++;
    }
    //3.保留小数
    bs = (int) bss;
    int k=(int)((bss-bs)*100);//小数点后两位
    if (k==0)
        sprintf(ss1, "%6.0f", bss);
    else if(k%10==9)
        sprintf(ss1, "%6.1f", bss);
    else
        sprintf(ss1, "%6.2f", bss);
    speeds += ss1;
    speeds += sl[num];
    return speeds;

}
////---------------set<long long>-------------////
std::string Other::set_To_String(std::set<int> y, const std::string &delim) {
    if(y.empty())
        return "COMPLETE";
    std::string s;
    std::set<int>::iterator it;
    for (it = y.begin(); it != y.end(); it++) {
        if (*it < 0)
            return "ERROR";
        char s1[40] = "";
        sprintf(s1, "%d%s", *it+1, delim.c_str());
        s += s1;
    }
    s.pop_back();
    return s;
}
std::string Other::set_To_String(std::set<int> y, const char &Cut2, const char &Cut3) {
    if(y.empty())
        return "COMPLETE";
    std::string s=std::to_string(*y.begin()+1);
    std::set<int>::iterator it;
    int size=0;//连续数量
    int lastdata=*y.begin();
    for (it = y.begin(); it != y.end(); it++) {
        if (*it < 0)
            return "ERROR";
        if(size==0){//初始
            lastdata=*it;
            size++;
        }else{
            int now=*it;
            if(now-1==lastdata){//连续
                lastdata=now;
                size++;
            }else{//不连续
                if(size==2){
                    s+=Cut2;
                }else{
                    s+=Cut3;
                }
                s+=std::to_string(lastdata+1)+Cut2+std::to_string(now+1);
                lastdata=now;
                size=1;
            }
        }
    }
    if(size==2){
        s+=Cut2+std::to_string(lastdata+1);
    }else if(size>2){
        s+=Cut3+std::to_string(lastdata+1);
    }
    return s;
}
std::vector<std::string> Other::split(const std::string& str, const std::string& delim) {
    std::vector<std::string> res;
    if(str.empty()) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char * strs = new char[1] ; //不要忘了
    strcpy(strs, str.c_str());

    char * d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while(p) {
        std::string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(nullptr, d);
    }

    return res;
}
std::set<int> Other::string_to_Set(std::string str1, const char &Cut2, const char &Cut3) {
    std::set<int> y;
    if (str1.empty()) return y;
    std::string sp;
    sp.push_back(Cut2);
    std::vector<std::string> v = split(str1, sp);
    for(int i=0; i<v.size(); i++){
        std::string sp3;
        sp3.push_back(Cut3);
        std::vector<std::string> v2 = split(v[i], sp3);
        if(v2.size()==1){
            int n = atoi(v2[0].c_str());
            y.insert(n-1);
        }else if(v2.size()==2){
            int n1 = atoi(v2[0].c_str());
            int n2 = atoi(v2[1].c_str());
            for (int j = n1; j <= n2; ++j) {
                y.insert(j-1);
            }
        }
    }
    return  y;
}
std::set<long long> Other::string_to_Set(std::string str1, const std::string &delim) {
    std::set<long long> y;
    if (str1.empty()) return y;
    char *strs = new char[str1.length() + 1];
    strcpy(strs, str1.c_str());
    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());
    char *p = strtok(strs, d);
    while (p) {
        long long s = strtoll(p, nullptr, 10);
        if (s != 0)
            y.insert(s - 1);
        else{
            y.erase(y.begin(),y.end());
            y.insert(-1);
            return y;
        }
        p = strtok(nullptr, d);
    }
    return y;
}
std::set<long long> Other::initialization_Set(long long num) {
    std::set<long long> y;
    for (int i = 0; i < num; ++i) {
        y.insert(i);
    }
    return y;
}
////--------------map<int,string>-------------////
void Other::map_Insert(std::map<int,std::string> &maps,int num,std::string sss, const char &Cut2) {
    std::map<int, std::string>::iterator iter;
    iter = maps.find(num);
    if (iter != maps.end())
        iter->second += Cut2 + sss;
    else
        maps[num] = sss;
}
std::map<int,std::set<int>> Other::map_String_To_Set(std::map<int,std::string> &maps, const char &Cut2, const char &Cut3) {
    std::map<int, std::set<int>> mapV;
    std::map<int, std::string>::iterator iter;
    for (iter = maps.begin(); iter != maps.end(); iter++) {
        mapV[iter->first] = string_to_Set(iter->second, Cut2, Cut3);
    }
    return mapV;
}
////------------------FILE--------------------////
File::File() {
    Initialize();
}
File::~File() {
    Initialize();
}
void File::Initialize() {
    size = 0;
    block = 0;
    send = 0;
    file1 = "";
    file2 = "";
    fileName = false;
    fileMessage = false;
}
int File::checkProblem() {
    if (size <= ZERO || block <= ZERO || send <= ZERO)
        return -1;
    else if(send>block)
        return -2;
    else
        return 0;
}
////-----------------set/get------------------////
int File::setFile(long long int size1, int block1, int send1) {
    File::size = size1;
    File::block = block1;
    File::send = send1;
    int error1=checkProblem();
    if(error1==0){
        fileMessage=true;
    }
    if(error1>=0){
        setBlockMaxNum();
        setBlockEndSize();
        setBlockEndNum();
        setBufEndSize();
    }
    return error1;
}
void File::setBlockMaxNum() {
    if (size % block == 0)//文件和块成倍数
        File::blockMaxNum = File::size/File::block-1;
    else//文件和块不成倍数
        File::blockMaxNum = File::size/File::block;
}
void File::setBlockEndSize() {
    int size1=File::size%File::block;
    if(size1==0){
        size1= File::block;
    }
    File::blockEndSize = size1;
}
void File::setBlockEndNum() {
    int num1=File::blockEndSize/File::send;
    if(File::blockEndSize%File::send!=0){
        num1++;
    }
    File::blockEndNum = num1-1;
}
void File::setBufEndSize() {
    int size1=getBlockEndSize()%File::send;
    if(size1==0){
        size1=File::send;
    }
    File::bufEndSize = size1;
}
void File::setFile1(const std::string &file11) {
    File::file1 = file11;
}
void File::setFile2(const std::string &file22) {
    File::file2 = file22;
    fileName= true;
}
void File::setFileName(const std::string &file11,const std::string &file22) {
    fileName= true;
    File::file1 = file11;
    File::file2 = file22;
}


long long File::file_Size() {
    if(!fileName){//判断是否文件名初始化
        fileError=-4;
        return -4;
    }
    fp = fopen(getFileName().c_str(), "r");
    if (!fp){
        fileError=-5;
        return -5;
    }
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size;
}
long long int File::getSize() const {
    return size;
}
long long int File::getBlock() const {
    return block;
}
long long int File::getSend() const {
    return send;
}
long long int File::get_Block_Num() {
    if (fileError != ZERO)
        return fileError;
    if (size % block == 0)//文件和块成倍数
        return size / block-1;
    else//文件和块不成倍数
        return size / block;
}
int File::get_Block_Size(long long int blockNum) {
    if (blockNum > File::blockMaxNum || blockNum < ZERO)//块序号不在正确块范围内
        return -21;
    if (blockNum != File::blockMaxNum)//非最后一块
        return block;
    else {//最后一块
        if (size % block == 0)
            return block;
        else
            return (int) (size % block);
    }
}

int File::get_Buf_Num(long long int blockNum) {
    int x=get_Block_Size(blockNum);
    if(x<ZERO)//继承之前的错误
        return x;
    if(x%send==0)
        return x/send-1;
    else
        return x/send;
}
int File::get_Buf_Size(long long int blockNum, int bufNum) {
    int x = get_Buf_Num(blockNum);//数据最大序号
    if (x < ZERO)//继承之前的错误
        return x;
    if (bufNum > x || bufNum < ZERO)//数据序号不在正确范围内
        return -31;
    if (send >= size)//数据大于文件
        return (int) size;
    int z = get_Block_Size(blockNum);//当前块大小
    if (z < 0) {
        return -32;
    }
    if (bufNum < x) {//当前块非最后一个数据
        return send;
    } else {//当前块最后一个数据
        if (z % send == 0)
            return send;
        else
            return z % send;
    }
}
const std::string &File::getFile2() const {
    return file2;
}
std::string File::getFileName(){
    return file1+file2;
}
long long int File::getBlockMaxNum() const {
    return blockMaxNum;
}
int File::getBlockEndSize() const {
    return blockEndSize;
}
int File::getBlockEndNum() const {
    return blockEndNum;
}
int File::getBufEndSize() const {
    return bufEndSize;
}

int File::getNowBufBegin(long long int blockNum, int bufNum){//获取当前数据的开始的坐标
    int Error1=judgeBufNum(blockNum,bufNum);
    if(Error1<0){
        return Error1;
    }
    return blockNum*block+bufNum*send;
}
int File::getNowBufSize(long long int blockNum, int bufNum){//获取当前数据的长度
    int Error1=judgeBufNum(blockNum,bufNum);
    if(Error1<0){
        return Error1;
    }
    if(blockNum==blockMaxNum){//最后一块
        if(bufNum==blockEndNum){//最后一个
            return bufEndSize;
        }else{
            return send;
        }
    } else {//非最后一块
        return send;
    }
}
int File::getNowBlockNum(long long int blockNum){
    int Error1=judgeBlockNum(blockNum);
    if(Error1<0){
        return Error1;
    }
    if(blockNum==blockMaxNum){//最后一块
        return File::blockEndSize;
    }else{
        return File::block;
    }
}
int File::judgeBlockNum(long long int blockNum){//判断文件块数是否符合
    if(blockNum>blockMaxNum){
        return -100;
    }
    return 0;
}
int File::judgeBufNum(long long int blockNum, int bufNum){//判断序号是否符合
    int Error1=judgeBlockNum(blockNum);
    if(Error1<0){
        return Error1;
    }
    if(blockNum==blockMaxNum){//最后一块
        if(bufNum>blockEndNum){
            return -110;
        }
    }else{
        if(bufNum>=block/send){
            return -200;
        }
    }
    return 0;
}
////---------------read/write-----------------////
bool File::newFile() {
    if(fileName){
        fp = fopen(getFileName().c_str(), "w+");
        fclose(fp);
        return true;
    }
    return false;
}
char *File::readFile(long long num) {
    long long block_Size=getNowBlockNum(num);
    if (block_Size <= 0)
        return nullptr;
    char *read=new char[block_Size];
//    printf("读区块长度:%lld",block_Size);
    fp = fopen(getFileName().c_str(), "rb+");
    if ((fp = fopen(getFileName().c_str(), "rb")) != nullptr) {
//        printf("从坐标:%lld开始读区%lld\n",num * block,block_Size);
        fseek(fp, num * block, SEEK_SET);//写入坐标
        fread(read, sizeof(char), (size_t) block_Size, fp);
        fclose(fp);
        return read;
    }
    fclose(fp);
    return nullptr;
}

bool File::writeFile(char *buf, long long num) {
    long long block_Size=getNowBlockNum(num);
    if (block_Size <= 0)
        return false;
    fp = fopen(getFileName().c_str(), "rb+");
    fseek(fp, num * block, SEEK_SET);//写入坐标
    fwrite(buf, sizeof(char), (size_t) block_Size, fp);
    fclose(fp);
    return true;
}
