/*
	会做馅饼的人 [题库题号 P2844]
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
typedef long long ll;
using namespace std;

const int MAX = 1e4 + 10;
const double Pi = acos(-1.0);
int n , m , maxv = 0;
int r[MAX];
// int temporary = 1;

bool find(int x)
{
    int share = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        share += Pi * r[i] * r[i] / x ;
        
    }
    // cout << temporary++ << ',' << share << ',' << x << endl;    
    if(share < m)
        return false;
    else
        return true;
}

int main()
{
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> r[i];
        maxv = r[i] > maxv ? r[i] : maxv ;
    }
    m++;
    int left = 0 , right = Pi * maxv * maxv , ans = -1;
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
3 1
4 3 3
*/