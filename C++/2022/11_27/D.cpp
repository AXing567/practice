#include <iostream> 
#include <cstring>
#include <algorithm>
#define endl '\n'
#define jiasu ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    jiasu long long n, ans;
    cin >> n;
    while (n--)
    {
        int a, b;
        ans = 0;
        cin >> a >> b;
        while (a != 0 && b != 0)
        {
            if (a < b)
            {
                int t;
                t = a;
                a = b;
                b = t;
            }
            ans += a / b;
            a = a - (a / b) * b;
        }
        cout << ans << endl;
    }
    return 0;
}