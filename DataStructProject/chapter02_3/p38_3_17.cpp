/*
17
判断带头节点的循环双链表是否对称


*/

#include <iostream>

using namespace std;
typedef struct circleLNode {
    int data;
    struct circleLNode *next, *prior;
} circleLNode, *circleLinkList;

int a[9] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
int n = 9;

// 建立循环双链表

void buildList(circleLinkList& L) {
    L = (circleLinkList)malloc(sizeof(circleLNode));
    circleLNode *s, *r = L;
    L->prior = L;
    L->next = L;
    for (int i = 0; i < n; i++) {
        s = (circleLNode*)malloc(sizeof(circleLNode));
        s->data = a[i];
        s->next = r->next;
        r->next->prior = s;
        s->prior = r;
        r->next = s;
        r = s;
        L->prior = s;
    }
}
void disp(circleLinkList L) {
    circleLNode* s = L->next;
    while (s != L) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

// 判断是否是子序列

bool isok(circleLinkList& L) {
    circleLNode *p = L->next, *q = L->prior;
    while (p != q && q->next != p) {
        if (p->data = q->data) {
            p = p->next;
            q = q->prior;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    circleLinkList L;

    buildList(L);
    disp(L);

    if (isok(L))
        cout << "是" << endl;
    else
        cout << "不是子序列" << endl;
    return 0;
}