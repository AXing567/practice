//https://www.luogu.com.cn/problem/P1102

#include <iostream>
#include <algorithm>
using namespace std;

int a[200005];

int main()
{
    int n , c;
    cin >> n >> c;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    long long ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        ans += upper_bound(a + 1 , a + n + 1 , a[i] + c) - lower_bound(a + 1 , a + n + 1 , a[i] + c);
    }
    cout << ans << endl;
    return 0;
}