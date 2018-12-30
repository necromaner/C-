#include "udp/Udp.h"
#include "test/Test.h"
void test(int argc, char ** argv){
    Test test;
    test.test(argc,argv);
}
int main(int argc, char ** argv) {
    int x = 1;
    switch (x) {
        case 0:
//            udp();
            break;
        case 1:
            test(argc, argv);
            break;
        default:
            break;
    }
}