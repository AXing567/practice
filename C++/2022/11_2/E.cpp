/*
题目描述
Given an integer X between −1018 and 1018 (inclusive), print ⌊X10⌋.
Notes
For a real number x, ⌊x⌋ denotes "the maximum integer not exceeding x". For example, we have ⌊4.7⌋=4, ⌊−2.4⌋=−3, and ⌊5⌋=5. (For more details, please refer to the description in the Sample Input and Output.)
输入格式
Input is given from Standard Input in the following format:
X

Constraints
−1018≤X≤1018
All values in input are integers.
输出格式
Print ⌊X10⌋. Note that it should be output as an integer.
样例输入
Sample Input 1
47
Sample Input 2
-24
Sample Input 3
50
样例输出
Sample Output 1
4
Sample Output 2
-3
Sample Output 3
5
*/
#include <iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    if(n<0)
        cout<<(n-9)/10<<'\n';
    else   
        cout<<n/10<<'\n';
    return 0;
}