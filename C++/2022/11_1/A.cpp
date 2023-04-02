/*
题目描述
啊~啊~~啊~~~啊~~~~先吼几声吧~~~~~.
输入两个数n和q，分别表示n个正整数和q次查找
每次查找一个数字x，输出有多少数比x小，有多少个数比x大.
输入格式
第一行输入 n和q(整数)
第二行输入 n个正整数
第三行输入 q个正整数
输出格式
q行 每行两个整数
为小于、大于的数
样例输入
10 2
2 8 3 4 1 9 2 7 4 6
5 1
样例输出
6 4
0 9
提示
比5小的有1、2、2、3、4、4
比5大的有6、7、8、9
数据范围：
1≤n≤10^5
1≤q≤10^5
1≤x≤10^9
来源
原创

*/
#include <iostream>//二分查找
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, q, x;
int a[N];

int findBig(int x)//查找第一个大于x的下标，答案等于n-x+1
{
    int l = 1, r = n + 1;

    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] > x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int findLeft(int x)
{
    int l = 1, r = n + 1;

    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[n + 1] = 1e9 + 1;
    sort(a + 1, a + n + 1);

    while (q--)
    {
        cin >> x;
        int smallpos = findLeft(x) - 1;
        int bigpos = n - findBig(x) + 1;
        cout << smallpos<< ' ' <<bigpos<< '\n';
    }

    return 0;
}

