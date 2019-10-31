#include "Leetcode.h"
//1. 两数之和
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

执行用时 :148 ms, 在所有 cpp 提交中击败了50.71% 的用户
内存消耗 :9.3 MB, 在所有 cpp 提交中击败了78.39%的用户
 */
vector<int> Solution::twoSum(vector<int>& nums, int target){
    int size=nums.size();
    for(int i=0;i<size-1;i++){
        int nums1=target-nums[i];
        for(int j=i+1;j<size;j++){
            if(nums1==nums[j])
                return {i,j};
        }
    }
    return {};
}
//2. 两数相加
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
 */
ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {


    return nullptr;
}
//7. 整数反转
/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:
输入: 123
输出: 321

示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21

注意:
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 */
//执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
//内存消耗 :8 MB, 在所有 cpp 提交中击败了97.19%的用户
const long  MAX = (1<<31)-1, MIN = (-1<<31); //最大最小值
int Solution::reverse(int x) {
    if (x / 10 == 0) return x; //绝对值小于10，直接返回
    long y = 0;
    while (x) {
        y *= 10;
        if (y > MAX || y < MIN)
            return 0;
        y += x % 10; //取出x的个位
        x /= 10;     //去掉x的个位
    }
    return y;
}
//9. 回文数
 /*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:
输入: 121
输出: true

示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

进阶:
你能不将整数转为字符串来解决这个问题吗？

//执行用时 :12 ms, 在所有 cpp 提交中击败了88.65% 的用户
//内存消耗 :8.1 MB, 在所有 cpp 提交中击败了82.64%的用户
*/
bool Solution::isPalindrome(int x) {
    int x1=x;
    if(x1<10&&x1>=0){
        return true;
    }
    if(x1<0||x1>2147447412){
        return false;
    }

    int j=0;
    while(x1>0){
        j=j*10+x1%10;
        x1/=10;
    }
    return x == j ? true : false;
}
//13. 罗马数字转整数
 /*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:
输入: "III"
输出: 3

示例 2:
输入: "IV"
输出: 4

示例 3:
输入: "IX"
输出: 9

示例 4:
输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.

示例 5:
输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
 */
//执行用时 :8 ms, 在所有 cpp 提交中击败了98.32% 的用户
//内存消耗 :8.3 MB, 在所有 cpp 提交中击败了94.54%的用户
int Solution::romanToInt(string s) {
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
//14. 最长公共前缀
/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:
所有输入只包含小写字母 a-z 。
 */
//执行用时 :8 ms, 在所有 cpp 提交中击败了71.48% 的用户
//内存消耗 :8.8 MB, 在所有 cpp 提交中击败了78.58%的用户
string Solution::longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())
        return "";
    int size=strs.size();
    if(size==1)
        return strs[0];
    int minsize=strs[0].size();
    int minsize1;
    for (int i = 1; i < size; ++i) {
        minsize1=strs[i].size();
        if(minsize>minsize1)
            minsize=minsize1;
    }
    if(minsize==0)
        return "";
    int j;
    for (j = 0; j < minsize; ++j) {
        char first=strs[0].at(j);
        for (int i = 1; i < size; ++i) {
            if(first!=strs[i].at(j))
                return strs[0].substr(0,j);
        }
    }
    return strs[0].substr(0,j);
}
//15. 三数之和
 /*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
[-1, 0, 1],
[-1, -1, 2]
]
 */
//执行结果：
//超出时间限制
vector<vector<int>> Solution::threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());//排序（头，尾，排序方式）
    vector<vector<int>> answer;
    vector<int> answer1;
    if (nums.size() < 3) {
        return answer;
    }
    /*
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]);
        else {
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]);
                else {
                    for (int k = j + 1; k < nums.size(); k++) {
                        if (k > j + 1 && nums[k] == nums[k - 1]);
                        else {
                            if (nums[i] + nums[j] + nums[k] == 0) {
                                answer1 = {nums[i], nums[j], nums[k]};
                                answer.push_back(answer1);
                            }
                        }
                    }
                }
            }
        }
    }*/
    for (int i = 0; i < nums.size(); i++) {
        int j = i + 1;
        int k = nums.size() - 1;
        cout<<j<<" "<<k<<endl;
        while (j != k) {
            if (nums[j] == nums[i] + nums[k]) {
                answer1 = {nums[i], nums[j], nums[k]};
                answer.push_back(answer1);
            } else if (nums[j] < nums[i] + nums[k]) {//0 -1 2
                cout<<"k--"<<j<<" "<<k<<endl;
                k--;
            } else {
                cout<<"j++"<<j<<" "<<k<<endl;
                j++;
            }
        }
    }
    return answer;
}
void Solution::threeSum1(vector<int> &nums,vector<vector<int>> &answer,vector<int> &answer1,int i,int j,int k){
    for(int m=0;m<nums.size()-3;m++){
        while(j!=k){
            if(nums[j]==nums[i]+ nums[k]){
                answer1 = {nums[i], nums[j], nums[k]};
                answer.push_back(answer1);
            }else if(nums[j]<nums[i]+ nums[k]){//0 -1 2
                k--;
            }else{
                j++;
            }
        }
    }

}
//20. 有效的括号
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true

