/*
题目描述
Given are three sequences of length N each: A=(A1,A2,…,AN), B=(B1,B2,…,BN), and C=(C1,C2,…,CN), consisting of integers between 1 and N (inclusive).

How many pairs (i,j) of integers between 1 and N (inclusive) satisfy Ai=BCj​​?
输入格式
Constraints
1≤N≤105
1≤Ai,Bi,Ci≤N
All values in input are integers.

Input is given from Standard Input in the following format:

N
A1​ A2​ … AN
B1​ B2​ … BN
C1​ C2​ … CN
输出格式
Print the number of pairs (i,j) such that Ai=BCj​​.
样例输入
Sample Input 1
3
1 2 2
3 1 2
2 3 2

Sample Input 2
4
1 1 1 1
1 1 1 1
1 2 3 4

Sample Input 3
3
2 3 3
1 3 3
1 1 1
样例输出
Sample Output 1
4
Sample Output 2
16
Sample Output 3
0
提示
Sample 1:
Four pairs satisfy the condition: (1, 1), (1, 3), (2, 2), (3, 2)(1,1)
*/


#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], b[N], c[N], cnt[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        cnt[b[c[i]]]++;
    for (int i = 1; i <= n; i++)
        ans += cnt[a[i]];
    cout<<ans<<'\n';
}