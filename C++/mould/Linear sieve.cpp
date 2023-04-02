#include <iostream>//半线性筛--求质数
#include <cmath>
#include <cstring>
using namespace std;

const int N = 1e5;
bool isprime[N];

void getprime(int x)//求[2,x]内所有的质数
{
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    int end = sqrt(x);
    for (int i = 2; i <= end; i++)
    {
        if (isprime[i])
        {

            for (int j = i * i; j <= x; j += i)
                isprime[j] = false;
        }
    }
}

int main()
{
    getprime(500);

    for (int i = 1; i <= 500; i++)
    {
        if (isprime[i])

            cout << i << '\n';

    }
    return 0;
}