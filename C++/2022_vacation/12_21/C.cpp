#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
int t[MAX];
int main()
{
    quicken;
    ll s = 0;
    int n , m , k;
    cin >> n >> m >> k;
    while(m--)
    {
        int a , b , c;
        cin >> a >> b >> c;
        t[a] += c;
        t[b + 1] -= c;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        t[i] += t[i - 1];
        s += t[i] > k ? 1 : 0;
    }
    cout << s << endl;
    return 0;
}