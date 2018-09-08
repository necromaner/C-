/*Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
 */

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> answer;
        int d = 0;
        vector<int> error{-1, -1};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if(d>1){
                    answer[1]=i;
                }
                    else{
                answer.push_back(i);}
                ++d;
            }
        }
        if (d > 0)
            if (d > 1) {
                return answer;
            } else {
                answer.push_back(answer[0]);
                return answer;
            }
        else
            return error;
    }
};

int main() {
    Solution solution;
    vector<int> a={1,6,1,2,6,4,3,1,7,8,9,6,4,3,1,1,1,0};//0 1 1 1 1 1 1 2 3 3 4 4 6 6 6 7 8 9
    int b=1;

    cout<<"Input  : ";
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl<<"target :"<<b<<endl;
    cout<<"answer is : ";
    for(auto j:solution.searchRange(a,b)){
        cout<<j<<" ";
    }
    cout<<endl;
    return 0;
}