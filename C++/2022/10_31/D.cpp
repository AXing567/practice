/*
题目描述
如果自然数n和n+2都是素数，那么我们就称n和n+2是孪生素数。现给出一个数字x，请降序输出不大于x的所有孪生素数
输入格式
输入包含一个整数x。（5<= x <=20000000）
输出格式
若干行,每行两个数,为一对孪生素数
样例输入
10
样例输出
7 5
5 3
*/

#include <iostream> // 线性筛    例题
#include <cmath>
#include <cstring>
using namespace std;
const int N = 2*1e7 + 10;

bool isprime[N];

void getprime(int x) //找到1-x范围内的所有质数，不是质数就将  全局数组isprime[i]   置false
{
    memset(isprime,true,sizeof(isprime));//将数组isprime里的内容全置为true
    isprime[0] = isprime[1] = false;//0和1不是质数，所以置false
    int end = sqrt(x);              //这里到下面的for循环结束，的功能是将2-x之间所有的非质数标记出来（用isprime数组）
    for (int i = 2; i <= end; i++)
    {
        if (isprime[i])
        {

            for (int j = i * i; j <= x; j += i)
                isprime[j] = false;
            
        }
    }
}

int main()
{

    int n;
    cin >> n;
    getprime(n);
    for (int i = n; i >= 3; i--)
    {
        if (isprime[i] && isprime[i - 2])
        {
            cout << i << ' ' << i - 2 << '\n';
        }
    }

    return 0;
}

//新增知识点：线性筛、memset()函数(在cstring头文件中)