#include <iostream>
#include <algorithm>
using namespace std;
int age[100000];
int copy1[100000];
bool cmp(int a, int b)
{
    return a < b;
}
int main()
{
    int n, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> age[i];
        copy1[i] = age[i];
    }

    sort(age, age + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (copy1[i] != age[i])
        {
            sum++;
        }
    }

    cout << sum;
}