#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define jiasu ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

bool m, a, i, n;

int main()
{
    string s;
    cin >> s;
    for (int k = 0; k < s.length(); k++)
    {
        if (s[k] == 'm')
            m = true;
        if (s[k] == 'a')
            a = true;
        if (s[k] == 'i')
            i = true;
        if (s[k] == 'n')
            n = true;

    }
    if (m && a && i && n && s.length() == 4)
        cout << "main" << endl;
    else
        cout << "I don't know" << endl;
    return 0;
}
