/*
18，有两个循环单链表，表头指针分别为h1,h2,编写一个函数将链表h2链接到链表h1之后
要求，链接后的链表任然保持循环链表的形式

循环单链表拼接
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

int a[4] = {1, 2, 3, 4};
int n1 = 4;
int b[5] = {5, 6, 7, 8, 9};
int n2 = 5;

// 建立循环双链表
void buildList(LinkList& L, int aa[], int n) {
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    for (int i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = aa[i];
        r->next = s;
        r = r->next;
    }
    r->next = L;  // 建立循环双链表
}
// 打印函数
void disp(LinkList L) {
    LNode* s = L->next;
    while (s != L) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}
// 链接

void add(LinkList& L1, LinkList& L2) {
    LNode *p = L1->next, *q = L2->next;
    while (p->next != L1) {
        p = p->next;
    }
    while (q->next != L2) {
        q = q->next;
    }
    p->next = L2->next;
    q->next = L1;
}
int main() {
    LinkList L1, L2;
    buildList(L1, a, n1);
    cout << "L1" << endl;
    disp(L1);
    buildList(L2, b, n2);
    cout << "L2" << endl;
    disp(L2);
    cout << "拼接后L1" << endl;
    add(L1, L2);
    disp(L1);
    return 0;
}