/*
将带头结点的单链表就地逆置，，就地指辅助空间的复杂度为O(1)
*r 指针作为p的后继，防止断链

*/
#include <bits/stdc++.h>
using namespace std;
// 定义单链表
typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, *Linklist;
int a[10] = {1, 2, 3, 3, 5 , 6, 7, 8, 9, 10};
int n = 10;
// 带头结点的，尾插法
void buildList_01(Linklist &L)
{
    L = (Linklist)malloc(sizeof(Lnode)); // 头节点
    Lnode *s, *r = L;                    //*r=L  尾指针  *s数据指针
    for (int i = 0; i < n; i++)
    { // 尾插法,第一个元素赋值
        s = (Lnode *)malloc(sizeof(Lnode));
        s->data = a[i];
        r->next = s; // r是尾指针
        r = s;       // 尾指针向后移
    }   
    r->next = NULL; // r是
}
// 带头结点的，使用头插法，将尾插法建立的链表就地逆置
void buildList_02(Linklist &L)
{
    Lnode *p = L->next, *r;                    //*r=L  尾指针  *s数据指针
    L->next = NULL;
    while (p)
    {
        /* code */
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }

}

// 输出链表
void display(Linklist L)
{
    Lnode *s = L->next;
    while (s != NULL)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

int main()
{

    Linklist L;
    buildList_01(L);
    display(L);
    buildList_02(L);
display(L);
    return 0;
}
