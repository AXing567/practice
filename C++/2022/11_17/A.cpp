#include <iostream>
using namespace std;

int dp[20005]; //容量为i时dp[i]的值：价值
int w[] = {0, 150, 200, 350};
int c[] = {0, 150, 200, 350}; //第i件物品的重量w[i]、价值c[i]

int main()
{
    int t, p;
    cin >> p;
    while (p)
    {
        cin >> t;
        for (int i = 1; i <= 3; i++) // m容量,n数量
            for (int j = w[i]; j <= t; j++)
                dp[j] = max(dp[j], dp[j - w[i]] + c[i]); //经典01背包问题动态转移方程

        cout << t - dp[t] << endl;
        p--;
    }

    return 0;
}
