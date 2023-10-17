/*
25
题目：
设线性表L={a1,a2,a3,a4,a5 ...an-2, an-1, an},采用带头结点的单链表保存，
链表中定义如下

重新排列单链表使其
L={a1,an,a2,an-1,a3,an-2,....}

 1，描述算法的设计思想 运用（桶排序原理）
2，描述算法的详细实现步骤
3，写出c++代码，必要处给出注解
4，说明时间复杂度和空间复杂度
保留链表绝对值相同的首个节点
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int n = 8;

// 建立单链表
void buildList(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    for (int i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

void disp(LinkList L) {
    LNode* s = L->next;
    while (s != NULL) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

// 查找

void newList(LinkList& L) {
    LNode *p, *q, *s, *r;
    p = L, q = L;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
        if (q->next != NULL)
            q = q->next;
    }
    q = p->next;
    p->next = NULL;
    while (q) {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = L->next;
    q = p->next;
    p->next = NULL;
    while (q) {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s=q->next;
        q = r;
    }
}

int main() {
    LinkList L;
    buildList(L);
    cout << "之前L:" << endl;
    disp(L);
    newList(L);
    cout << "之后:"  << endl;
    disp(L);
    return 0;
}