#include <iostream>//制造AC
using namespace std;

const int N= 1e5 +10;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans=0;
    string str;
    
    cin>>str;
    for(int i=0;i<str.length();i++){
        a[i+1]=str[i];
    }
    for(int i=1;i<=str.length();i++){
        if(a[i]==a[i+1]&&a[i]!='?'){
            a[i+1]='?';
            ans++;
            i++;
        }
    }
    cout<<ans;


    
    return 0;
}