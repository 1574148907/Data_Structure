/*
设L为带头结点的单链表，，实现从头到尾反向输出每个节点的值
*/
#include <bits/stdc++.h>
using namespace std;
// 定义单链表
typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, *Linklist;
int a[9] = {1, 2, 3, 3, 5, 6, 7, 8, 9};
int n = 9;
// 不带头结点的单链表
void buildList_01(Lnode *L)
{
    Lnode *r = L, *s;
    r->data = a[0];
    if (n == 1)
        r->next = NULL;
    else
    {
        for (int i = 1; i < n; i++)
        {
            s = (Lnode *)malloc(sizeof(Lnode));
            s->data = a[i];
            r->next = s;
            r = r->next;
        }
        r->next = NULL;
    }
}
// //递归逆置
void display01(Lnode *L)
{
    if (L != NULL)
    {
        display01(L->next);
        cout << (L->data) << " ";
    }
    else
        return;
}
// 带头结点的单链表，尾插法
void buildList_02(Linklist &L)
{
    L = (Linklist)malloc(sizeof(Lnode)); // 头节点
    Lnode *s, *r = L;                    //*r=L  尾指针  *s数据指针
    for (int i = 0; i < n; i++)
    { // 尾插法,第一个元素赋值
        s = (Lnode *)malloc(sizeof(Lnode));
        s->data = a[i];
        r->next = s; // r是尾指针
        r = s;       // 尾指针向后移
    }
    r->next = NULL; // r是
}

// 递归逆置
void display02(Linklist L)
{
    if (L != NULL)
    {
        display02(L->next);
        cout << (L->data) << " ";
    }
    else
        return;
}
int main()
{
    Lnode list;
    Lnode *L=&list;
   buildList_01(L);
    display01(L);
cout<<"-----"<<endl;
    Linklist Li;
    buildList_02(Li);
    display02(Li);
    return 0;
}
