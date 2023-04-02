#include <iostream>//求最大公约数


using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << gcd(a, b)<<endl;
    }

    return 0;
}

//求最大公约数的模板