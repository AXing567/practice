/*

题目描述
计算一个整数的约数个数
输入格式
输入一个整数 n
输出格式
输出共一行，表示n的约数个数
样例输入
10
样例输出
4
提示
数据范围： 1<=n<2^31提示：1.在本机测试极限数据是否可以在规定的时限内出解2.掌握估计简单程序的时间复杂度3.建议使用函数来编写

*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n, ans = 0;
    cin >> n;

    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == sqrt(n))
                ans += 1;
            else
                ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}