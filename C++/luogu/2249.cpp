//https://www.luogu.com.cn/problem/P2249
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define endl '\n'
typedef long long ll;


const int N = 1e6 + 10;

int a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    for (int i = 1 ; i <= m ; i++)
    {
        int b ;
        cin >> b;
        int temp = lower_bound(a + 1 , a + n + 1 , b) - a;
        if (a[temp] == b)
        {
            cout << temp << ' ';
        }else
            cout << -1 << ' ';
    }
    return 0;
}