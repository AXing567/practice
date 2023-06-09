/*
题目描述
计算机竞赛小组的神牛V神终于结束了万恶的高考，然而作为班长的他还不能闲下来，班主任老t给了他一个艰巨的任务：帮同学找出最合理的大学填报方案。可是v神太忙了，身后还有一群小姑娘等着和他约会，于是他想到了同为计算机竞赛小组的你，请你帮他完成这个艰巨的任务。
根据n位学生的估分情况，分别给每位学生推荐一所学校，要求学校的预计分数线和学生的估分相差最小（可高可低，毕竟是估分嘛），这个最小值为不满意度。求所有学生不满意度和的最小值。
输入格式
共三行，第一行读入两个整数m,n。m表示学校数，n表示学生数。第二行共有m个数，表示m个学校的预计录取分数。第三行有n个数，表示n个学生的估分成绩。
输出格式
一个数，即最小的不满度之和。
样例输入
4 3
513 598 567 689
500 600 550
样例输出
32
提示
数据范围：对于30%的数据，m，n<=1000;对于100%的数据，n,m<=100,000。
来源
大连24中翠神原创
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e5 + 10;
int m, n;
int school[N], score[N], res, INF = 0x3f3f3f3f;

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> school[i];
    for (int i = 1; i <= n; i++)
        cin >> score[i];

    school[m + 1] = INF;

    sort(school + 1, school + m + 1);

    for (int i = 1; i <= n; i++)
    {
        int x = score[i];
        int l = 1, r = m + 1;

        while (l < r)
        {
            int mid = l + r >> 1;

            if (school[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if (l == 1)
            res += abs(x - school[l]);
        else
            res += min(abs(x - school[l]), abs(x - school[l - 1]));
    }
    cout << res;

    return 0;
}