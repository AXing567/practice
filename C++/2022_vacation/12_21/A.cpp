#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
ll sum[N];

int main()
{
    quicken;
    int n , q; 
    cin >> n >> q;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> sum[i];
        sum[i] = sum[i] + sum[i - 1];
    }//O(n)

    // for (int i = 1 ; i <= n ; i++)
    // {
    //     sum[i] = sum[i - 1] + sum[i];
    // }

    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << sum[y] - sum[x - 1] << endl;
    }//O(q)

    return 0;
}