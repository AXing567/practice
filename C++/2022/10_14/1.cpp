//校门外的树pro（前缀和）
#include <iostream>
using namespace std;
#define MAX 10002

int arr[MAX];
int main()
{
    int l, m, m1, m2, count = 0;
    cin >> l >> m;
    l++;
    for (int i = 1; i <= m; i++)
    {
        cin >> m1 >> m2;
        m1++;
        m2++;
        arr[m1]--;
        arr[m2 + 1]++;
    }
    count = l;
    for (int i = 1; i <= l; i++)
    {
        arr[i] = arr[i] + arr[i - 1];
        if (arr[i] < 0)
        {

            count--;
        }
    }
    cout << count << '\n';
    return 0;
}

/*#include <iostream> //校门外的树
using namespace std;
#define MAX 10001
int arr[MAX]; //默认值为0
int main()
{
    int n, l, m1, m2, sum = 0;
    cin >> l >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m1 >> m2;
        for (; m1 <= m2; m1++)
        {
            arr[m1] = 1;
        }
    }
    for (int i = 0; i <= l; i++)
    {
        if (arr[i] == 1)
        {
            sum++;
        }
    }
    cout << (l + 1 - sum) << '\n';
}*/