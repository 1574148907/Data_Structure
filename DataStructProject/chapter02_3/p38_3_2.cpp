/*
在头节点的单链表L中，删除所有值为X的节点，，并释放空间，
假设x的值不唯一，

*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next; // 指向下一个节点
} LNode, *LinkList;

int a[9] = {1, 2, 3, 3, 5, 6, 7, 8, 9};
int n = 9;
// 带头节点 尾插法函数
void buildList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L; //*r=L  尾指针  *s数据指针
    for (int i = 0; i < n; i++)
    { // 尾插法,第一个元素赋值
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s; // r是尾指针
        r =r->next;       // 尾指针向后移
    }
    r->next=NULL; // r是
}
//输出链表
void display(LinkList L)
{
    LNode *s = L->next;
    while(s!=NULL)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}
void delete_x01(LinkList &L, int x)
{
    LNode *p = L->next, *q, *r = L; // r :尾指针  p:遍历（实时指针）  p指针在前，r指针在后
    while (p!=NULL)
    {
        if (p->data != x)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        { // q指针指向删除的元素
            q = p;
            p = p->next;
            free(q);
        }
    }
}
int main()
{
    LinkList L;
    buildList(L);
    display(L);
    delete_x01(L, 3);
    display(L);
    return 0;
}