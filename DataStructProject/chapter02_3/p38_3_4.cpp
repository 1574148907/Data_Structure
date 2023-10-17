/*
设L为带头结点的单链表，，删除最小值节点的高效算法（最小直接点唯一）
*p 指针：实时指针L->next=p   *q:标识最小指针(初始化时是指针p)
*r ：遍历时r指针是p指针的前驱   *s:存最小值节点前驱


*/
#include <bits/stdc++.h>
using namespace std;
// 定义单链表
typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, *Linklist;
int a[10] = {1, 2, 3, 3, 5,0, 6, 7, 8, 9};
int n = 10;
// 不带头结点的尾插法
// void buildList_01(lnode *L)
// {
//     lnode *r = L, *s;
//     r->data = a[0];
//     if (n == 1)
//         r->next = NULL;
//     else
//     {
//         for (int i = 1; i < n; i++)
//         {
//             s = (lnode *)malloc(sizeof(lnode));
//             s->data = a[i];
//             r->next = s;
//             r = r->next;
//         }
//         r->next = NULL;
//     }
// }
// //递归逆置
// void display(lnode *L)
// {
//     if (L != NULL)
//     {
//         display(L->next);
//         cout << (L->data) << " ";
//     }
//     else
//         return;
// }
// 带头结点的，尾插法
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

// 输出链表
void display(Linklist L)
{
    Lnode *s = L->next;
    while (s != NULL)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}
// 删除最小值
void deleteMin(Linklist &L)
{
    Lnode *p = L->next, *q, *r = L, *s;
    q = p; // *p 指针：实时指针L->next=p   *q:标识最小指针(初始化时是指针p)
    s = r; // s为找到最小值的前驱，初始化时与r（p的前驱），一样
    while (p != NULL)
    {
        if (p->data < q->data)
        {
            q = p;
            s = r;
        }
        r = p;
        p = p->next;
    }
    s->next = q->next;
    free(p);
}
int main()
{

    Linklist L;
    buildList_02(L);
    display(L);
    deleteMin(L);
    display(L);
    return 0;
}
