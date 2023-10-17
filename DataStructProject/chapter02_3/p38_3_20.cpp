/*
20，
头指针为L 的带有表头节点的非循环双链表，，其中每个节点除了pre(前驱指针)
data数据，和next后继指针，还有一个访问频度域，freq。
在链表被启用前，其值均初始化为0.
每当在locate(L,x) 运算时，令元素值为x的节点中freq域的值增加1，
并使此链表中节点保持按照访问频率非增（递减）的数序排列，同时，最近访问的节点排在同频度节点的前面，以便使频繁访问的节点总是靠近表头
试着编写符合上述要求的locate（L，e）运算的算法，该算法为函数过程，返回找到节点的地址，类型为指针类型

双链表查找元素，在排序

*/
#include <iostream>
using namespace std;
typedef struct LNode {
    int data, f;
    struct LNode *next, *prior;
} LNode, *LinkList;

int a[5] = {3, 5, 2, 7, 4};
int n = 5;

// 建立非循环双链表
void NocircleList(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    L->prior = NULL;
    L->next = L;

    for (int i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        s->f = 0;
        s->next = r->next;
        r->next->prior = s;
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;  // 建立循环双链表
}
// 打印函数
void disp(LinkList L) {
    LNode* s = L->next;
    while (s != NULL) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}
// 链接

LinkList Locate(LinkList& L, int x) {
    LNode *p = L->next, *q;
    while (p != NULL && p->data != x)
        p = p->next;
    if (!p)
        cout << "没有这个节点" << endl;
    else {
        p->f++;
        if (p->next != NULL)
            p->next->prior = p->prior;
        p->prior->next = p->next;
        q = p->prior;

        while (q != L && q->f <= p->f)
            q = q->prior;
        p->next = q->next;
        q->next->prior = p;
        p->prior = q;
        q->next = p;
    }
    return p;
}
int main() {
    LinkList L;

    NocircleList(L);

    disp(L);
    Locate(L, 4);
    disp(L);
    return 0;
}