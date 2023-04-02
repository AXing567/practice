/*2808
这项比赛将在一条笔直的河道中进行,河道中分布着一些巨大岩石。组委会已经选择好了两块岩石作为比赛起点和终点。在起点和终点之间,有 N 块岩石(不含起点和终 点的岩石)。在比赛过程中,选手们将从起点出发,每一步跳向相邻的岩石,直至到达 终点。
为了提高比赛难度,组委会计划移走一些岩石,使得选手们在比赛过程中的最短跳 跃距离尽可能长。由于预算限制,组委会至多从起点和终点之间移走 M 块岩石(不能 移走起点和终点的岩石)。
输入格式
输入文件名为 stone.in。
输入文件第一行包含三个整数 L,N,M,分别表示起点到终点的距离,起点和终 点之间的岩石数,以及组委会至多移走的岩石数。
接下来 N 行,每行一个整数,第 i 行的整数 Di(0 < Di < L)表示第 i 块岩石与 起点的距离。这些岩石按与起点距离从小到大的顺序给出,且不会有两个岩石出现在同 一个位置
输出格式
输出文件名为 stone.out。 输出文件只包含一个整数,即最短跳跃距离的最大值。
样例输入
25 5 2
2
11
14
17
21
样例输出
4
提示
输入输出样例 1
说明：将与起点距离为 2 和 14 的两个岩石移走后,最短的跳跃距离为 4(从与起点距离 17 的岩石跳到距离 21 的岩石,或者从距离 21 的岩石跳到终点)。
另：对于 20%的数据,0 ≤ M ≤ N ≤ 10。 对于50%的数据,0 ≤ M ≤ N ≤ 100。
对于 100%的数据,0 ≤ M ≤ N ≤ 50,000；1 ≤ L ≤ 1,000,000,000。
来源
Noip2015 D2T1
*/
#include <iostream>
using namespace std;
typedef long long ll;
// const int N= 1e9 +10;//1000000010
int s, n, m;

int num[1001000];

bool check(int x)
{
    int res = 0;
    int empt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (num[i] - empt < x)
        {
            res++;
        }
        else
        {
            empt = num[i];
        }
    }
    if (res > m)
    {
        return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    n++;
    num[n] = s;
    ll l = 0, r = s, ans = l;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;

    return 0;
}