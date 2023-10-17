/*
线性表（a1,a2,a3,a4...an ）的元素递增有序且按顺序存储在计算机中，设计一个算法
用最少时间查找数值为x的元素，
若找到，将其与后继元素位置交换，，找不到，插入表中并使表中元素依旧递增有序
折半查找
*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
int a[Max] = {1, 2, 3, 5, 6, 7, 8, 9};
int length = 8;
void Findd(int a[], int x)
{
    int left, right, mid;
    left = 0, right = length - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
            break;
        else if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (a[mid] == x && mid != length - 1) // 若最后一个元素与x相等，则不存在与其前后继交换操作
    {
        int t = a[mid];
        a[mid] = a[mid + 1];
        a[mid + 1] = t;
    }
    if (right < left) // 查找失败，插入元素x
    {
        int i;
        for (i = length - 1; i > right; i--)
        {
            /* code */
            a[i + 1] = a[i]; // 后移元素
        }
        a[i + 1] = x; //
    }
}
int main()
{
    for (int i = 0; i < 8; i++)
        cout << a[i] << " ";
    cout << endl;
    Findd(a, 4);
    int i;
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
