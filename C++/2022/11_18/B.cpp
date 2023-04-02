#include <iostream>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    double n;
    cin >> n;

    if (n <= 100)
    {
        for (int i = 1; i <= 1000; i++)
        {
            if (0.1 * i == n)
            {
                cout << i << endl;
            }
        }
    }
    else if (n <= 900)
    {
        for (int i = 1; i <= 4000; i++)
        {
            if (0.2 * i == n - 100)
            {
                cout << i+1000 << endl;
            }
        }
    }else
    {
        for (int i = 5000; i <= 100000; i++)
        {
            if(0.25 * (i - 5000) == n - 900)
                cout << i << endl;
        }
    }

    
    return 0;
}