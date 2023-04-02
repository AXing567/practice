/*
题目描述
     春春是一名道路工程师，负责铺设一条长度为 n 的道路。
     铺设道路的主要工作是填平下陷的地表。整段道路可以看作是 n 块首尾相连的区 域，一开始，第 i 块区域下陷的深度为 di 。
     春春每天可以选择一段连续区间 [L,R] ，填充这段区间中的每块区域，让其下陷深 度减少 1。在选择区间时，需要保证，区间内的每块区域在填充前下陷深度均不为 0 。
     春春希望你能帮他设计一种方案，可以在最短的时间内将整段道路的下陷深度都变 为 0 。 
输入格式
输入包含两行，第一行包含一个整数 n，表示道路的长度。
第二行包含 n 个整数，相邻两数间用一个空格隔开，第 i 个整数为 di 。 

输出格式
输出仅包含一个整数，即最少需要多少天才能完成任务。
样例输入
6
4 3 2 5 3 5
样例输出
9
提示
对于 30% 的数据，1 ≤ 𝑛 ≤ 10 ；
对于 70% 的数据，1 ≤ 𝑛 ≤ 1000 ；
对于 100% 的数据，1 ≤ 𝑛 ≤ 100000 ，0 ≤ di ≤ 10000 。 
*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n,t=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a>t){
            ans+=(a-t);
            t=a;
        }else{
            t = a;
        }    
    }

    cout<<ans<<'\n';
    return 0;
}