/*
题目描述
判断一个数是否为质数，质数指在一个大于1的自然数中，除了1和此整数自身外，不能被其他自然数整除的数。
输入格式
输入一个整数 n
输出格式
如果n是质数，输出"Yes"，否则输出"No"（不含引号）
样例输入
2
样例输出
Yes
提示
数据范围： 1<=n<2^31
本题是主要让大家掌握循环语句
提示：1.Time Limit Exceeded表示程序执行超过了最大限制，没有通过题目2.估计你的程序能否在程序规定的时间内出结果3.尽可能的多测试一些大数据和特殊数据

*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if(n==2)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if(n==1){
        cout<<"No"<<endl;
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}