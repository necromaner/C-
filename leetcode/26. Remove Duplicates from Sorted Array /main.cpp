/* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question.

 */



#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int bb = 0;                     //重复出现的个数
        sort(nums.begin(), nums.end());//排序（头，尾，排序方式）
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                ++bb;
            } else
                nums[i - bb] = nums[i];
        }
        nums.erase(nums.end() - bb, nums.end());  //删除后面 重复出现的个数
        return nums.size();;
    }
};


int main() {
    Solution solution;
    vector<int> aa={1,6,1,2,6,4,3,1,7,8,9,6,4,3,1,1,1,0};//0 1 1 1 1 1 1 2 3 3 4 4 6 6 6 7 8 9
    vector<int> ab={2};

    vector<int> a=aa;
    cout<<"size   : "<<a.size()<<endl<<"Input  : ";
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    solution.removeDuplicates(a);
    cout<<"size   : "<<a.size()<<endl<<"Output : ";
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}