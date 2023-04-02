/*
题目描述
输入两个自然数，输出他们相乘后数的位数
输入格式
输入两个自然数 a,b
输出格式
输出共一行，输出他们相乘后的位数
样例输入
123 500
样例输出
5
提示
数据范围： 1<=a,b<=2^64
提示：1.尝试使用数学函数2.本题有很多做法，但这里建议您使用“log”,因为它最简单
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long double a, b;
    cin >> a >> b;
    if (a == 1 || b == 1)//a、b其中一个为1
    {
        if (a * b == 1)//a、b都是1的情况
        {
            cout << 1<<endl;
            return 0;
        }
        else
        {
            cout << (int)(log10(a * b)) +1<< endl;
            return 0;
        }
    }

    cout << (int)(log10(a) + log10(b))+1 << endl;

    return 0;
}

//log10()可以理解为看一个数后面有多少个0


// 1*1     log10(1)==0


//long long 表示数据范围为-2^63到2^63-1
//本题的范围是2^64，没有规定是否是整数
//long double: 12 byte = 96 bit范围： 1.18973e+4932 ~ 3.3621e-4932

//反复出错原因，数据范围、数据类型确定不到位，边界数据测试不到位，应考虑数据为最小情况，算法不正确。
//不应使用ceil，当数据本身就是整数的时候，向上取整失效