//Determine whether an integer is a palindrome. Do this without extra space.

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int x1=x;
        if(x1<10&&x1>=0){
            return 1;
        }
        if(x1<0||x1>2147447412){
            return 0;
        }

        int j=0;
        while(x1>0){
            j=j*10+x1%10;
            x1/=10;
        }
        if(j==x){
            return 1;
        }else
            return 0;
    }
};

int main() {
    Solution solution;
    int x;
    cout << "Enter : ";
    cin >> x;
    cout << "Input : " << x << endl;
    cout << "isPalindrome : " << boolalpha << solution.isPalindrome(x) << endl;
    return 0;
}