/*
题目描述
Takahashi and Aoki are playing a game.

First, Takahashi chooses an integer between A and B (inclusive) and tells it to Aoki.
Next, Aoki chooses an integer between C and D (inclusive).
If the sum of these two integers is a prime, then Aoki wins; otherwise, Takahashi wins.
When the two players play optimally, which player will win?
输入格式
1≤A≤B≤100
1≤C≤D≤100
All values in input are integers.

Input is given from Standard Input in the following format:
A B C D
输出格式
If Takahashi wins when the two players play optimally, print Takahashi; if Aoki wins, print Aoki.
样例输入
Sample Input 1
2 3 3 4
Sample Input 2
1 100 50 60
样例输出
Sample Output 1
Aoki
Sample Output 2
Takahashi
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
bool isprime[N];

void prime(int x)
{
    for (int i = 1; i <= x; i++)
        isprime[i] = true;
    isprime[0] = isprime[1] = false;
    int end = sqrt(x);
    for (int i = 2; i <= end; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= x; j += i)
            {
                isprime[j] = false;
            }
        }
    }
}

int main()
{

    int a, b, c, d;
    bool ok = 1;
    prime(1000);
    cin >> a >> b >> c >> d;

    for ( int i=a ; i<=b ; i++ )
    {
        ok = 1;
        for (int j = c ; j <= d ; j++ )
        {
            if(isprime[i+j]){
                ok = 0;
                break;
            }
        }
        if (ok) break;
    }
    puts(ok?"Takahashi":"Aoki");

    return 0;
}