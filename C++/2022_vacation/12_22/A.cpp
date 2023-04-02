#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define quicken ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
using namespace std;
typedef long long ll;

int main()
{
    quicken;
    ll n , a , b , c , sum = 0;
    ll A , B , C;
    ll AB , BC , AC , ABC;
    cin >> n >> a >> b >> c;
    A = n / a;
    B = n / b;
    C = n / c;
    AB = n / (a * b);
    BC = n / (b * c);
    AC = n / (a * c);
    ABC = n / (a * b * c);
    cout << A + B + C - 2 * (AB + AC + BC ) + 4 * ABC << endl;
    return 0;
}

