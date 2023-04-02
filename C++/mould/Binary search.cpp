#include <iostream>//二分查找----边界查找
#include <cstring>
using namespace std;

int a[] = {0, 1, 2, 2, 2, 3, 3, 3, 4, 4,  5,  6,  8,  9,  9, 10};//被查找数组
int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};//辅助对比元素下标的数组
int n = sizeof(a)/4;

int lower(int x)//查找第一个大于等于x的元素的下标
{               //如果查找最后一个小于x的元素的下标只需要在此基础上，将返回值变量改为 l 即可
    int l = -1, r = n;//细节：查找区间为：(l,r)     如果是[l,r]的话很有可能在最开始的时候l或者r指向的区域就不正确了
    while (l + 1 != r)
    {
        int mid = ((l - r) >> 1) + r;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid;
    }
    return r;
}

int upper(int x)//查找第一个大于x的元素的下标
{               //如果要查找最后一个大于等于x的元素的下标只需要在此基础上，将返回值改为 l 即可
    int l = -1 , r = n;
    while (l + 1 != r)
    {
        int mid = ((l - r) >> 1) + 1;
        if (a[mid] > x)
            r = mid;
        else 
            l = mid;
    }
    return r;
}

int main()
{
    cout << upper(3)<< endl;

    return 0;
}