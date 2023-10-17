/*
24

题目：
用单链表保存m个整数，节点结构为data  link  且|data| <=n, （n为正整数）
设计一个时间复杂度尽可能高效的算法，对于链表中的data 的绝对值相等的节点
仅保留第一次出现的节点而删除其余绝对值相等的节点
例如：给定单链表head 如下
【】->【21】——》【-15】-》【-15】-》【-7】-》【15】
删除后
【】-》【21】-》【-15】-》【-7】

 1，描述算法的设计思想 运用（桶排序原理）
2，描述算法的详细实现步骤
3，写出c++代码，必要处给出注解
4，说明时间复杂度和空间复杂度
保留链表绝对值相同的首个节点
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct LNode {
    int data, f;
    struct LNode *next, *prior;
} LNode, *LinkList;

int a[7] = {1, -4, 2, -2, 3, -4, 2};
int n = 7;

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

void find_first_abs(LinkList& L, int n) {
    LNode* p = L;
    int* q;
    q = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n + 1; i++)
        *(q + i) = 0;
    int s;
    LNode* f;
    while (p->next != NULL) {
        s = abs(p->next->data);
        if (*(q + s) == 0) {
            *(q + s) = 1;
            p = p->next;
        } else {
            f = p->next;
            p->next = f->next;
            free(f);
        }
    }

    free(q);
}

int main() {
    LinkList L;
    buildList(L);
    cout << "L:" << endl;
    disp(L);
    find_first_abs(L, 4);
    cout << "之后" << endl;
    disp(L);
    return 0;
}