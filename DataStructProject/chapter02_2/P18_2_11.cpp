/*
长度L （L>=1） 的升序序列S  在【L/2】位置上称为S的中位数，
例如：S1=（11，13，15，17，19 ） S1的中位数是15  两个序列的中位数是他们所有元素升序序列的中位数
例如 S2=（2，4，6，8，20）
则s1和s2 的中位数是11，现在有两个等长升序序列A B 找出A和B的中位数


*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
int a[5] = {11, 13, 15, 17, 19};
int b[5] = {2, 3, 4, 5, 20};
int c[10];

int verge(int a[], int b[], int c[])
{
    int i = 0, j = 0, k = 0;
    while (i < 5 && j < 5)
    {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < 5)
        c[k++] = a[i++];

    while (j < 5)
        c[k++] = b[j++];
    return c[(k-1) / 2];
}

int main()
{
    int t = verge(a, b, c);
    for (int i = 0; i < 10; i++)
        cout << c[i] << " ";

    cout << endl;

    cout << "中位数" << t << endl;
}
