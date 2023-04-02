//车厢 [题库题号 P3403]
#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
using namespace std;

const int MAX = 105;
int a[MAX];
int n , max_ , min_;
int max_l , min_l;

int main()
{
    quicken;
    cin >> n ;
    cin >> a[1];
    max_ = min_ = a[1];
    max_l = min_l = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        cin >> a[i];
        if(max_ < a[i])
        {
            max_ = a[i];
            max_l = i;
        }
        if(min_ > a[i])
        {
            min_ = a[i];
            min_l = i;
        }
    }
    cout << max_l << ',' << min_l << endl;
    int next ;
    cout << min(max_l , n - max_l + 1) + min(min_l , n - min_l + 1) << endl;



    return 0;
}

/*
sample input 1
5
2 3 1 4 5
sample output 1

sample input 2
5
2 1 3 4 5

sample input 3
11
10 8 6 2 1 3 11 4 5 7 9
sample output 3
7
*/