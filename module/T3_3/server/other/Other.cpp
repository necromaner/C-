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
std::string Other::set_To_String(std::set<long long> y, const std::string &delim) {
    if(y.empty())
        return "COMPLETE";
    std::string s;
    std::set<long long>::iterator it;
    for (it = y.begin(); it != y.end(); it++) {
        if (*it < 0)
            return "ERROR";
        char s1[40] = "";
        sprintf(s1, "%lld%s", *it+1, delim.c_str());
        s += s1;
    }
    s.pop_back();
    return s;
}
std::set<long long> Other::string_to_Set(std::string str, const std::string &delim) {
    std::set<long long> y;
    if (str.empty()) return y;
    char *strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());
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
int File::setFile(long long int size, int block, int send) {
    File::size = size;
    File::block = block;
    File::send = send;
    int error=checkProblem();
    if(error==0){
        fileMessage=true;
    }
    return error;
}
void File::setFileName(const std::string &file1,const std::string &file2) {
    fileName= true;
    File::file1 = file1;
    File::file2 = file2;
}
long long File::file_Size() {
    if(!fileName)//判断是否文件名初始化
        return -1;
    fp = fopen(getFileName().c_str(), "r");
    if (!fp) return -2;
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
    int error = checkProblem();
    if (error != ZERO)
        return error;
    if (size % block == 0)//文件和块成倍数
        return size / block-1;
    else//文件和块不成倍数
        return size / block;
}
int File::get_Block_Size(long long int blockNum) {
    long long x = get_Block_Num();
    if (x < ZERO)//继承之前的错误
        return (int) x;
    if (block >= size)//块大小大于文件大小
        return (int) size;
    if (blockNum > x || blockNum < ZERO)//块序号不在正确块范围内
        return -21;
    if (blockNum != x)//非最后一块
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
    long long block_Size=get_Block_Size(num);
    if (block_Size <= 0)
        return error;

    char *read=new char[block_Size];
    fp = fopen(getFileName().c_str(), "rb+");
    fseek(fp, num*block, SEEK_SET);//写入坐标
    fread(read, sizeof(char), (size_t )block_Size, fp);
    fclose(fp);
    return read;
}
bool File::writeFile(char *buf, long long num) {
    long long block_Size=get_Block_Size(num);
    if (block_Size <= 0)
        return false;

    fp = fopen(getFileName().c_str(), "rb+");
    fseek(fp, num * block, SEEK_SET);//写入坐标
    fwrite(buf, sizeof(char), (size_t) block_Size, fp);
    fclose(fp);
    return true;
}