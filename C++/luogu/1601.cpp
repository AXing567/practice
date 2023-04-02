//https://www.luogu.com.cn/problem/P1601
#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define jiasu ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;

const int N = 505;

int find(string a, string b, int *c)
{
    int x[N] = {0}, y[N] = {0}, lena = a.length(), lenb = b.length();
    for (int i = N - lena; i <= N - 1; i++)
        x[i] = a[i - N + lena] - '0';
    for (int i = N - lenb; i <= N - 1; i++)
        y[i] = b[i - N + lenb] - '0';
    int n = max(lena, lenb);
    int temp = 0;
    int i;
    for (i = N - 1; i >= N - n; i--)
    {
        c[i] = x[i] + y[i] + temp;
        temp = c[i] / 10;
        c[i] %= 10;
        // cout << c[i];
    }

    if (temp)
    {
        c[i] = temp;
        return i;
    }
    else
        return ++i;
}

int main()
{
    jiasu
    string a,
    b;
    cin >> a >> b;
    int c[N] = {0};
    int n = find(a, b, c);
    // cout << endl << n << endl;
    for (int i = n; i < N; i++)
        cout << c[i] ;
    return 0;
}