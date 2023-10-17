/*
将带头结点的单链表,使其元素递增有序
使用插入排序，*p为实时工作指针，*r为p的后继指针，防止断链，*f=L指针为新链的工作（遍历）指针

*/
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;
// 定义单链表
typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, *Linklist;
int a[7] = {3, 1, 5 , 7, 2, 1, 10};
int n = 7;
// 带头结点的，尾插法
void buildList_01(Linklist &L)
{
    L = (Linklist)malloc(sizeof(Lnode)); // 头节点
    Lnode *s, *r = L;                    //*r=L  尾指针  *s数据指针
    for (int i = 0; i < n; i++)
    { // 尾插法,第一个元素赋值
        s = (Lnode *)malloc(sizeof(Lnode));
        s->data = a[i];
        r->next = s; // r是尾指针
        r = r->next;       // 尾指针向后移 r->next=s
    }   
    r->next = NULL; // r是
}
// 排序函数
void sortList(Linklist &L)
{
    Lnode *p = L->next, *r=p->next,*f; //*r=L  尾指针  *新链表的遍历指针
    p->next = NULL;
    p=r;
    while (p)
    {
        /* code */
        r = p->next;
        f=L;
        while (f->next && f->next->data < p->data){
            f=f->next;
        }
        p->next = f->next;
        f->next = p;
        p = r;
    }

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

int main()
{

    Linklist L;
    buildList_01(L);
    display(L);
    sortList(L);
    display(L);

    return 0;
}
