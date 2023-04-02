#include <iostream>
using namespace std;
#define MAX 100005

int a[MAX];

int main()
{
    int n, m, k,ans=0;
    int ai, bi, xi;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> ai >> bi >> xi;
        a[ai] += xi;
        a[bi+1] -= xi;
    }

    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        if(a[i]>k){
            ans++;
        }
    }
    cout<<ans;

    return 0;
}