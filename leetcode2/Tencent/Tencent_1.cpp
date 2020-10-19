#include "Tencent.h"
////数组与字符串
//1 两数之和
/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
 */
vector<int> Tencent::twoSum(vector<int>& nums, int target) {//完成60 ms
    vector<int> answer(2,0);
    int N = nums.size();
    for (int i = 0; i < N-1; ++i) {
        int temp = target -nums[i];
        for (int j = i+1; j < N; ++j) {
            if(temp==nums[j]) {
                answer[0]=i;
                answer[1]=j;
                return answer;
            }
        }
    }
    return answer;
}
//T2 两个排序数组的中位数
/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
你可以假设 nums1 和 nums2 不同时为空。

示例 1:
nums1 = [1, 3]
nums2 = [2]
中位数是 2.0
示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
中位数是 (2 + 3)/2 = 2.5
 */
double Tencent::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double answer=0.0;
    vector<int> x(nums1.size()+nums2.size());
    int x_size= x.size();
    int nums1_size= nums1.size();
    int nums2_size= nums2.size();
    for (int i = 0; i < x_size; ++i) {
        if (i<nums1_size) {
            x[i]=nums1[i];
        } else {
            x[i]=nums2[i-nums1_size];
        }
    }
    for (int j = 0; j < x_size-1; ++j) {
        for (int i = j+1; i < x_size; ++i) {
            if(x[j]>x[i]){
                int max=x[j];
                x[j]=x[i];
                x[i]=max;
            }
        }
    }
    if(x_size%2!=0)
        return x[x_size/2];
    else
        return ((double)(x[x_size/2-1]+x[x_size/2]))/2;
}
//T3 最长回文子串
/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
示例 2：
输入: "cbbd"
输出: "bb"
ccdasacdccs
 cs
 cc-cc-dd-ac
 cc-cd
 cd
 cc-ca
 ca
 cs
 ca
 cd
 cc
 */
string Tencent::longestPalindrome(string s) {
    string answer=s;
    int min=0;
    int max=0;
    int s_size=s.size();
    for (int i = 0; i < s_size; ++i) {
        for (int j = s_size-1; j >i ; --j) {
            if(s[i]==s[j]){
                int k;
                bool yes=1;
                for (k = 1; k <= (j-i)/2; ++k) {
                    if(s[i+k]!=s[j-k]){
                        yes=0;
                        break;
                    }

                }
                if(yes&&(j-i)>(max-min)){
                    min=i;
                    max=j;
                }
            }
        }
    }
    return s.substr(min,max-min+1);
}
//T4 字符串转整数 (atoi)
/*
实现 atoi，将字符串转为整数。
在找到第一个非空字符之前，需要移除掉字符串中的空格字符。如果第一个非空字符是正号或负号，选取该符号，并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。
当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。
若函数不能执行有效的转换，返回 0。

说明：
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。如果数值超过可表示的范围，则返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。

示例 1:
输入: "42"
输出: 42
示例 2:
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
示例 3:
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
示例 4:
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5:
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
     因此返回 INT_MIN (−231) 。
 */
