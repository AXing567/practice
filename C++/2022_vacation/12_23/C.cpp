/*
跳石头 [题库题号 P2808]
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
using namespace std;
typedef long long ll;

const int MAX = 5e4 + 10;
int a[MAX];
int l , n , m;

bool find(int x)
{   
    int moved = 0 , last = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(a[i] - last < x )
        {
            moved++;
        }
        else
        {
            last = a[i];
        }
    }
    if(moved > m || a[n + 1] - last < x)
        return false;
    else
        return true;
}


int main()
{
    quicken;
    cin >> l >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] ;
    }    
    a[n + 1] = l;
    int left = 1 , right = l , ans = 0;
    while(left <= right)
    {
        int mid = ((left - right) >> 1) + right;
        if(find(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}

/*
25 5 3
2
11
14
17 
21

*/