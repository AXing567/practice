/*
题目描述
Unit4, Section B
对于不等式1+1/2+1/3+……+1/i>n很显然,当i足够大时,不等式成立。现在,请你计算出这个最小的i。
输入格式
输入一行,一个整数,表示n。(0<n<20)
输出格式
输出一行,一个整数,表示i。
样例输入
2
样例输出
4
*/

#include <iostream>
using namespace std;
int main()
{
    double sum = 0;
    double n;
    cin >> n;
    for (int i = 1;; i++)
    {
        sum += 1.0 / i; //关键点：小心1/i始终是0，从而导致死循环的问题
        if (sum > n)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}