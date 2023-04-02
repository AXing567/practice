#include <iostream>//最大公约数
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b,a%b);
}

int main()
{   
    cout<<gcd(6,18)<<endl;
    return 0;
}