#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
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

    }

}




int main()
{
    init();
    int n , MAX = 0;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        int p , q;
        cin >> p >> q;
        merge(p , q);
    }
    for(int i = 1 ; i <= 100 ; i++)
    {   
        int t = 0;
        for (int j = i ; j <= 100 ; j++)
        {
            if(find(i) == find(j))
            {
                t++;
            }
        }
        MAX = max(t , MAX);
    }
    cout << MAX << endl;
    return 0;
}
/*
4
1 4
2 3
1 5
1 6
*/