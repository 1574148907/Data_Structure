/*
有序顺序表中删除在  s和T 之间的所有元素  （s<t）若s  T 不合理，或者表为空，显示出错信息，并退出运行
删除区间元素
*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
struct SqlList
{
    int a[Max] = {1, 2, 3, 3, 4, 5, 7, 7, 7, 8, 9};
    int length = 11;
};
bool Del_s_t(SqlList &L, int s, int t)
{
    int ss = 0;
    bool flag = false;
    if (s >= t || L.length == 0)
    {
        /* code */
        return false; // s  T 不合理，或者表为空
    }
    for (int i = 0; i < L.length; i++) // 寻找值大于或等于s 的第一个元素
    {
        if (L.a[i] >= s)
        {
            ss = i;
            flag = true;
            break;
        }
    }
    if (!flag)
        return false;
    int vv = 0;
    for (int i = ss; i < L.length; i++)
    {
        /* code */
        if (L.a[i] > t)
        {
            /* code */
            vv = i;
            break;
        }
    }
    int s1 = ss, v1 = vv;
    for (int i = vv; i < L.length; i++)
    {
        /* code */
        L.a[ss] = L.a[i];
        ss++;
    }
    L.length = L.length - (v1 - s1);
    return true;
}

// 方法二
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
    L.length = k;
}

int main()
{
    SqlList L;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    if (!Del_s_t(L, 3, 7))
    {
        /* code */
        cout<<"错误" <<endl;
    }
    cout <<"线性表产长度为" << L.length << endl;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;

    return 0;
}
