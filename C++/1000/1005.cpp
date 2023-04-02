/*
题目描述
请问长度分别为a、b、c的三条边能否构成一个三角形？
输入格式
输入三个用空格隔开的整数a、b、c
输出格式
如果能构成三角形，输出Yes，否则输出No
样例输入
1 2 2
样例输出
Yes
提示
数据范围： 1<=a,b,c<=2147483647
提示：
1.三角形两边之和大于第三边、两边之差小于第三边。
2.继续练习使用if语句和逻辑关系运算符。
3.带符号32位整数(C/C++)int能够表示的最大整数为2147483647，请使用无符号32位整数unsigned int、或者64位整数long long完成本题。
*/
#include<iostream>
#include <math.h>
using namespace std;

int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    if(a+b>c&&a+c>b&&b+c>a&&abs(a-b)<c&&abs(a-c)<b&&abs(b-c)<a)
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;

    return 0;
}

