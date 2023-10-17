/*
顺序表中删除在  s和T 之间的所有元素  （s<t,包含  s  t ）若s  T 不合理，或者表为空，显示出错信息，并退出运行
删除区间元素
*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
struct SqlList
{
    int a[Max] = {4, 1, 2, 5, 0, 0, 3};
    int length = 7;

};
bool Del_s_t(SqlList &L, int s, int t)
{
    int k = 0;
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
            flag = true;
            break;
        }
    }
    //  s 不在线性表中
    if (!flag)
        return false;

    for (int i = 0; i < L.length; i++)
    {
        /* code */
        if (L.a[i] > s && L.a[i] < t)  //包含s 元素 t元素 不能 =
        {
            k++;
        }
        else
        {
            L.a[i - k] = L.a[i];
        }
    }
    L.length=L.length-k;
    return true;
}

// 方法二
// void del_x_2(SqlList &L, int x)
// {
//     int k = 0; // 记录L中不等于x的元素的个数

//     for (int i = 0; i < L.length; i++)
//     {
//         if (L.a[i] != x)
//         {
//             L.a[k] = L.a[i];
//             k++;
//         }
//     }
//     L.length = k;
// }

int main()
{
    SqlList L;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    if (!Del_s_t(L, 1, 5))
    {
        /* code */
        cout << "错误" << endl;
    }
    cout << "线性表产长度为" << L.length << endl;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;

    return 0;
}
