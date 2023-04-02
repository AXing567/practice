#include <iostream>
#include <map>
#define jiasu ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    jiasu;
    int n, t, ans, sum = 0, mx = 0, typ = 0, ove = 0;
    map<int, int> mp1, mp2;
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        mp1[t]++;
    }
    for (map<int, int>::iterator it = mp1.begin(); it != mp1.end(); it++)
        mp2[it->second]++;
    for (map<int, int>::reverse_iterator it = mp2.rbegin(); it != mp2.rend(); it++)
    {
        t = it->first;
        sum += t * (it->second);
        ove += (mx - t) * typ;
        ans = min(ans, (n - sum) + ove);
        typ += (it->second);
        mx = t;
    }
    cout << ans << endl;
    return 0;
}
