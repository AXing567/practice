#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
using namespace std;
typedef long long ll;

const int MAX = 1e6 + 10;
int t[MAX];
int main()
{
    quicken;
    ll s = 0;
    int l , m , n;
    cin >> l >> m >> n;
    while(m--)
    {
        int a , b ;
        cin >> a >> b ;
        t[a]--;
        t[b + 1]++;
    }
    for(int i = 1 ; i <= l ; i++)
    {
        t[i] += t[i - 1];
    }
    for(int i = 1 ; i <= l ; i++)
    {
        t[i] = t[i] < 0 ? 0 : 1;
    }
    t[0] = t[0] < 0 ? 0 : 1;
    for(int i = 1 ; i <= l ; i++)
    {
        t[i] += t[i - 1];
    }
    while(n--)
    {
        int a , b;
        cin >> a >> b;
        cout << t[b] - t[a - 1 < 0 ? MAX - 1 : a - 1] << endl;
    }
    
    

/*
7 2 1
2 3
3 4
0 7
*/



    return 0;
}