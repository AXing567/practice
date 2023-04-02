/*
题目描述
We have 4 cards with an integer 1 written on it, 4 cards with 2, …, 4 cards with N, for a total of 4N cards.

Takahashi shuffled these cards, removed one of them, and gave you a pile of the remaining 4N−1 cards. The i-th card (1≤i≤4N−1) of the pile has an integer Ai  written on it.

Find the integer written on the card removed by Takahashi.
输入格式
Constraints
1≤N≤105
1≤Ai≤N , (1≤i≤4N−1)
For each k , (1≤k≤N), there are at most 4 indices ii such that Ai=k.
All values in input are integers.

Input is given from Standard Input in the following format:

N
A1​ A2 … A4N−1​
输出格式
Print the answer.
样例输入
Sample Input 1
3
1 3 2 3 3 2 2 1 1 1 2
Sample Input 2
1
1 1 1
Sample Input 3
4
3 2 1 1 2 4 4 4 4 3 1 3 2 1 3
样例输出
Sample Output 1
3
Sample Output 2
1
Sample Output 3
2
*/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];

int main(){
    int n,x;
    cin>>n;
    for(int i=1 ; i<=n*4-1 ; i++){
        cin>>x;
        a[x]++;       
    }

    for(int i=1 ; i<=n ; i++){
        if(a[i]!=4)
        {
            cout<<i<<'\n';
            return 0;
        }
    }
    

    return 0;
}