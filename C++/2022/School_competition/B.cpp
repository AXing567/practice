#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define jiasu ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
int x[N];
ll ans;

int main()
{
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            x[i] = i + 1;
        }
    }

    for (int i = 0; i < a.length(); i++)
    {
        if (x[i] + 1 == x[i + 1] && a[i] != a[i + 1])
        {
            ans++;
            i++;
            continue;
        }
        if (x[i] > 0)
            ans++;
    }
    cout << ans << endl;
    // for (int i = 0; i < a.length(); i++)
    //     cout << x[i] << "  ";
    return 0;
}
