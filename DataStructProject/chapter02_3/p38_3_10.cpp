/*
带头结点的单链表，分解成两个带头结点的单链表A，B
使A表中含有原表中序号为奇数的元素 而B表中含有为偶数的元素，且保持相对位置不变
 *r1=L1  *r2=L2  *p=L1->next;
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
int a[7] = {2, 7, 4, 1, 9, 3, 6};
int n = 7;

// 带头结点的，尾插法
void buildList_01(Linklist& L) {
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
void cutList(Linklist& L1) {
    L2 = (Linklist)malloc(sizeof(Lnode));
     L2->next = NULL;
    Lnode *r1 = L1, *r2 = L2, *p= L1->next;
    int i = 0;
    L1->next = NULL;
    while (p) {
        i++;
        if (i % 2 == 0) {
            r2->next = p;
            r2 = p;
        } else {
            r1->next = p;
            r1 = p;
        }
        p = p->next;
    }
    r1->next = NULL;
    r2->next = NULL;
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
    cout << "之前数组L1" << " ";
    cutList(L1);
    display(L1);
    cout << "之后数组L2"<< " ";
    display(L2);
    return 0;
}
