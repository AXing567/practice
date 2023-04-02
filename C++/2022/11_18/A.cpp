#include <iostream>
using namespace std;

int main()
{
    long long x, y, z;
    cin >> x >> y >> z;

    if ((x == y && x >= z) || (x == z && x >= y) || (y == z && y >= x))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}