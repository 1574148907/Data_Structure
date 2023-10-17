/*
从顺序表中删除最小值元素（假设唯一），并返回被删除的元素的值，空出的位置由最后一个元素填补。
若顺序表为空，显示出错信息退出.有个bug,如果最后一个元素最小。则顺序表元素没变
*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
struct SqlList
{
    int a[Max] = {22, 32, 52, 6, 74, 92, 71, 11, 41};
    int length = 9;
};
bool ListDelete(SqlList &L, int &e)
{
    if (L.length == 0)
        return false;
    int min = L.a[0];
    int flag = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.a[i] < min)  //3
        {
            min = L.a[i];
            flag = i;
        }
    }
    e = L.a[flag];
    L.a[flag] = L.a[L.length-1]; //空出的位置由最后一个元素填补。
    return true;
}
int main()
{
    SqlList L;
    cout << "原先数组为" << endl;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    int k = 0;
    if (ListDelete(L, k))
    {
        cout << "最小元素为k==" << k << endl;
        cout << "修改之后的线性表为" << endl;
        for (int i = 0; i < L.length; i++)
        {
            cout << L.a[i] << " ";
        }
    }
    else
    {
        cout << "输出错误" << endl;
    }

    return 0;
}
