/*
从有序顺序表中删除所有值重复的元素，使表中所有元素的值均不同
*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
struct SqlList
{
    int a[Max] = {1,2,2,3,4};
    int length = 4;

};
void DeleteList(SqlList &L){

int black =1; //黑指针
for (int  red = 1; red < L.length; red++)
{
    /* code */
    if (L.a[red]!=L.a[red-1]){   //  1,2,3,4
        L.a[black]=L.a[red];
        black++;
    }
    
}
L.length=black;

}

int main()
{
    SqlList L;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    DeleteList(L);
    cout << "线性表产长度为" << L.length << endl;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;

    return 0;
}
