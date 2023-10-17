/*
将带头结点的单链表,使其元素节点的数据值无序
删除表中所有介于给定的两个值（函数参数给出，不包括两个值）之间的元素的元素（若存在）
删除链表区间的节点
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
int a[7] = {3, 1, 5, 7, 2, 1, 10};
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
        r = r->next; // 尾指针向后移 r->next=s
    }
    r->next = NULL; // r是
}
// 删除区间值的函数
void deleteList_a_b(Linklist &L, int min, int max)
{
    Lnode *p = L->next, *r = L; // r为p的前驱节点
    while (p)

    {
        if (p->data < max && p->data > min)
        {
            r->next = p->next;
            free(p);
            p = r->next;
        }else{
            r = p;
            p = p->next;
        }
  
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
    deleteList_a_b(L,2,7);
    display(L);

    return 0;
}
