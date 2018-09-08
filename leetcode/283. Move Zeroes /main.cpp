/* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int bb = 0;
        int cc;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]==0){
                ++bb;
            } else {
                nums[i - bb] = nums[i];
            }
        }
        for(int j=bb;j>0;j--){
            nums[nums.size()-j]=0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> a={1,6,1,2,6,4,3,1,0,0,7,8,0,0,9,6,4,3,1,1,1,0};//0 0 0 0 0 1 1 1 1 1 1 2 3 3 4 4 6 6 6 7 8 9

    cout<<"size   : "<<a.size()<<endl<<"Input  : ";
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    solution.moveZeroes(a);
    cout<<"size   : "<<a.size()<<endl<<"Output : ";
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}