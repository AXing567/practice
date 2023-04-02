#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#define endl '\n'
using namespace std;

const int N = 1010;
int n, m, s[N][N];

int query(int lx, int ly, int rx, int ry)
{
    return s[rx][ry] - s[rx][ly - 1] - s[lx - 1][ry] + s[lx - 1][ly - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            while (i + ans <= n && j + ans <= m && query(i, j, i + ans, j + ans) == (ans + 1) * (ans + 1))
            {
                ans++;
            }
    cout << ans << endl;
    return 0;

}
