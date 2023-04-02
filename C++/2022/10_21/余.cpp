/*好像是1060
Unit5, Section B
嗯,小明同学在小的时候喜欢爬楼梯,不为什么,只是觉得 这种阶梯状的建筑非常好玩等到他长大了,
可以一次跨上一级,也可以跨两级所以,他想知道, 有多少种不同的上到楼梯顶端的方案
输入格式
一行,一个整数,表示楼梯的高度（小于15）
输出格式
一行,一个整数,表示方案数。
样例输入
3
样例输出
3
*/
#include <iostream>
using namespace std;

//const int N= 1e9 +10;//1000000010
int a[16];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=15;i++){
        a[i]=a[i-1]+a[i-2];
    }
    int n;
    cin>>n;
    cout<<a[n];

    
    return 0;
}