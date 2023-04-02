#include <iostream>//	单词 [题库题号 P2854]
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            cout<<"YES";
            return 0;
        }

    }
    cout<<"NO";
    return 0;
}