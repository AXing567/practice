#include <iostream>//容斥原理，题目：数星星

using namespace std;

int a[1005][1005], sum[1005][1005];
int main()
{
    int n, m, p;
    int x1, y1, x2, y2;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    { //接收行列数据
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

     for (int i = 1; i <= n; i++)
    { 
        for (int j = 1; j <= m; j++)
        {
            
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }


    while (p--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
        {
            int t = x1;
            x1 = x2;
            x2 = t;
        }
        if (y1 > y2)
        {

            int t = y1;
            y1 = y2;
            y2 = t;
        }
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]<<endl;
    }
}
