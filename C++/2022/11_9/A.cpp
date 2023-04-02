#include <iostream> //经典01背包问题模板
#define endl '\n'
typedef long long ll;
using namespace std;

int w[505], v[505];
int dp[500001]; 

ll count;
int sum;

int main()
{

    int m, n; // m容量,n数量
    cin >> n >> m;

    dp[0] = 0;
    for (int i = 1; i <= m; i++)
        dp[i] = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i < n; i++)
        for (int j = m; j >= w[i]; j--)
            if (dp[j - w[i]] != -1)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
    if (dp[m] == -1)
        cout << 0 << endl;
    else
        cout << dp[m] << endl;
    return 0;
}