#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
using namespace std;
typedef long long ll;

const int MAX = 2e3 + 10;
int c[MAX][MAX] , ans[MAX][MAX];

void init(int k)
{
    for(int i = 0 ; i < MAX ; i++)//求得杨辉三角
    {   
        c[i][0] = c[i][i] = 1 % k;//杨辉三角或组合数的边界条件，当取的数为0时即Cnm的n为0时，Cnm为1 ， 当n=m时，Cnm=1
        for (int j = 1 ; j < i ; j++)
        {
            c[i][j] =(c[i - 1][j - 1] % k + c[i - 1][j] % k) % k;//杨辉三角的公式，根据题意对k取余，避免数值过大
        }
    }   
    
    for (int i = 0 ; i < MAX ; i++)
    {
        for (int j = 0 ; j < MAX ; j++)
        {
            if(c[i][j] == 0 && j <= i)//是k的倍数还是j<=i就是符合要求的，变成0或1的形式，方便后续统计个数
                c[i][j] = 1;
            else
                c[i][j] = 0;
        }
    }
    // ans[0][0] = c[0][0];
    // for (int i = 1 ; i < MAX ; i++ )
    // {
    //     ans[0][i] = ans[0][i - 1] + c[0][i];
    // }
    for (int i= 1 ; i < MAX ; i++)
    {
        // ans[i][0] = ans[i - 1][0] + c[i][0];
        for (int j = 1 ; j < MAX ; j++)
        {
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + c[i][j];
            //统计符合条件的个数，后续以O(1)的时间复杂度查找对应的值
        }
    }
}

int main()
{
    quicken;
    int t , k;
    cin >> t >> k;
    init(k);
    while(t--)
    {
        int a , b ;
        cin >> a >> b;
        cout << ans[a][b] << endl;
    }
    return 0;
}
