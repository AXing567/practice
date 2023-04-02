#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
int TT, n, q;
long long sum[N][N], a[N][N];
int main()
{
    scanf("%d", &TT);
    while (TT--)
    {
        memset(a, 0, sizeof a);
        scanf("%d%d", &n, &q);

        for (int i = 1, x, y; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            a[x][y] += x * y;
        }
        for (int i = 1; i <= 1000; i++)
        {
            for (int j = 1; j <= 1000; j++)
            {
                sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        while (q--)
        {
            int ws, wb, hs, hb;
            scanf("%d%d%d%d", &hs, &ws, &hb, &wb);
            printf("%lld\n", sum[hb - 1][wb - 1] - sum[hs][wb - 1] - sum[hb - 1][ws] + sum[hs][ws]);
        }
    }

    return 0;
}