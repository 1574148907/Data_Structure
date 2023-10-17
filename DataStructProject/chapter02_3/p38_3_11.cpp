/*
设C={a1,b1,a2,b2,........an,bn} 为线性表，采用带头结点的单链表存放，
设计一个就地算法，将其差分为两个线性表，使得A={a1,a2,a3....an}
B={bn....b3,b2,b1};
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
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int n = 10;

// 带头结点的，尾插法
void buildList_01(Linklist &L) {
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

// 分开链表
Linklist L2;
Linklist cutList(Linklist &L1) {
    L2 = (Linklist)malloc(sizeof(Lnode));
    L2->next = NULL;
    Lnode *r1 = L1, *q, *p = L1->next; //p指针指向首元素
    while (p != NULL) {
        r1->next = p;
        r1 = p;
        p = p->next;
        if (p != NULL) {
            q = p->next;
            p->next = L2->next;
            L2->next = p;
            p = q;
        }
    }
    r1->next = NULL;

    return L2;
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
    Linklist L1;
    buildList_01(L1);
    cout << "之前数组L1:"
         << " ";
    display(L1);
    cutList(L1);
    cout << "之后数组L1:"
         << " ";
    display(L1);
    cout << "之后数组L2:"
         << " ";

    display(L2);
    return 0;
}