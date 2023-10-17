/*
两个整数序列，A={a1,a2,a3,a3....an}
B={b1,b2.........bn} 已经存在两个单链表中，
设计一个算法，判断B是否是A的连续子序列

*/

#include <iostream>

using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

int a[4] = {2, 3, 4, 5};
int n1 = 4;
int b[6] = {1, 2, 3, 4, 5, 6};
int n2 = 6;
// 尾插法建立链表

void buildList(LinkList& L, int aa[], int n) {
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    for (int i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = aa[i];
        r->next = s;
        r = s;
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

// 判断是否是子序列

bool isok(LinkList& L1, LinkList& L2) {
    LNode *p1 = L1->next, *p2 = L2->next, *r = L1->next;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data != p2->data) {
            r = r->next;
            p1 = r;
            p2 = L2->next;
        } else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    if (p2 != NULL)
        return false;
    else
        return true;
}
int main() {
    LinkList L1, L2;
    buildList(L1, a, n1);
    cout << "之前数组L1:"
         << " ";
    disp(L1);
    buildList(L2, b, n2);
    cout << "之前数组L2:"
         << " ";
    disp(L2);
    if (isok(L2, L1))
        cout << "是子序列" << endl;
    else
        cout << "不是子序列" << endl;
    return 0;
}