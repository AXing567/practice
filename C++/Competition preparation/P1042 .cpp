// https://www.luogu.com.cn/problem/P1042
#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'

using namespace std;

void Question(char *s, int n , int f)//n:不包含E的长度，即WLE为2。
{
    int hua = 0, rival = 0;
    for (int i = 0; i < n; i++)
    {
        s[i] == 'W' ? hua++ : rival++;
        if ((hua >= f || rival >= f) && abs(hua - rival) >= 2)
        {
            cout << hua << ':' << rival << endl;
            hua = 0;
            rival = 0;
        }
        // cout << s[i];
    }
    cout << hua << ':' << rival << endl ;
}
int main()
{
    char s[62530];
    char t;
    int n = 0;
    while (true)
    {
        cin >> t;
        if (t == 'E')
            break;
        s[n++] = t;
    }
    Question(s, n , 11);
    cout << endl;
    Question(s, n , 21);
    return 0;
}
// WWWWWWWWWWLWWWWWWWWWWLE