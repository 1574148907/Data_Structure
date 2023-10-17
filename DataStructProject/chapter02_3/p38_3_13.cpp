/*
假设按元素值递增次序排列的线性表，均已单链表形式存储，
请编写算法，将两个单链表归并成一个按元素值递减次序排列的单链表
要求，利用两个单链表的节点存放归并后的单链表
L1 ={2，4，8} *p1指针， r指针为p1的后继指针，防止断链
L2 ={3,5,6,9} *p2指针


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
int a[4] = {1, 3, 7, 10};
int n1 = 4;
int b[6] = {2, 4, 6, 8, 9, 11};
int n2 = 6;

// 带头结点的，尾插法
void buildList(Linklist& L, int aa[], int n) {
    L = (Linklist)malloc(sizeof(Lnode));  // 头节点
    Lnode *s, *r = L;                     //*r=L  尾指针  *s数据指针
    for (int i = 0; i < n; i++) {         // 尾插法,第一个元素赋值
        s = (Lnode*)malloc(sizeof(Lnode));
        s->data = aa[i];
        r->next = s;  // r是尾指针
        r = r->next;  // 尾指针向后移 r->next=s
    }
    r->next = NULL;  // r是
}

// 重新排列单链表元素 递减 (头插法)
void meger(Linklist& L1, Linklist& L2) {
    Lnode *p2 = L2->next, *p1 = L1->next, *r;
    L1->next = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            r = p1->next;
            p1->next = L1->next;
            L1->next = p1;
            p1 = r;
        } else {
            r = p2->next;
            p2->next = L1->next;
            L1->next = p2;
            p2 = r;
        }
    }
    if (p1)
        p2 = p1;
    while (p2) {
        r = p2->next;
        p2->next = L1->next;
        L1->next = p2;
        p2 = r;
    }
    free(L2);
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
    Linklist L1, L2;
    buildList(L1, a, n1);
    buildList(L2, b, n2);
    cout << "之前数组L1:"
         << " ";
    display(L1);
    cout << "之前数组L2:"
         << " ";
    display(L2);
    meger(L1, L2);
    cout << "合并后数组L3:"
         << " ";
    display(L1);

    return 0;
}