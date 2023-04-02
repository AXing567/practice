#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin .tie(0) , cout.tie(0)
using namespace std;

const int MAX = 1e3 + 10;
int star[MAX][MAX];

int main()
{
    quicken;
    int n , m , p;
    cin >> n >> m >> p;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> star[i][j];
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            star[i][j] += star[i - 1][j] + star[i][j - 1] - star[i - 1][j - 1] ;
            // cout << star[i][j] << ',';
        }
        // cout << endl;
    }
    while(p--)
    {
        int x1 , x2 , y1 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2)
        {
            swap(x1 , x2);
        }
        if(y1 > y2)
        {
            swap(y1 , y2);
        }
        cout << star[x2][y2] - star[x2][y1 - 1] - star[x1 - 1][y2] + star[x1 - 1][y1 - 1] << endl;
    }



    return 0;
}