/*The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"

Example 2:

Input: 4
Output: "1211"
*/
/*
 *                                  1
 *                                 11
 *                                 21
 *                               1211
 *                             111221
 *                             312211
 *                           13112221
 *                         1113213211
 *                     31131211131221
 *               13211311123113112211
 *         11131221133112132113212221
 * 3113112221232112111312211312113211
        */
#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string answer = "1";
        if (n <= 1) {
            return answer;
        }
        for (int i = 1; i < n; i++) {
            countAndSay1(answer);
        }
        return answer;
    }

    void countAndSay1(string &answer) {
        string answer1 = "";
        char count = '1';
        for (int i = 0; i < answer.size(); i++) {
            if (answer[i] == answer[i + 1]) {
                count++;
            } else {
                answer1 = answer1 + count + answer[i];
                count = '1';
            }
        }
        answer = answer1;
    }
};

int main() {
    Solution solution;
    int n;
    cout<<"Enter:";
    cin>>n;
    cout<<"countAndSay : "<<solution.countAndSay(n);
    return 0;
}