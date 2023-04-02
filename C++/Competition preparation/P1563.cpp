// https://www.luogu.com.cn/problem/P1563
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> pf; // profession
    vector<bool> face;

    int t;    // 用于压入容器的临时变量
    string s; // 用于压入容器的临时变量
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        face.push_back(t);
        cin >> s;
        pf.push_back(s);
    }

    int a, b;  // 用于计算的临时变量；
    int p = 0; // 指针变量p
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (face[p] == 0) // 朝向里面，当是左时指针向上，当是右时指针向下
        {
            if (a == 0) // 指左边
            {
                p -= b;
                p %= n; // 涉及负数取余运算
            }
            else // 指右边
            {
                p += b;
                p %= n;
            }
        }
        else // 朝向外边,当指左时指针向下，当指右时指针向上
        {
            if (a == 0) // 指向左边
            {
                p += b;
                p %= n;
            }
            else // 指向右边
            {
                p -= b;
                p %= n;
            }
        }
    }
    p += n;
    p %= n;
    cout << pf[p] << endl;
    return 0;
}

/*
7 3
0 singer
0 reader
0 mengbier
1 thinker
1 archer
0 writer
1 mogician

10 10
1 C
0 r
0 P
1 d
1 e
1 m
1 t
1 y
1 u
0 V
*/