#include <iostream>
using namespace std;
const int N = 1010;
const int MOD = 998244353;
int TT, n, m, f[N][N];
// i代表位置 j代表上限
int main()
{
    for (int i = 1; i < N; i++)
    {
        f[1][i] = i;
        for (int j = 2; j < N; j++)
        {
            f[j][i] = (f[j - 1][i] + f[j][i - 1]) % MOD;
        }
    }
    scanf("%d", &TT);
    while (TT--)
    {
        scanf("%d%d", &n, &m);
        printf("%d\n", f[n][m]);
    }
    return 0;
}