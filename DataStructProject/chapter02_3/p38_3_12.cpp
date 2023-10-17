/*
在递增有序地线性表中，有数值相同的元素存在，若存储方式为单链表，
设计算法，去掉数值相同的元素，使表中不在有重复的元素
例如（7，10，10，21，30，42，42，42，51，）将变为（7，10，21，30，42，51）

p=L->next;  q=p->next; q为p的后继

*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;
// 定义单链表
typedef struct Lnode {
    int data;
    struct Lnode* next;
} Lnode, *Linklist;
int a[10] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 51};
int n = 10;

// 带头结点的，尾插法
void buildList(Linklist& L) {
    L = (Linklist)malloc(sizeof(Lnode));  // 头节点
    Lnode *s, *r = L;                     //*r=L  尾指针  *s数据指针
    for (int i = 0; i < n; i++) {         // 尾插法,第一个元素赋值
        s = (Lnode*)malloc(sizeof(Lnode));
        s->data = a[i];
        r->next = s;  // r是尾指针
        r = r->next;  // 尾指针向后移 r->next=s
    }
    r->next = NULL;  // r是
}

// 删除重复元素
void deleteList(Linklist& L) {
    Lnode *q, *p = L->next;
    if (p == NULL)
        return;  // 空表

    while (p->next != NULL) {
        q = p->next;
        if (p->data == q->data) {
            p->next = q->next;
            free(q);
        } else
            p = p->next;
    }
}

// 输出链表
void display(Linklist L) {
    Lnode* s = L->next;
    while (s != NULL) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

int main() {
    Linklist L;
    buildList(L);
    cout << "之前数组L:"
         << " ";
    display(L);
    deleteList(L);
    cout << "之后数组L1:"
         << " ";
    display(L);
    return 0;
}