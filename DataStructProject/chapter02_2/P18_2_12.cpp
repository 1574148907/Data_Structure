/*  p17页12题
已知整数序列，A=(a0,a1...an-1) 其中0<=ai<n (0<=i<n),若存在ap1=ap2=ap3 ...  apm=x
且m>2/n (0<=pk<n,1<=k<=m), 称x为A的主元素，
例如 A=（0，5，5，3，5，7，5，5） 5为主元素，  又如A=(0,5,5,3,5,1,5,7) 没有主元素
假设 A 中n个元素保存在一个一维数组中，请设计一个高效算法，找出A的主元素。
存在主元素，输出，不存在，就输出-1；

*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
int a[8] = {0, 5, 5, 3, 5, 7, 5, 5};
int b[8] = {0, 5, 5, 3, 5, 1, 5, 7};
int n = 8;

bool half(int a[], int &cc)
{

    int c = a[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        /* code */
        if (a[i] == c)
        {
            /* code */
            count++;
        }
        else
        {
            if (count > 0)
                count--;
            else
            {
                c = a[i];
                count = 1;
            }
        }
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        /* code */
        if (a[i] == c)
        {
            /* code */
            k++;
        }
    }
    if (k > n / 2)
    {
        cc = c;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int cc;
    if (half(a, cc))
    {
        cout << "主元素为" << cc << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return 0;
}
