#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define jiasu ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

const int N = 50005;
int a[N];

bool cmp(int a , int b)
{
    return a > b;
}

int main()
{
    jiasu 
    int n , k;
    long long ans = 0;
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i];
    sort(a + 1 , a + n + 1 , cmp);
    // int group = ( n + k ) / k;
    for (int i = 1 ; i <= n ; i+=k)
    {
        int m = 0;
        for (int j = i ; j <= i+k ; j++)
        {
            m = max(a[j],m);
        }
        ans +=( m - 1 ) * 2;
        // cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}