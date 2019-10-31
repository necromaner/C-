//#include "RC4.h"
#include <iostream>
//int main() {
//    RC4 rc4;
//
//    RC4::testRC4(128,1024);
//    RC4::demoRC4();
//    return 0;
//}


//#include "DES.h"
//#include <iostream>
//int main() {
//
//	char a[9] = { '3','1','3','4','5','6','7','8','\0' };
//	char text[100] = "hello DEShello DEShello DES";
//	//明文八字节(除去0),所以密文也是正好一个bdata64
//	//a作为秘钥
//	DES myDes(a);//a作为秘钥传入构造函数,这里可以直接传一个char数组或者我定义的bdata64数据结构
//	//加密text
//	DES::bdata64* secret = myDes.encode(text);
//	//打印加密后的二进制,可以用于查看
//	DES::showBdata64InB(secret, 2);//show Bdata64 in binary
//	//myDes.key.showExKey();这里还可以打印16个秘钥,但我这里注释了,如果想查看把注释取消就是
//	DES::bdata64* mingwen = myDes.decode(secret, 2);//解密,需要注意后面的int代表几个bdata64,八个字节为一个bdata64,也就你明文长度除以8+1;
//	DES::showBdata64InC(mingwen, 2);//打印明文
//	delete secret;
//	delete mingwen;
//	getchar();
//	return 0;
//}

#include "AES.h"
#include <string>
using namespace std;
void print(unsigned char* state);
int main(int argc, char* argv[]){
//    unsigned char input[] ={
//            0x32, 0x43, 0xf6, 0xa8,
//            0x88, 0x5a, 0x30, 0x8d,
//            0x31, 0x31, 0x98, 0xa2,
//            0xe0, 0x37, 0x07, 0x34
//    };
//    char* p="how are you ?";
//    strcpy(reinterpret_cast<char *>(input), p);
    unsigned char key[]={
            0x2b, 0x7e, 0x15, 0x16,
            0x28, 0xae, 0xd2, 0xa6,
            0xab, 0xf7, 0x15, 0x88,
            0x09, 0xcf, 0x4f, 0x3c
    };//128位，16字节
    AES aes(key);
//
//    printf("Input:\n");
//    print(input);
//
//    aes.Cipher(input);
//    printf("After Cipher:\n");
//    print(input);
//
//    aes.InvCipher(input);
//    printf("After InvCipher:\n");
//    print(input);
    string sss=" \tTdLbSszlxN4XDDKh226JbcDrT1TzwshYZ5e6VUlz+wuEEJyv3jw6OF8d5Mnv1AGz2c3mk4MyhK5La6x/8cHx0PHuLo5e3Fn7oUcTFDNMZnxPKiX36SF+Zf/KFzsUwNOpSx+LZlgkd7Xxd4tI+J8q5yaASeVGse1uiNJmdcO6EYTDO6DKona8wGo0aiIgESorBQKhcK2gck6bYWEX4oSffIWcMA3l36keZcpmfMT+ZjlL7fAn880BcyjIW349uTV5Ia3NE7WaP3U/wo7c9HGB++8b5Oe9QsPnE01L9+/SGGziKDwJd9L11W7Y2SjwQL+qFNkHLdKODFgHyjE7JzuvRumR9+1RA1ikkmvuka6eX75bCX58LT6jydNi0wE24S0wQq7gXhYOC6ZHO45IUNAMp8+bxj5qiV41DKH5T+MngwYZrGs7F3NXOVH3l3YB2Pfyw6Xdq2K21bO395U7hbVdOR/9c3NtYFyJuoihyJ0MqbjzLxAa74jdBXojGfBStddGTjYID/4K5OFF/hWfz8HGF0Y0lyB2LTyqiskS5GKneCA=";

    cout<<sss.size();
    int j;
    printf("\n");
    char str[1000] = "Hello,My AES Cipher!";
    sprintf(str,sss.c_str());
    char *xxx=str;
    printf("%s\n",xxx);
    for(j=0; j<1000; j++)printf("%X ",str[j]);
    printf("\n");
    aes.Cipher((void *)str);
    printf("%s\n",xxx);
    for(j=0; j<1000; j++)printf("%X ",(unsigned char)str[j]);
    printf("\n");
    aes.InvCipher((void *)str,21);
    printf("%s\n",xxx);
    for(j=0; j<1000; j++)printf("%X ",(unsigned char)str[j]);
    printf("\n");

    return 0;
}

void print(unsigned char* state){
    int i;
    for(i=0; i<16; i++){
        printf("%s%X ",state[i]>15 ? "" : "0", state[i]);
    }
    for(int i=0;i<16;i++) printf("%02x ",state[i]);
    printf("\n");
}