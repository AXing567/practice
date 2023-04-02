#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) 
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
int Fa[MAX];
int ans ;

void init()
{
    for (int i = 1 ; i <= MAX ; i++)
    {
        Fa[i] = i;
    }
}

int find(int x)
{
    if(Fa[x] == x)
    {
        return x;
    }
    else
    {
        Fa[x] = find(Fa[x]);
        return Fa[x];
    }
}

void merge(int a , int b)
{
    if(find(a) != find(b))
    {
        Fa[find(a)] = find(b);
        ans--;
    }

}




int main()
{
    while(true)
    {
        init();
        int n , m ;
        cin >> n >> m;
        if(n == 0)  break;
        ans = n - 1;
        for (int i = 1 ; i <= m ; i++)
        {
            int a , b ;
            cin >> a >> b;
            merge(a , b);
        }
        cout << ans << endl;
    }
    
    

    return 0;
}