int Tencent::myAtoi(string str) {
    string s = "";
    bool symbol = true;
    bool symbol2 = true;
    int str_size = str.size();
    for (int i = 0; i < str_size; ++i) {
        if (str[i] == ' ' && s.size() == 0 && symbol2) {//祛空格
            continue;
        }
        if (str[i] == '0' && s.size() == 0) {
            s = '0';
            continue;
        }

        if (s.size() == 0 && str[i] == '-' && symbol2) {//负号
            symbol = false;
            symbol2 = false;
            continue;
        }
        if (s.size() == 0 && str[i] == '+' && symbol2) {//正号
            symbol2 = false;
            continue;
        }

        if (str[i] > '9' || str[i] < '0')
            break;

        if (s[0] == '0')
            s = str[i];
        else
            s.push_back(str[i]);
        if (s.size() > 10 || (s.size() == 9 && s[0] > '2'))
            return symbol ? INT32_MAX : INT32_MIN;
    }
    int a = atoi(s.c_str());
    if (a >= 0) {
        if (symbol)
            return a;
        else
            return -a;
    } else {
        if (symbol)
            return INT32_MAX;
        else
            return INT32_MIN;
    }
}
//T5 最长公共前缀
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
string Tencent::longestCommonPrefix(vector<string>& strs) {
    string answer;
    if (strs.size() == 0) return answer;
    for (int i = 0; i < strs[0].size(); ++i) {
        for (int j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[0][i] != strs[j][i])
                return answer;
        }
        answer.push_back(strs[0][i]);
    }
    return answer;
}
//T6 三数之和
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
/*
vector 是向量类型，它可以容纳许多类型的数据，如若干个整数，所以称其为容器。vector 是C++ STL的一个重要成员，使用它时需要包含头文件：
#include<vector>;
vector<int> a ;                                //声明一个int型向量a
vector<int> a(10) ;                            //声明一个初始大小为10的向量
vector<int> a(10, 1) ;                         //声明一个初始大小为10且初始值都为1的向量
vector<int> b(a) ;                             //声明并用向量a初始化向量b
vector<int> b(a.begin(), a.begin()+3) ;        //将a向量中从第0个到第2个(共3个)作为向量b的初始值
int b[7]={1,2,3,4,5,9,8};
        vector<int> a(b,b+7); //从数组中获得初值

vector对象的几个重要操作，举例说明如下：
（1）a.assign(b.begin(), b.begin()+3); //b为向量，将b的0~2个元素构成的向量赋给a
（2）a.assign(4,2); //是a只含4个元素，且每个元素为2
（3）a.back(); //返回a的最后一个元素
（4）a.front(); //返回a的第一个元素
（5）a[i]; //返回a的第i个元素，当且仅当a[i]存在2013-12-07
（6）a.clear(); //清空a中的元素
（7）a.empty(); //判断a是否为空，空则返回ture,不空则返回false
（8）a.pop_back(); //删除a向量的最后一个元素
（9）a.erase(a.begin()+1,a.begin()+3); //删除a中第1个（从第0个算起）到第2个元素，也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+         3（不包括它）
（10）a.push_back(5); //在a的最后一个向量后插入一个元素，其值为5
（11）a.insert(a.begin()+1,5); //在a的第1个元素（从第0个算起）的位置插入数值5，如a为1,2,3,4，插入元素后为1,5,2,3,4
（12）a.insert(a.begin()+1,3,5); //在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5
（13）a.insert(a.begin()+1,b+3,b+6); //b为数组，在a的第1个元素（从第0个算起）的位置插入b的第3个元素到第5个元素（不包括b+6），如b为1,2,3,4,5,9,8         ，插入元素后为1,4,5,9,2,3,4,5,9,8
（14）a.size(); //返回a中元素的个数；
（15）a.capacity(); //返回a在内存中总共可以容纳的元素个数
（16）a.resize(10); //将a的现有元素个数调至10个，多则删，少则补，其值随机
（17）a.resize(10,2); //将a的现有元素个数调至10个，多则删，少则补，其值为2
（18）a.reserve(100); //将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.这种操作只有在需要给a添加大量数据的时候才         显得有意义，因为这将避免内存多次容量扩充操作（当a的容量不足时电脑会自动扩容，当然这必然降低性能）
（19）a.swap(b); //b为向量，将a中的元素和b中的元素进行整体性交换
（20）a==b; //b为向量，向量的比较操作还有!=,>=,<=,>,<
几种重要的算法，使用时需要包含头文件：
#include<algorithm>
（1）sort(a.begin(),a.end()); //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素进行从小到大排列
（2）reverse(a.begin(),a.end()); //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，但不排列，如a中元素为1,3,2,4,倒置后为4,2,3,1
（3）copy(a.begin(),a.end(),b.begin()+1); //把a中的从a.begin()（包括它）到a.end()（不包括它）的元素复制到b中，从b.begin()+1的位置（包括它）开        始复制，覆盖掉原有元素
（4）find(a.begin(),a.end(),10); //在a中的从a.begin()（包括它）到a.end()（不包括它）的元素中查找10，若存在返回其在向量中的位置
*/
//1。排序祛重-2。三层for循环
vector<vector<int>> Tencent::threeSum(vector<int>& nums) {
    vector<vector<int>> answer = {};
    if (nums.size() < 3)return answer;
    sort(nums.begin(), nums.end());;//排序
    int num_size = nums.size();
    int sum;
    for (int i = 0; i < num_size - 2; i++) {
        sum = 0 - nums[i];
        for (int j = i + 1, k = num_size - 1; j < k;) {
//                printf("i=%d,j=%d,k=%d\n",i,j,k);
            if (nums[j] + nums[k] == sum) {
                answer.push_back({nums[i], nums[j++], nums[k--]});

                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;

            } else if (nums[j] + nums[k] < sum)
                j++;
            else
                k--;
        }
        while (i < num_size - 2 && nums[i + 1] == nums[i])
            i++;
    }
    return answer;
}
vector<vector<int>> Tencent::threeSum1(vector<int>& nums) {
    vector<vector<int>> answer = {};
    if (nums.size() < 3)return answer;
    sort(nums.begin(), nums.end());;//排序
    int num_size = nums.size();
    for (int i = 0; i < num_size - 2; ++i) {
        if (i != 0 && nums[i - 1] == nums[i]) {
            continue;
        }
        for (int j = i + 1; j < num_size - 1; ++j) {
            if (j != i + 1 && nums[j - 1] == nums[j]) {
                continue;
            }
            for (int k = j + 1; k < num_size; ++k) {
                if (k != j + 1 && nums[k - 1] == nums[k]) {
                    continue;
                }
                if (nums[i] + nums[j] + nums[k] == 0) {
                    answer.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
    }
    return answer;
}
//T7 最接近的三数之和
/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/
/*
 1。排序
 2。找到第一个比target大或者相等的位置（前三个为比taeget小的，当前位置到后二为比taeget大的）例：1，2，2，2，3---2--->1
1 2 2 3---2
    2 3---1
 3。找位置前三后三做对比，找差值最小的。
 */
int Tencent::threeSumClosest(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    int res = 0;
    bool first = true;
    for (int i = 0; i < nums.size(); i++) {
        int pa = i + 1;
        int pb = nums.size() - 1;
        while (pa < pb) {
            int sum = nums[i] + nums[pa] + nums[pb];
            if (first) {
                res = sum;
                first = false;
            } else if (abs(target - sum) < abs(target - res)) {
                res = sum;
            }
            if (res == target) {
                return res;
            }
            if (sum <= target) {
                pa++;
            } else {
                pb--;
            }
        }
    }
    return res;
}
//T8 有效的括号
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
 */
/*
c++栈的方法的基本用法：

    push(): 向栈内压入一个成员；
    pop(): 从栈顶弹出一个成员；
    empty(): 如果栈为空返回true，否则返回false；
    top(): 返回栈顶，但不删除成员；
    size(): 返回栈内元素的大小；
 */
/*
栈空则返回ture
 */
bool Tencent::isValid(string s) {
    if (s.length() % 2 == 1)
        return false;
    stack<int> stk;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk.push(s[i]);
        } else if ((stk.size() > 0 && stk.top() == '(' && s[i] == ')') ||
                   (stk.size() > 0 && stk.top() == '[' && s[i] == ']') ||
                   (stk.size() > 0 && stk.top() == '{' && s[i] == '}')) {
            stk.pop();
        } else
            return false;
    }
    return stk.empty();
}
//T9 删除排序数组中的重复项
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
int Tencent::removeDuplicates(vector<int>& nums) {
    if (nums.size() < 1)
        return 0;
    int nums_size = nums.size();
    int now = 0;
    for (int i = 1; i < nums_size; ++i) {
        if (nums[now] < nums[i]) {
            nums[now + 1] = nums[i];
            now++;
        }
    }
//        nums.erase(nums.begin()+now,nums.end());
    nums.resize(now + 1);
    return now + 1;
}
//T10 盛最多水的容器
/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
 */
int Tencent::maxArea1(vector<int>& height) {
    if (height.size() == 2)
        return min(height[0], height[1]);
    if (height.size() < 2)
        return 0;
    int max = 0;
    int height_size = height.size();
    for (int i = 0; i < height_size - 1.; ++i) {
        for (int j = i + 1; j < height_size; ++j) {
            int minInt = height[i] > height[j] ? height[j] : height[i];
            int now = minInt * (j - i);
            if (max < now)
                max = now;
        }
    }
    return max;
}
int Tencent::maxArea(vector<int>& height) {
    int max = 0;
    int height_size = height.size();
    int water = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
        int now = min(height[left], height[right]) * (right - left);
        if (max < now)
            max = now;
        if (height[left] > height[right])
            right--;
        else
            left++;
    }
    return max;
}
//T11 字符串相乘
/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"
说明：
    num1 和 num2 的长度小于110。
    num1 和 num2 只包含数字 0-9。
    num1 和 num2 均不以零开头，除非是数字 0 本身。
    不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 */
