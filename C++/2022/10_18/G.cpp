#include <iostream>//拓展
using namespace std;

int main()
{

    string str;
    long long k,a;
    cin >> str >> k;
    
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '1')
        {
            a=i;
            break;
        }
        a=str.length()-1;
    }

    if(k>=a+1)
        cout<<str[a]<<'\n';
    else
        cout<<'1';


    return 0;
}