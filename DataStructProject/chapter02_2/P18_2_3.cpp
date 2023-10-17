/*长度为n的线性表，删除线性表中 值为x的元素，时间复杂度为O（n） 空间复杂度为O（1）

*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
struct SqlList
{
    int a[Max] = {5, 2, 0, 1, 3, 1, 4, 1, 1, 4};
    int length = 10;
};
void del_x_1(SqlList &L, int x)
{
    int k = 0; // 记录L中等于x的元素的个数

    for (int i = 0; i < L.length; i++)
    {
        if (L.a[i] == x)
        {
            /* code */
            k++;
        }
        else
        {
            L.a[i - k] = L.a[i];
        }
    }
    L.length = L.length - k;
}

//方法二
void del_x_2(SqlList &L, int x)
{
    int k = 0; // 记录L中不等于x的元素的个数

    for (int i = 0; i < L.length; i++)
    {
        if (L.a[i] != x)
        {
          L.a[k] = L.a[i];
            k++;
        }
         
    }
     L.length =k;
}

int main()
{
    SqlList L;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    del_x_2(L, 1);
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;

    return 0;
}