/*
1.实现乘法
2.去除前面'0'
*/
string Tencent::multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    if (m == 0 || n == 0) return 0;
    string res(m + n, '0');

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for (int i = 0; i < m; ++i) {
        int r = 0;
        for (int j = 0; j < n; ++j) {
            int tmp = (res[i + j] - '0') + (num1[i] - '0') * (num2[j] - '0') + r;
            res[i + j] = tmp % 10 + '0';
            r = tmp / 10;
        }
        res[i + n] += r;
    }

    reverse(res.begin(), res.end());

    size_t pos = res.find_first_not_of("0");
    if (pos != string::npos) {
        return res.substr(pos);
    }

    return "0";
}
//T12 反转字符串
/*
编写一个函数，其作用是将输入的字符串反转过来。

示例 1:
输入: "hello"
输出: "olleh"

示例 2:
输入: "A man, a plan, a canal: Panama"
输出: "amanaP :lanac a ,nalp a ,nam A"
 */
string Tencent::reverseString(string s) {
    static bool x = false;
    if (s.size() == 0)
        return "";
    int ss = s.size();
    for (int i = 0; i < s.size() / 2; ++i) {
        char x = s[i];
        s[i] = s[ss - 1 - i];
        s[ss - 1 - i] = x;
    }
    return s;
}
//T13 反转字符串中的单词 III
/*
反转字符串中的单词 III
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:
输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc"
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 */
string Tencent::reverseWords(string s) {
    int min = 0;
    int ss = s.size();
    for (int i = 0; i < ss;) {
        if (s[i + 1] == ' ' || i + 1 == ss) {
            for (int j = 0; j < (i - min + 1) / 2; ++j) {
                char x = s[min + j];
                s[min + j] = s[i - j];
                s[i - j] = x;
            }
            i += 2;
            min = i;
        } else
            i++;
    }
    return s;
}
//T14 除自身以外数组的乘积
/*
给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:
输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 */
vector<int> Tencent::productExceptSelf1(vector<int>& nums) {//超时
    int ns = nums.size();
    vector<int> answer(ns, 1);
    for (int i = 0; i < ns; ++i) {
        for (int j = 0; j < ns; ++j) {
            if (i != j) {
                answer[i] *= nums[j];
            }
        }
    }
    return answer;
}
vector<int> Tencent::productExceptSelf(vector<int>& nums) {
    int ns = nums.size();
    if (ns < 1)
        return {0};
    int max = 1;
    int zero = 0;
    for (int i = 0; i < ns; ++i) {
        if (nums[i] != 0)
            max *= nums[i];
        else
            zero++;
    }
    if (zero == ns)
        return vector<int>(ns, 0);
    for (int j = 0; j < ns; ++j) {
        if (nums[j] != 0) {
            if (!zero)
                nums[j] = max / nums[j];
            else
                nums[j] = 0;
        } else {
            if (zero == 1)
                nums[j] = max;
            else
                nums[j] = 0;
        }
    }
    return nums;
}
//T15 存在重复元素
/*
给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:
输入: [1,2,3,1]
输出: true
示例 2:
输入: [1,2,3,4]
输出: false
示例 3:
输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
 */
