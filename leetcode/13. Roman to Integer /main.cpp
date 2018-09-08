/*Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Subscribe to see which companies asked this question.
*/

//题意：把罗马数转为十进制。

//Ｉ=1、Ｖ=5、Ｘ=10、Ｌ=50、Ｃ=100、Ｄ=500和Ｍ=1000
//I II III IV V VI VII VIII IX X  XI XII XIII XIV XV XVI XVII XV111 XIX XX
//1  2   3  4 5  6   7    8  9 10 11  12   13  14 15  16   17    18  19 20

//I     1-   4    9        V   5-  8
//X    10-  49   90-  99   L  50- 89
//C   100- 499  900- 999   D 500-899
//M  1000-4999 9000-9999
/*
I 73
V 86
X 88
L 76
C 67
D 68
M 77
 */

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int answer = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == 'I') {
                if (s[i + 1] == 'I' || s[i + 1] == 0) {//1
                    answer += 1;
                } else if (s[i + 1] == 'V') {//5
                    answer += 4;
                } else if (s[i + 1] == 'X') {//10
                    answer += 9;
                }
            } else if (s[i] == 'V') {
                if (s[i - 1] != 'I') {
                    answer += 5;
                }
            }
            if (s[i] == 'X') {
                if (s[i + 1] == 'L') {//50
                    answer += 40;
                } else if (s[i + 1] == 'C') {//100
                    answer += 90;
                } else if (s[i - 1] != 'I') {
                    answer += 10;
                }
            } else if (s[i] == 'L') {
                if (s[i - 1] != 'X') {
                    answer += 50;
                }
            }
            if (s[i] == 'C') {
                if (s[i + 1] == 'D') {//50
                    answer += 400;
                } else if (s[i + 1] == 'M') {//100
                    answer += 900;
                } else if (s[i - 1] != 'X') {
                    answer += 100;
                }
            } else if (s[i] == 'D') {
                if (s[i - 1] != 'C') {
                    answer += 500;
                }
            }
            if (s[i] == 'M') {
                if (s[i - 1] != 'C') {
                    answer += 1000;
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution solution;
    string aa;
    cout<<"Enter roman numeral:";
    cin>>aa;
    string a="IVXLCDM";
    cout<<" roman  numeral : "<<aa<<endl;
    cout<<"decimal numeral ："<<solution.romanToInt(aa)<<endl;
    return 0;
}