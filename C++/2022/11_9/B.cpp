
#include <iostream> //经典01背包问题模板
#define endl '\n'
typedef long long ll;
using namespace std;

int a[1005];
int dp[50005];       //容量为i时dp[i]的值：价值
// int w[505], c[505]; //第i件物品的重量w[i]、价值c[i]
ll count;
int sum;

int main()
{
    int m, n; // m容量,n数量
    cin >> n ;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < n; i++)
        for (int j = sum / 2; j >= a[i]; j--)
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
    
    cout << sum - dp[sum / 2] - dp[sum / 2] << endl;

    return 0;
}