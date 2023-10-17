/*
设计一个递归算法，删除不带头节点的单链表L中所有x的节点

*/
#include <bits/stdc++.h>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;

int a[4] = {1, 2, 3, 4};
int n = 4;
// 不带头节点 尾插法函数
void buildList(LNode *L)
{
    LNode *s, *r = L;
    r->data = a[0]; // 尾指针指向第一个元素
    if (n == 1)
        r->next = NULL;
    else
    {
        for (int i = 1; i < n; i++)
        { // 尾插法,第一个元素赋值
            s = (LNode *)malloc(sizeof(LNode));
            s->data = a[i];
            r->next = s; // r是尾指针
            r = s;       // 尾指针向后移
        }
        r->next = NULL;
    }
}
// 遍历链表
void display01(LNode *L)
{
    LNode *s = L;
    for (s; s != NULL; s = s->next)
    {
        cout << s->data << " ";
    }
    cout << endl;
}

void display(LNode *L)
{
    LNode *s = L;
    while (s != NULL)
    {
        cout << (s->data) << " ";
        s = s->next;
    }
    cout << endl;
}
void delete_x(LNode *&L, int x)
{
    LNode *p;      // p指向待删除的节点
    if (L == NULL) // 递归出口
        return;
    if (L->data == x)
    {
        p = L;
        L = L->next;
        free(p);
        delete_x(L, x);
    }
    else
        delete_x(L->next, x);
}
int main()
{
    LNode list;
    LNode *L = &list;
    buildList(L);
    display(L);
    delete_x(L, 2);
    display(L);
    return 0;
}