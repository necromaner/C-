/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string s1 = "";
        int count = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}' || s[i] == '[' || s[i] == ']')
                s1 = s1 + s[i];
        }
        if (s1.size() < 2) {
            return 0;
        }
        while (s1.size() > 1) {
            for (unsigned i = 0; i < s1.size();) {
                int count1 = 0;
                if (s1[i] == '(') {
                    if (s1[i + 1] == ')') {
                        s1.erase(i, 2);
                        count++;
                        count1++;
                    }
                }
                if (s1[i] == '{') {
                    if (s1[i + 1] == '}') {
                        s1.erase(i, 2);
                        count++;
                        count1++;
                    }
                }
                if (s1[i] == '[') {
                    if (s1[i + 1] == ']') {
                        s1.erase(i, 2);
                        count++;
                        count1++;
                    }
                }
                if (count1 == 0) {
                    i++;
                }
            }
            if (count == 0) {
                return 0;
            }
            count = 0;
        }
        if (s1.size() == 0) {
            return 1;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    string s = "([]";
    cout << "input : " << s << endl;
    cout << "isValid : " << boolalpha << solution.isValid(s);
}