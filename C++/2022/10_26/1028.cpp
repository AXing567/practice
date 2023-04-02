/*
题目描述
给一段仅含有'('、')'、'['、']'、'{'、'}'的序列，判断其是否合法（这段序列能否分成若干对对应的括号、并且每对括号之间也是一段合法的括号序列）。
例如：()[{}]是一段合法的括号序列。而：([)]则是一段不合法的括号序列。序列长度不超过10000。
输入格式
一行一个括号序列。
输出格式
合法输出Yes，否则输出No。
样例输入
(([()]{})())[]
样例输出
Yes
*/

#include <iostream>
#include <stack> //pop()弹出，top()栈顶，empty()栈空为1反之为0，push()压栈
#include <cstring>
const int N = 1e5 + 10;
char s[N];
int main()
{
    scanf("%s", s + 1);    //从s[1]接收字符串
    int n = strlen(s + 1); //头文件 <cstring> 里的函数。
    std::stack<char> stk;  //定义字符型栈stk，头文件stack
    int ans = 1;           //判定过程中，如果有一个括号不符合，那么整个串都不会符合，所以，用ans变量在结尾的时候判定

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == ')')
        {
            if (stk.empty() || stk.top() != '(')
            {
                ans = 0;
                break;
            }
            stk.pop(); //弹出
        }
        else if (s[i] == ']')
        {
            if (stk.empty() || stk.top() != '[')
            {
                ans = 0;
                break;
            }
            stk.pop(); //弹出
        }
        else if (s[i] == '}')
        {
            if (stk.empty() || stk.top() != '{')
            {
                ans = 0;
                break;
            }
            stk.pop(); //弹出
        }
        else
            stk.push(s[i]);
    }
    if (ans && stk.empty())
        printf("Yes");
    else
        printf("No");

    return 0;
}