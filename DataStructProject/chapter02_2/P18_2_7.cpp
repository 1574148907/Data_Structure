/*
将两个有序顺序表合并成一个新的有序顺序表，用函数返回结果顺序表
a{4}={2,3,4,6,7}
i  指针
b{4}={3,4,4,6,7}
j 指针
合并成c{}
k 指针 下标
*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
struct SqlList
{
    int data[Max];
    int length;
};
bool Verge(SqlList a, SqlList b, SqlList &c)
{
    if (c.length < a.length + b.length)
        return false;
    int i=0,j=0,k=0;
    while (i < a.length && j < b.length)
    {
        /* code */
        if (a.data[i] <= b.data[j]) // 两个表的第一个元素比较
        {
            /* code */
            c.data[k++] = a.data[i++];
        }
        else
        {
            c.data[k++] = b.data[j++];
        }
    }
    while (i < a.length)
    {
        /* code */
        c.data[k++] = a.data[i++];
    }
    while (j < b.length)
    {
        /* code */
        c.data[k++] = b.data[j++];
    }

    c.length = a.length + b.length;
    return true;
}

int main()
{
    SqlList a = {{4, 9,6,8, 7}, 5};
    SqlList b = {{2,1,5}, 3};
    SqlList c;
    c.length = 8;
    for (int i = 0; i < a.length; i++)
        cout << a.data[i] << " ";
    cout << endl;
    for (int j = 0; j < b.length; j++)
        cout << b.data[j] << " ";
    cout << endl;
    if (!Verge(a, b, c))
    {
        cout << "合并错误" << endl;
    }
    else
    {
        for (int i = 0; i < c.length; i++)
            cout << c.data[i] << " ";
        cout << endl;
    }

    return 0;
}
