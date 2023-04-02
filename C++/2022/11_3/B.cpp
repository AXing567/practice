/*
题目描述
dota是一款非常流行的著名游戏，Moe-ing最近也迷上了dota。
dota中决定游戏的往往是你的装备（当然技术也重要- -），而装备都是要金钱买的，金钱怎么得到呢，杀死敌方小兵就有钱得，杀死小兵得到的钱也是随机的。
当小兵的血量为0，或者更低时，该小兵就会死亡。
Moe-ing有个习惯，每次开始攻击小兵就一定要杀死他（怪习惯）。
Moe-ing现在有一个难题：
已知有小兵的数量n，每个小兵都有对应的血量，和杀死小兵所得的金钱
Moe-ing每次攻击能造成的伤害m（固定的），Moe-ing想要知道他在k次攻击之后最多能得到多少钱。
输入格式
第一行3个正整数n,m,k。分别表示有n个敌方小兵，Moe-ing每次攻击造成m点伤害和Moe-ing可以攻击k次。
第二行n个正整数 第i个数字表示第i个小兵的血量；
第三行n个正整数 第i个数字表示杀死第i个小兵可以得到的钱。
1≤n≤100
0≤m≤10000
0≤k≤20
输出格式
输出仅一个数字 表示最多可以获得的金钱
最后输出保证小于maxlongint
样例输入
4 50 3
8 20 99 101
2 50 20 1000
样例输出
1000
*/
#include <iostream>//经典01背包问题模板
#include <cmath>
using namespace std;

long long dp[105];
int w[105],v[105];//物品的重量、价值
long long hp[105],money[105];

int main()
{
    long long m,n,k;//m容量,n数量
    cin>>n>>m>>k;
    if (m == 0 )
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>hp[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>money[i];
    }
    for(int i=1 ;i<=n;i++)
    {
        v[i]=money[i];

        w[i]=hp[i]/m;
        if(hp[i]%m != 0)
            w[i]+=1;
    }




    for(int i =1 ; i <= n;i++)
        for(int j=k; j >= 1; j--)
            if(j >= w[i])
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            
    cout<<dp[k]<<endl;
  

    return 0;
}