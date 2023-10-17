/*
22
单链表查找倒数第k个节点
题目：
带头结点的单链表，查找单链表中倒数第k个位置上的节点（k为正数），若查找出成功，输出该节点的data值，返回1；
否则，返回0
1，描述算法的设计思想
2，描述算法的详细实现步骤
3，写出c++代码，必要处给出注解


*/
#include <iostream>
using namespace std;
typedef struct LNode {
    int data, f;
    struct LNode *next, *prior;
} LNode, *LinkList;

int a[5] = {5, 4, 3, 2, 1};
int n = 5;

// 建立单链表
void buildList(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;

    for (int i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];

        r->next = s;
        r = s;
    }
    r->next = NULL;
}
// 查找

int find_k(LinkList& L, int k) {
    LNode *p = L->next, *q = L->next;
    int num = 0;
    while (p != NULL) {
        if (num < k)  num++;
        else q = q->next;
        p = p->next;
    }
    if (num < k)
        return 0;
    else {
        cout << "倒数第k个节点值为" << q->data << endl;
        return 1;
    }
}
int main() {
    LinkList L;

    buildList(L);
    cout <<find_k(L,2)<<endl;

   
    return 0;
}