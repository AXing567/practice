#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;




int main()
{
    std::stack<char>stk;
    string s;
    cin>>s;
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(!stk.empty() && s[i] == ')')
        {
            if(stk.top() == '(')
                stk.pop();
            else
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
        else if(!stk.empty() && s[i] == ']')
        {
            if(stk.top() == '[')
                stk.pop();
            else
            {
                cout<<"No"<<endl;
                return 0;
            }

        }else if(!stk.empty() && s[i] == '}')
        {
            if(stk.top() == '{')
                stk.pop();
            else
            {
                cout<<"No"<<endl;
                return 0;
            }

        }else stk.push(s[i]);
    }
    
    if(stk.empty())
        cout<<"Yes"<<endl;
    else    
        cout<<"No"<<endl;
    return 0;
}