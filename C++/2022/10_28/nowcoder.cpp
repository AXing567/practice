/*
链接：https://ac.nowcoder.com/acm/contest/44339/D?&headNav=acm
来源：牛客网
*/

#include <iostream>
using namespace std;
const int N = 1e5 + 10;

long long a[N];
int n, m;

bool check(long long x)
{

    int res = 1;        //记录已经分了多少块
    long long empt = 0; //已经被分出来的块的   和
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > x) //假定答案不符，返回假。（当本个点大于了“假定答案”后，就代表“把一个点分成一个块，x也不是最大值尽量小的值”）
        {
            return false;
        }
        if (empt + a[i] > x)
        { //如果当前分出的块加下一个值大于了假定答案，那么就要开启下一个块，并
            res++;
            empt = a[i];
        }
        else
        {
            empt += a[i];
        }
    }
    if (res > m)
        return false;
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // sum+=a[i]/m
    long long l = 0, r = 1e15, ans = r;

    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}