#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
typedef long long ll;
using namespace std;
const int N = 1e5 + 10 , INF = 0x7EEEEEEE;
inline int read()//快速读入
{
    int x, f = 1;
    char c;
    while (!((c = getchar()) >= '0' && c <= '9'))
        if (c == '-')
            f = -1;
    x = c - '0';
    while ((c = getchar()) >= '0' && c <= '9')
        (x *= 10) += c - '0';
    return x * f;
}
inline void write(int ans)//快速写入
{
    if (ans < 0)
    {
        putchar('-');
        write(-ans);
    }
    else
    {
        if (ans / 10)
            write(ans / 10);
        putchar(ans % 10 + '0');
    }
}


int main()
{
    quicken;
    int a = read();
    write(a);

    return 0;
}