示例 3:
输入: "(]"
输出: false

示例 4:
输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true
 */

bool Solution::isValid(string s) {
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
//22. 括号生成
/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
例如，给出 n = 3，生成结果为：

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
 */
//执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
//内存消耗 :13.8 MB, 在所有 cpp 提交中击败了90.93%的用户
vector<string> Solution::generateParenthesis(int n) {
    vector<string> answer;
    string answer1 = "";
    if (n == 0)
        return answer;
    dfs(answer, answer1, n, 0, 0);
    return answer;
}
void Solution::dfs(vector<string> &answer, string &answer1, int n, int digit, int leftparenthesis) {
    if (digit == n * 2) {
        answer.push_back(answer1);
        return;
    }
    if (leftparenthesis < n) {
        answer1.push_back('(');
        dfs(answer, answer1, n, digit + 1, leftparenthesis + 1);
        answer1.pop_back();
    }
    if (leftparenthesis * 2 > digit) {
        answer1.push_back(')');
        dfs(answer, answer1, n, digit + 1, leftparenthesis);
        answer1.pop_back();
    }
}
//26. 删除排序数组中的重复项
/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:
给定数组 nums = [1,1,2],
函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
你不需要考虑数组中超出新长度后面的元素。

示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
你不需要考虑数组中超出新长度后面的元素。

说明:
为什么返回数值是整数，但输出的答案是数组呢?
请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
你可以想象内部操作如下:
// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);
// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
print(nums[i]);
}
*/
//执行用时 :48 ms, 在所有 cpp 提交中击败了35.79% 的用户
//内存消耗 :10 MB, 在所有 cpp 提交中击败了76.56%的用户
int Solution::removeDuplicates(vector<int> &nums) {
    int bb = 0;                     //重复出现的个数
    sort(nums.begin(), nums.end());//排序（头，尾，排序方式）
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            ++bb;
        } else
            nums[i - bb] = nums[i];
    }
    nums.erase(nums.end() - bb, nums.end());  //删除后面 重复出现的个数
    return nums.size();
}
//27. 移除元素
/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1:
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
你不需要考虑数组中超出新长度后面的元素。

示例 2:
给定 nums = [0,1,2,2,3,0,4,2], val = 2,
函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
注意这五个元素可为任意顺序。
你不需要考虑数组中超出新长度后面的元素。

说明:
为什么返回数值是整数，但输出的答案是数组呢?
请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:
// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);
// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 */
//执行用时 :4 ms, 在所有 cpp 提交中击败了90.08% 的用户
//内存消耗 :8.6 MB, 在所有 cpp 提交中击败了78.36%的用户
int Solution::removeElement(vector<int> &nums, int val) {
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
    return nums.size();
}

//34. 在排序数组中查找元素的第一个和最后一个位置
/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]

示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
 */
//执行用时 :12 ms, 在所有 cpp 提交中击败了66.92% 的用户
//内存消耗 :10.2 MB, 在所有 cpp 提交中击败了92.34%的用户
vector<int> Solution::searchRange(vector<int> &nums, int target) {
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
//38. 报数
/*
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
注意：整数顺序将表示为一个字符串。

示例 1:
输入: 1
输出: "1"

示例 2:
输入: 4
输出: "1211"
 */
//执行用时 :32 ms, 在所有 cpp 提交中击败了6.12% 的用户
//内存消耗 :59 MB, 在所有 cpp 提交中击败了11.10%的用户
string Solution::countAndSay(int n) {
    string answer = "1";
    if (n <= 1) {
        return answer;
    }
    for (int i = 1; i < n; i++) {
        countAndSay1(answer);
    }
    return answer;
}
void Solution::countAndSay1(string &answer) {
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
