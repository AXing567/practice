/*
题目描述
若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。规定：x和y是亲戚，y和z是亲戚，那么x和z也是亲戚。如果x,y是亲戚，那么x的亲戚都是y的亲戚，y的亲戚也都是x的亲戚。
输入格式
第一行：三个整数n,m,p，（n<=5000,m<=5000,p<=5000），分别表示有n个人，m个亲戚关系，询问p对亲戚关系。以下m行：每行两个数Mi，Mj，1<=Mi，Mj<=N，表示Ai和Bi具有亲戚关系。接下来p行：每行两个数Pi，Pj，询问Pi和Pj是否具有亲戚关系。
输出格式
P行，每行一个’Yes’或’No’。表示第i个询问的答案为“具有”或“不具有”亲戚关系。
样例输入
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6
样例输出
Yes
Yes
No
*/
#include <iostream>//图论
using namespace std;
#define endl '\n'
//const int N= 1e9 +10;//1000000010
const int N = 1e5 + 10;
int fa[N];

int find(int x)
{
    if(fa[x] == x)
        return x;
    // return find(fa[x]);
    return fa[x]=find(fa[x]);
}

void merge(int x,int y)
{
    x = find (x);
    y = find (y);
    if (x!=y)
        fa[y]=x;
}

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        merge(a,b);
    }
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b))
            cout<<"Yes"<<endl;
        else  
            cout<<"No"<<endl;
    }
    return 0;
}