#include <iostream> //前缀和应用之“找到AC"
using namespace std;

int a[100005], l[100005], r[100005], sum[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;

    string s;
    char str[n];
    cin >> n >> q;
    cin >> s;
    for (int i = 1; i <= q; i++) //接收p次的   左右范围
    {
        cin >> l[i] >> r[i];
    }
    for (int i = 0; i < n; i++)
    { //给AC做标记
        if (s[i] == 'A' && s[i + 1] == 'C')
        {
            a[i + 2]++;
        }
    }
    for (int i = 1; i <= s.length(); i++) //求前缀和
    {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cout << sum[r[i]] - sum[l[i]] << '\n';
    }

    return 0;
}