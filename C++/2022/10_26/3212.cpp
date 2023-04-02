/*
题目描述
Alice家装修完成之后，邀请Bob来家里作客玩游戏。
Alice有n个膜方，这些膜方有两种颜色，一种是红色的，一种是蓝色的，她把n个膜方竖直地堆起来。膜方消消乐是这样玩的，当两个上下相邻的膜方颜色不同时，Bob可以拿走这两个膜方，并且堆在它们上面的膜方会落在堆在它们下面的膜方上。
Bob的游戏目标是尽可能地拿走更多的膜方。随着时间不断地-1s，Bob越来越慌。
Bob把这堆膜方处理成了一个长度为n字符串S告诉了你。如果S中的第i个字符是0，那么第i个膜方是红色的；如果是1，那么这个膜方是蓝色的。
Bob希望你能帮助他计算出他最多可以拿走多少膜方。
即便如此，这也只是个膜方罢了，这大抵是我的幻觉罢，我愈发愈觉得奇怪。那倘若真是如此，这个膜方未必会-1s吧————Bob时常这么以为
输入格式
第一行包含一个字符串S，S中的每个字符都只能是0 或 1. 字符串S长度不超过10^5.
输出格式
输出一个整数，代表你最多能拿走多少个膜方数量。
样例输入
1010
样例输出
4
提示
膜方从上到下，颜色为蓝红蓝红。
*/

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
const int N = 1e5 + 10;

char s[N];
int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int ans = 0;
    std::stack<char> stk;

    for (int i = 1; i <= n; i++)
    {
        if (!(stk.empty()) && s[i] == '0')
        {
            if (stk.top() == '1')
            {
                ans += 2;
                stk.pop();
            }
            else
                stk.push(s[i]);
        }
        else if (!(stk.empty()) && s[i] == '1')
        {
            if(stk.top()=='0')
            {
                ans+=2;
                stk.pop();
            }else stk.push(s[i]);
        }else stk.push(s[i]);
    }

    printf("%d",ans);

    return 0;
}
/*
解题思路：此代码用的是栈操作，考验逻辑的题，
在每次判断的时候都应该看是否“栈空”栈空就“压栈”，反之就可以进行比较了
进行比较的时候就比较“栈顶”和新比较字符是否“匹配”
匹配就“出栈”并让答案加2，不匹配就“压栈”
重复以上步骤，直至没有新增，输出ans
*/

/*
#include <iostream>
#include <cstring>
using namespace std;
const int N=1e5+10;
char s[N];
int main(){
    scanf("%s",s);
    int n=strlen(s);
    int red=0,blue=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0')
            red++;
        else
            blue++;
    }
    printf("%d",2*min(red,blue));

}
*/

/*
解题思路2：
统计1和0的个数，将最小的乘2输出

因为没有什么特殊情况，消掉一对，后面的数据会自然追上空白的地方，
他们之间始终没有第三种数据，0或者1始终会消除掉，最后只剩下多的哪一种
*/