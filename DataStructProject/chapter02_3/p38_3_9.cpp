/*
一个带头结点的单链表，设head为头指针，节点结构为（data，next）
data为整形元素，next为指针，按递增次序输出单链表中个结点的数据
并释放节点所占用的空间（不许使用数组作为辅助空间）
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

// 每次删除最小值，输出
void deleteMin(Linklist& L) {
    while (L->next != NULL) {
        Lnode *r = L, *p = r->next;
        while (p->next != NULL) {
            if (p->next->data < r->next->data)
                r = p;
                p = p->next;
            
        }
        cout << (r->next->data) << " ";
        Lnode *q = r->next;  // q节点存每次删除的最小值
        r->next = q->next;
        free(q);
    }
    free(L);
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
    buildList_01(L);
    // display(L);
    deleteMin(L);
    return 0;
}
