//5.20：编写一段程序，从标准输入中读取string对象的序列直到连续出现两个相同的单词或者所有单词都读完为止。使用while循环一次读取一个单词，当一个单词连续出现两次时使用break语句终止循环。输出连续重复出现的单词，或者输入一个消息说明没有任何单词是连续重复出现的。


#include <iostream>
#include<string>
using namespace std;

int main() {
    string aa, bb, word, pastword;
    cout << "Input endenter is over" << endl << "enter :";
    cin >> aa;
    pastword = aa;
    if(pastword=="endenter"){
        cout << "Not recur word";
        return 0;
    }
    cout << "enter :";

    while (cin >> bb) {
        word = bb;

        if (pastword == word) {
            cout << "recur word is " << word << endl;
            break;
        } else if (bb == "endenter")
            cout << "Not recur word";
        else {
            pastword = bb;
            cout << "enter :";
        }

    }
    return 0;
}