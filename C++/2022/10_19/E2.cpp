#include <iostream>
#include <cstring>
using namespace std;

const int N=1010;
long long  sum[N][N],a[N][N];
int main(){
    int T;
    cin>>T;

    while(T--)
    {
        int n,p;
        cin>>n>>p;
        for(int i=1,x,y;i<=n;i++){//将给定的n组数据传递给数组a的（x,y）上这一点中存入此当前坐标所形成的矩形面积
            cin>>x>>y;
            a[x][y]+=x*y;
        }
        for(int i=1;i<=1000;i++){//求出二维数组的前缀和
            for(int j=1;j<=1000;j++){
                sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            }
        }
        while (p--)
        {
            int ws,hs,wb,hb;
            cin>>hs>>ws>>hb>>wb;
            cout<<sum[hs-1][wb-1]-sum[hb][wb-1]-sum[hs-1][ws]+sum[hb][ws];
        }
        
    //sum[hb-1][wb-1]-sum[hb-1][ws]-sum[hs][wb-1]+sum[hs][ws]
        
        

    }

    return 0;
}