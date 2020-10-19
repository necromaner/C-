#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>


#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
#define    CORRECT_FLAG    "FILE_TRANSPORT_CORRECT"
#define    AFFIRM_FLAG    "AFFIRM_TRANSPORT_FINISH"


using namespace std;

struct FileInformation{
    string name;
    long size;
    int max;
    int bigblock;
};

struct Data{
    char buf[984];
    int num;
    string md5;
};
struct Success{
    int suc[100]={0};
    int max=0;
};
void receive(int sc,sockaddr_in server_addr);

