#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
using namespace std;
typedef long long ll;

const int L = 1e4 + 10;
int a[L];

int main()
{
    quicken;
    ll s = 0;
    int l , m;
    cin >> l >> m;
    while(m--)
    {
        int b , e;
        cin >> b >> e;
        a[b]--;
        a[e + 1]++;
    }
    for(int i = 1 ; i <= l ; i++)
    {
        a[i] = a[i] + a[i - 1];
        s += a[i] == 0 ? 1 : 0;
    }
    cout << s + (a[0] == 0 ? 1 : 0)<< endl;
    return 0;
}