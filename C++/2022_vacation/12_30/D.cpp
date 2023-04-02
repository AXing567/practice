#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) 
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
int Fa[MAX] , count_s[MAX];

void init()
{
    for(int i = 1 ; i < MAX ; i++)
    {
        Fa[i] = i;
    }
}

int find(int x)
{
    if(Fa[x] == x)
        return x;
    else
        return Fa[x] = find(Fa[x]);
}

void merge(int x , int y)
{
    x = find(x);
    y = find(y);
    if(x != y)
    {
        Fa[x] = y;
    }
}

int main()
{
    quicken;
    init();
    int n , m , x ;
    int ans1 = 0 , ans2 = 0 ;//能分辨出ans双袜子 , ans2种袜子是自己的

    cin >> n >> m >> x;
    for(int i = 1 ; i <= m ; i++)
    {
        int temporary;
        cin >> temporary;
        merge(0 , temporary);
    }
    while(x--)
    {
        int first , a;
        cin >> a >> first;
        count_s[first]++;
        for(int i = 1 ; i < a ; i++)
        {
            int b;
            cin >> b; 
            merge(first , b);
            count_s[b]++;
        }
    }
    for(int i = 1 ; i < MAX ; i++)
    {
        if(find(0) == find(i)) 
        {
            ans2++;
            ans1 += count_s[i];
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}
/*
Sample input
5 2 2
1 2
5 5 6 7 8 9
3 5 1 2

Sample output
8 7

*/