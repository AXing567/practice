//线段问题（前缀和）
/*
有N条线段，已知每条线段的起点和终点（50000以内），然后有M个询问，每次询问一个点（50000以内），求这个点在多少条线段上出现过？
输入格式
第一行N线段条数接下来N行，每行两个数，线段的起点和终点第N+2行一个数M询问个数接下来M行，每行一个点
输出格式
对于每个询问，求答案
样例输入
3
2 5
4 6
0 7
4
2
4
7
6
样例输出
2
3
1
2
*/
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 50002

int arr[MAX],ans[MAX];
int main()
{
    int x, l, r, m,a,maxindex=0;
    cin >> x;

    for (int i = 1; i <= x; i++)//打标记
    {
        cin >> l >> r;
        arr[l]++;
        arr[r + 1]--;
        maxindex=max(r,maxindex);//线段右的段
    }

    for (int i = 1; i <= maxindex; i++)//前缀和
    {
        arr[i] = arr[i] + arr[i - 1];
    }

    cin >> m;

    for (int i = 1; i <= m; i++)//某个点出现了多少次，依次存入ans中
    {
        cin>>a;
        ans[i]=arr[a];
    }
    int i=1;
    while(ans[i])
    {
        cout<<ans[i]<<endl;
        i++;
    }


    return 0;
}
