#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
int Fa[N];
int count_s[N];//某个结点作为父节点时它的节点个数

void init() //初始化
{
    for (int i = 0; i < N; i++)
    {
        Fa[i] = i;
        // count_s[i] = 1;
    }
}

int find(int x) //压缩路径式查找结点x 的父节点
{
    if (Fa[x] == x)
    {
        return x;
    }
    else
    {
        Fa[x] = find(Fa[x]);
        return Fa[x];
    }
}

void merge(int a , int b)//带权值的合并
{
    a = find(a) , b = find(b);
    if(a != b)
    {
        Fa[a] = b;
        // count_s[b] += count_s[a];
        // count_s[a] = 0;
    }
}

void test()
{
    init();
    int t , a , b , k;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        merge(a , b);
    }
    cin >> k ;
    while(k--)
    {
        cin >> a;
        cout << find(a) << endl;
    }
}

int main()
{
    quicken;
    test();
    return 0;
}
/*
Sample Input
5
1 2
2 3
3 4 
4 5
5 6
6
1
2
3
4
5
6

Sample Output
6
6
6
6
6
6
*/