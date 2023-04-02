//天使与恶魔
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
using namespace std;
typedef long long ll;

const int MAX = 2e3 + 10;
int Fa[MAX];

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

void merge(int a , int b)
{
    a = find(a) , b = find(b);
    if(a != b)
    {
        Fa[a] = b;
    }
}

int main()
{
    init();
    quicken;
    // test();
    int n , m ;
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i ++)
    {
        int x , y;
        char z;
        cin >> x >> y >> z;
        if(z == 'T')
        {
            if(find(x) != find(y + n))//既然x和y同为天使或恶魔，就不能出现一个为天使一个为恶魔的现象
            {
                merge(x , y);
                merge(x + n , y + n);
            }
            else
            {
                cout << i << endl;
            }
        }
        else
        {
            if(find(x) !=find(y))
            {
                merge(x , y + n);
                merge(x + n , y);
            }
            else
            {
                cout << i << endl;
            }
        }
    }
    return 0;
}
/*
Sample Input


Sample Output

*/