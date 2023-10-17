/*
21
单链表有环。是指单链表的最后一个节点的指针指向了链表中某个节点，（通常，单链表的最后一个节点的指针域是空的。
试着编写算法，判断单链表是否存在环
1。给出算法设计思想
2，根据设计思想，采用，C/C++ 语言描述算法，关键之处给出注解
3，说明你设计的算法的空间复杂度和时间复杂度


判断是否有环
*/
#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode;

int a[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9};
int n = 15;

void buildList(LNode* L) {
    LNode *s, *r = L;
    for (int i = 0; i < n; i++) {
        s=(LNode*)malloc(sizeof(LNode));
        r->data = a[i];
        r->next = s;
        r = r->next;
    }

    r->next = NULL;
}
void disp(LNode* L) {
    LNode* s = L;
    while (s) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

LNode* findNode(LNode* L) {
    LNode* f = L, *s = L;
    while (s != NULL && f->next != NULL) {
        s = s->next;        // 慢指针
        f = f->next->next;  // 快指针
        if (s->data == f->data)
            break;
    }
    if (s == NULL || f->next == NULL)
        return NULL;
    LNode *p = L, *q = s;
    while (p->data != q->data) {
        p = p->next;
        q = q->next;
    }
    return p;
}
int main() {
    LNode list;
    LNode* L = &list;
    buildList(L);
    cout << "L" << endl;
    disp(L);
    LNode* ans = findNode(L);
    cout << "环口值为元素" << ans->data << endl;
    return 0;
}
