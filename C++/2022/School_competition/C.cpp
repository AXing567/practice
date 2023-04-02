#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define jiasu ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;

ll ans;

int main()
{
    ll t , x;
    cin >> t;
    while(t--)
    {
        cin >> x;
        ans = 0;
        for (ll i = 1 ; i <= 1e9 ; i = i * 10 + 1)
        {
            for (ll j = 1 ; j <= 9 ; j ++)
            {
                if (i * j <= x)
                {
                    // cout << i * j << endl;
                    ans++;
                }
                    // ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
