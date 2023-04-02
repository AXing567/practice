#include <iostream> //开心的金明，背包问题，拆分成要和不要两个变量、前面加上结束判定条件整体类似现在
using namespace std;//经典背包问题
int N, m;
// const int N= 1e9 +10;//1000000010
int v[30], w[30];
int find(int money, int n)
{
    if (n == m)
    {
        if(money>=v[n]){
            return w[n];
        }else{
            return 0;
        }
    }
    int t1 = find(money, n + 1);        //不要这件物品后最大的价值
    if(money<v[n])
    {
        return t1;
    }

    int t2 = find(money - v[n], n + 1)+w[n]; //要这件物品后最大的价值
    return max(t2,t1);
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> m;
    for (int i = 1; i <= m; i++)
    {
        int t;
        cin >> v[i] >> t;
        w[i]=t*v[i];
    }
    cout << find(N, 1) << '\n';

    return 0;
}