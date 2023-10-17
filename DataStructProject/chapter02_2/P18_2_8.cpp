/*
一维数组A【m+n】 依次存放两个线性表，（a1,a2,a3,a4...am ）和（b1,b2,b3...bn）
编写一个函数，将两个顺序表的位置互换，即将（b1,b2,b3...bn） 放到a1,a2,a3,a4...am  的前面
折半查找，将后面一半逆置放到前面  1234567 ---》4567123
*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
struct SqlList
{
    int a[Max] = {1, 2, 3, 4, 5, 6, 7};
    int length = 7;
};
void Reverse(SqlList &L, int left, int right)
{
    for (int i = left; i <= (left + right) / 2; i++)
    {
        /* code */
        int t = L.a[i];
        L.a[i] = L.a[right + left - i];
        L.a[right + left - i] = t;
    }
}
void print(SqlList L)
{
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
}
void Change(SqlList &L, int m, int n)
{
    cout << "整个逆置"
         << " ";
    Reverse(L, 0, n + m - 1);
    print(L);
    cout << "前n==4个逆置"
         << " ";
    Reverse(L, 0, n - 1);
    print(L);
    cout << "后m==3个逆置"
         << " ";
    Reverse(L, n, n + m - 1);
    print(L);
};
int main()
{

    SqlList L;
    Change(L, 3, 4); // m 123  n  4567
    return 0;
}
