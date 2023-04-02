//https://www.luogu.com.cn/problem/P2670
#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
typedef long long ll;
using namespace std;

const int N = 105;
bool a[N][N] ;

int main()
{
    jiasu
    ll n , m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j ++)
        {   
            char ch;
            cin >> ch;
            if (ch == '*')
                a[i][j] = true;
        }

    for (int i = 1 ; i <= n ; i ++)
    {
         for (int j = 1 ; j <= m ; j ++)
        {
            if (a[i][j])
                cout << '*';
            else
                cout << a[i + 1][j] + a[i + 1][j - 1] + a[i][j - 1] + a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j + 1] + a[i + 1][j + 1];
        }
        cout << endl;
    }
       

            

    return 0;
}
