#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

const int MAXN = 1e5;
const int MAXV = 1e5;
int dp[MAXN], w[MAXV], c[MAXV], x[MAXV];
int bag, n;

void knapsackProblem01() // 01背包
{
    cin >> bag >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> c[i];
    for (int i = 0; i < n; i++)
        for (int j = bag; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
    cout << dp[bag] << endl;
    /*
    sample input
    10 4
    2 1
    3 3
    4 5
    7 9
    sample output
    12
    */
}

void knapsackProblemFull() //完全背包
{
    cin >> bag >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> c[i];
    for (int i = 0; i < n; i++)
        for (int j = w[i]; j <= bag; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
    cout << dp[bag] << endl;
    /*
    sample input
    10 4
    2 1
    3 3
    4 5
    7 9
    sample output
    12
    */
}

void knapsackProblemMultiple() //多重背包
{
    cin >> bag >> n;
    int tempw[MAXV], tempc[MAXV];
    int k = -1;
    for (int i = 0; i < n; i++)
        cin >> tempw[i] >> tempc[i] >> x[i];
    
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 1 ; j <= x[i] ; j <<= 1)
        {
            k++;
            w[k] = tempw[i] * j;
            c[k] = tempc[i] * j;
            x[i] -= j;
        }
        if (x[i] != 0)
        {
            k++;
            w[k] = tempw[i] * x[i];
            c[k] = tempc[i] * x[i];
        }
    }
    n = k;//注意这里给到了n
    for (int i = 0 ; i <= n ; i++)
        for (int j = bag ; j >= w[i] ; j--)
        {
            dp[j] = max(dp[j] , dp[j - w[i]] + c[i]);
        }
    cout << dp[bag] << endl;
    // cin >> bag >> n;//朴素算法
    // for (int i = 0 ; i < n ; i ++)
    //     cin >> w[i] >> c[i] >> x[i];
    // for (int i = 0 ; i < n ; i ++)
    //     for (int j = bag ; j >= 0 ; j--)
    //         for (int k = 0 ; k <= x[i] && j >= k * w[i] ; k ++)
    //             dp[j] = max (dp[j] , dp[j - k * w[i]] + k * c[i]);
    // cout << dp[bag] << endl;
/*
sample input1
1000 5
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1
sample output1
1040



sample input
10 4
3 2 2
4 3 2
2 2 1
5 3 4
sample output
8
    */
}

int main()
{
    // knapsackProblem01();
    // knapsackProblemFull();
    knapsackProblemMultiple();

    return 0;
}
/*#include <iostream>//混合背包
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Thing
{
    bool kind;
    int w , c;
};
const int N = 1010;
int dp[N];
vector<Thing> things;

int main()
{
    int n , bag;
    cin >> n >> bag;
    for (int i = 1 ; i <= n ; i ++)
    {
        int w , c , s;
        cin >> w >> c >> s;
        if (s < 0)  things.push_back({false , w , c});
        else if (s == 0)    things.push_back({true , w , c});
        else
        {
             for (int j = 1 ; j <= s ; j <<= 1)
             {
                 things.push_back({false , w * j , c * j});
                 s -= j;
             }
             if (s > 0) things.push_back({false , w * s , c * s});
        }
    }
    for (auto i : things)
    {
        if (i.kind)
        {
            for (int j = i.w ; j <= bag ; j++)  dp[j] = max(dp[j] , dp[j - i.w] + i.c);
        }
            
        else{
            for (int j = bag ; j >= i.w ; j--)  dp[j] = max(dp[j] , dp[j - i.w] + i.c);
        }
            
    }
    
    cout << dp[bag] << endl;
    
    return 0;
}
*/

/*#include <iostream>//分组背包
#include <cstring>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

const int N = 105;
int dp[N] , w[N] , c[N];
int n , bag;

int main()
{
    cin >> n >> bag;
    for (int i = 1 ; i <= n ; i++)
    {
        int s;
        cin >> s;
        for (int j = 1 ; j <= s ; j++)  cin >> w[j] >> c[j];
        for (int j = bag ; j >= 0 ; j--)
            for (int k = 1 ; k <= s; k ++)
                if (j >= w[k])
                    dp[j] = max(dp[j] , dp[j - w[k]] + c[k]);
    }
    cout << dp[bag];

    return 0;
}*/