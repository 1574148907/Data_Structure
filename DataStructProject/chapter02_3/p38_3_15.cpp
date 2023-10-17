/*
A  B两个单链表（带头结点），分别表示两个集合，其元素递增排序，
其中元素递增有序，
编辑算法，求A，B的交集，并存放在A链表中

保留公共节点，其余删除

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

void deleteList(LinkList& L1, LinkList& L2) {
    LNode *p1 = L1->next, *p2 = L2->next, *q, *r = L1;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            q = p1;
            p1 = p1->next;
            free(q);
        } else if (p1->data > p2->data) {
            q = p2;
            p2 = p2->next;
            free(q);
        } else {  // 俩个指针指向相同元素
            // L1
            r->next = p1;
            r = p1;
            p1 = p1->next;
            // L2 删除L2中相同元素
            q = p2;
            p2 = p2->next;
            free(q);
        }
    }
        while (p1) {
            q = p1;
            p1 = p1->next;
            free(q);
        }
        while (p2) {
            q = p2;
            p2 = p2->next;
            free(q);
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

        deleteList(L1, L2);
        cout << "合并数组L3:"
             << " ";
        disp(L1);
        return 0;
    }