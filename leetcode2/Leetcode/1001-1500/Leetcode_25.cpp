#include "../leetcode.h"
//1207. 独一无二的出现次数
/*
给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。

示例 1：
输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
示例 2：
输入：arr = [1,2]
输出：false
示例 3：
输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
输出：true

提示：
    1 <= arr.length <= 1000
    -1000 <= arr[i] <= 1000
 */
bool Leetcode::uniqueOccurrences(vector<int>& arr) {//2020-10-28
//    执行用时：12 ms, 在所有 C++ 提交中击败了10.83% 的用户
//    内存消耗：8.1 MB, 在所有 C++ 提交中击败了93.34% 的用户
    if (arr.empty())
        return true;
    sort(arr.begin(), arr.end());
    int left = 0, right = left, num = 0, size = arr.size();
    unordered_set<int> ans;
    while (right < size) {
        if (arr[left] == arr[right]) {
            right++;
            num++;
        } else {
            if (ans.find(num) != ans.end())
                return false;
            ans.insert(num);
            num = 0;
            left = right;
        }
    }
    return !(num > 0 && ans.find(num) != ans.end());
}
bool uniqueOccurrences_1(vector<int>& arr) {//抄
//    执行用时：4 ms, 在所有 C++ 提交中击败了92.42% 的用户
//    内存消耗：8.6 MB, 在所有 C++ 提交中击败了9.08% 的用户
    unordered_map<int, int> occur;
    for (const auto& x: arr) {
        occur[x]++;
    }
    unordered_set<int> times;
    for (const auto& x: occur) {
        times.insert(x.second);
    }
    return times.size() == occur.size();
}
