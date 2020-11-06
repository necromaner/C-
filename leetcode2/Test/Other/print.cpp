#include "../Test.h"
TEST(print,print_1) {
    string out;
    string head="CTCI";
    string num="01";
    out="#include \"../Test.h\"\n\n";
    for (int i = 0; i < 20; ++i) {
        out+="//#define TT"+num+"_"+to_string(i+1)+" \n";
        out+="//TEST("+head+",t"+num+"_"+to_string(i+1)+") {\n";
        out+="//    EXPECT_EQ(,"+head+"().TT"+num+"_"+to_string(i+1)+"());\n//}\n";
    }
    printf("%s",out.c_str());
}