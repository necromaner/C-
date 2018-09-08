//1.9 编写程序，使用while循环将50到100的整数相加。
using std::cout;
using std::endl;
int sum = 0, val = 50;
int main()
{
    while (val <= 100) {
        sum = sum + val;
        val = val + 1;
    }
    cout << "the sum of 50 to 100 is " << sum << endl;
    return 0;

}