bool Tencent::containsDuplicate(vector<int>& nums) {
    int ns = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    if (nums.size() != ns)
        return true;
    return false;
}
//T16 螺旋矩阵
/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 */
vector<int> Tencent::spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.size() == 0)
        return vector<int>{};
    vector<int> answer;
    int x1 = 0, y1 = 0;
    int x2 = matrix.size() - 1;
    int y2 = matrix[0].size() - 1;
    int direction = 0;
    while (x1 <= x2 && y1 <= y2) {
        switch (direction) {
            case 0:
                for (int y = y1; y <= y2; y++)//上
                    answer.push_back(matrix[x1][y]);
                direction++;
                x1++;
                break;
            case 1:
                for (int x = x1; x <= x2; x++)//右
                    answer.push_back(matrix[x][y2]);
                direction++;
                y2--;
                break;
            case 2:
                for (int y = y2; y >= y1; --y)//下
                    answer.push_back(matrix[x2][y]);
                direction++;
                x2--;
                break;
            case 3:
                for (int x = x2; x >= x1; x--)//左
                    answer.push_back(matrix[x][y1]);
                direction = 0;
                y1++;
                break;
        }
    }
    return answer;
}
//T17 螺旋矩阵 II
/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 */
vector<vector<int>> Tencent::generateMatrix(int n) {
    if (n == 1)
        return {{n}};
    else if (n == 0)
        return {};
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int x1 = 0, x2 = n - 1;
    int y1 = 0, y2 = n - 1;
    int num = 1;
    int direction = 0;
    while (x1 <= x2 && y1 <= y2) {
        switch (direction) {
            case 0:
                for (int i = y1; i <= y2; ++i) {
                    answer[x1][i] = num;
                    num++;
                }
                direction++;
                x1++;
                break;
            case 1:
                for (int i = x1; i <= x2; ++i) {
                    answer[i][y2] = num;
                    num++;
                }
                direction++;
                y2--;
                break;
            case 2:
                for (int i = y2; i >= y1; --i) {
                    answer[x2][i] = num;
                    num++;
                }
                direction++;
                x2--;
                break;
            case 3:
                for (int i = x2; i >= x1; --i) {
                    answer[i][y1] = num;
                    num++;
                }
                direction = 0;
                y1++;
                break;
        }
    }
    return answer;
}
//T18 合并两个有序数组
/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:
    初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
    你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
输出: [1,2,2,3,5,6]
 */
void Tencent::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] < nums2[j]) {
            nums1[k] = nums2[j];
            --j;
        } else {
            nums1[k] = nums1[i];
            --i;
        }
        --k;
    }
    if (j >= 0) {
        while (k >= 0)
            nums1[k--] = nums2[j--];
    }
}




