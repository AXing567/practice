#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
using namespace std;
typedef long long ll;

const int MAX = 5e4 + 10;
int t[MAX];
int main()
{
    quicken;
    ll s = 0;
    int n , m , fast , slow;
    cin >> n;
    while(n--)
    {
        cin >> fast >> slow;
        t[fast]++;
        t[slow + 1]--;
    }
    for (int i = 1 ; i <= MAX ; i++)
    {
        t[i] += t[i - 1];
    }
    cin >> m;
    while(m--)
    {
        int x;
        cin >> x;
        cout << t[x] << endl;
    }

    return 0;
}