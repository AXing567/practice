/*
题目描述
提示：1.了解现行历法下公元1583~3199年间，闰年的判断方法：年份是400的倍数，或者年份是4的倍数但不是100的倍数。
2.学习使用if语句和逻辑关系运算符。
输入一个年份，输出它是否是闰年。年份在公元1583~3199年之间。
输入格式
一个整数，表示年份
输出格式
如果是闰年输出Yes，否则输出No
样例输入
2012
样例输出
Yes
*/

#include <iostream>
using namespace std;

int main()
{
    int year;
    cin>>year;
    if(year%400==0 || (year%4==0 && year%100 != 0))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}