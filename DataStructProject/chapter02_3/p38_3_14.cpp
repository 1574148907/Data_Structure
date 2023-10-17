/*
A  B两个单链表（带头结点），其中元素递增有序，
设计一个算法，从A到B 中公共元素产生单链表C
要求不破坏A  B节点


找公共元素
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

void buildList(LinkList &L, int aa[], int n) {
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
LinkList L3;
void bulideNew(LinkList L1, LinkList L2) {
    L3 = (LinkList)malloc(sizeof(LNode));
    LNode *p1 = L1->next, *p2 = L2->next, *s, *r;
    r = L3;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data)
            p1 = p1->next;
        else if (p1->data > p2->data)
            p2 = p2->next;
        else {
            s = (LNode*)malloc(sizeof(LNode));
            s->data = p1->data;
            r->next = s;
            r = s;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    r->next = NULL;
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

    bulideNew(L1, L2);
    cout << "合并数组L3:"
         << " ";
    disp(L3);
    return 0;
}