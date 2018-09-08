/*Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
 */



#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int bb = 0;
        sort(nums.begin(), nums.end());//排序（头，尾，排序方式）
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                ++bb;
            } else {
                nums[i - bb] = nums[i];
            }
        }
        nums.erase(nums.end() - bb, nums.end());  //删除后面 重复出现的个数
        return nums.size();;
    }
};

int main() {
    Solution solution;
    vector<int> a={1,6,1,2,6,4,3,1,7,8,9,6,4,3,1,1,1,0};//0 1 1 1 1 1 1 2 3 3 4 4 6 6 6 7 8 9
    int b=1;

    cout<<"size   : "<<a.size()<<endl<<"Input  : ";
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    solution.removeElement(a,b);
    cout<<"size   : "<<a.size()<<endl<<"Output : ";
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}