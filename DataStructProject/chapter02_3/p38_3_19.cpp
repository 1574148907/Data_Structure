/*
19，
带头节点的循环单链表，其节点值均为正整数
，设计一个算法，反复找出单链表中节点值最小的节点输出
然后将该节点删除，直到单链表空为止，再删除表头节点
  L=r=mp指针    min=p=L->next    p为r指针的前驱，进行遍历
  min指针为标记最小值   mp指针为最小值的前驱

循环单链表依次输出最小值并删除节点
*/
#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

int a[5] = {3, 5, 2, 7, 4};
int n = 5;

    // 建立
void buildList(LinkList & L) {
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    for (int i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
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

void deletetList(LinkList& L) {
    LNode *p = L->next, *r = L, *min = p, *mp = r;
    while (L->next != L) {
        p = L->next, r = L, min = p, mp = r;

        while (p != L) {
            if (p->data < min->data) {
                min = p;
                mp = r;
            } else {
                r = p;
                p = p->next;
            }
        }
        cout << "min:" << min->data << endl;
        mp->next = min->next;
        free(min);
    }
    free(L);
}
int main() {
    LinkList L;
    buildList(L);
  cout <<"L:"<<endl;
  disp(L);
  deletetList(L);
  
    return 0;
}