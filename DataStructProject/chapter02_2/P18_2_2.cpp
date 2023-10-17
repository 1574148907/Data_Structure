/*
设计一个高效算法，将顺序表的元素逆置，空间复杂度为O(1)

*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
struct SqlList
{
    int a[Max] = {1, 4, 6, 3, 2,8, 7, 9};
    int length = 8;
};
void Reverse(SqlList &L)
{
    for (int i = 0; i<L.length/2; i++)
    {
        int v=L.a[i];
        L.a[i]=L.a[L.length-i-1];
        L.a[L.length-i-1]=v;

    }
    
}
int main()
{
    SqlList L;
   for (int  i = 0; i < L.length; i++) cout<<L.a[i]<<" ";
   cout<<endl;
   Reverse(L);
   for (int  i = 0; i < L.length; i++) cout<<L.a[i]<<" ";
   cout<<endl;

    return 0;
}
