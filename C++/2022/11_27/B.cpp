#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;

int main()
{
    int a, b , c;
    cin >> a >> b >> c;
    cout << min(min(min (a + b + c, 2 * a + 2* b),2 * (a + c)),2 * (b + c)) << endl;

    return 0;
}