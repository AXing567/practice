/*
题目描述
输入键盘上一个字母，输出该字母左上方和右上方分别是什么键。以下为键盘上键的名称和位置：
1 2 3 4 5 6 7 8 9 0 -
 Q W E R T Y U I O P
  A S D F G H J K L
   Z X C V B N M ,
输入格式
输入包含一个大写字母。
输出格式
输出该大写字母按键左上方、右上方分别是什么键。两个字符之间用一个空格隔开。
样例输入
T
样例输出
5 6
提示
提示：1.练习使用switch(C/C++)、case(Pascal)语句来代替大量的if语句。2.本题所指键盘为标准美式键盘。

*/

#include <iostream>
using namespace std;

int main(){
    char t;
    cin>>t;
    switch(t){
        case 'Q': cout<<1<<' '<<2<<endl;break;
        case 'W': cout<<2<<' '<<3<<endl;break;
        case 'E': cout<<3<<' '<<4<<endl;break;
        case 'R': cout<<4<<' '<<5<<endl;break;
        case 'T': cout<<5<<' '<<6<<endl;break;
        case 'Y': cout<<6<<' '<<7<<endl;break;
        case 'U': cout<<7<<' '<<8<<endl;break;
        case 'I': cout<<8<<' '<<9<<endl;break;
        case 'O': cout<<9<<' '<<0<<endl;break;
        case 'P': cout<<0<<' '<<'-'<<endl;break;
        case 'A': cout<<'Q'<<' '<<'W'<<endl;break;
        case 'S': cout<<'W'<<' '<<'E'<<endl;break;
        case 'D': cout<<'E'<<' '<<'R'<<endl;break;
        case 'F': cout<<'R'<<' '<<'T'<<endl;break;
        case 'G': cout<<'T'<<' '<<'Y'<<endl;break;
        case 'H': cout<<'Y'<<' '<<'U'<<endl;break;
        case 'J': cout<<'U'<<' '<<'I'<<endl;break;
        case 'K': cout<<'I'<<' '<<'O'<<endl;break;
        case 'L': cout<<'O'<<' '<<'P'<<endl;break;
        case 'Z': cout<<'A'<<' '<<'S'<<endl;break;
        case 'X': cout<<'S'<<' '<<'D'<<endl;break;
        case 'C': cout<<'D'<<' '<<'F'<<endl;break;
        case 'V': cout<<'F'<<' '<<'G'<<endl;break;
        case 'B': cout<<'G'<<' '<<'H'<<endl;break;
        case 'N': cout<<'H'<<' '<<'J'<<endl;break;
        case 'M': cout<<'J'<<' '<<'K'<<endl;break;
        case ',': cout<<'K'<<' '<<'L'<<endl;break;
    }

    return 0;
}