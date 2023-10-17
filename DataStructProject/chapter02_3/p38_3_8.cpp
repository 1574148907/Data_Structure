/*
两个单链表，找出公共节点
*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;
// 定义单链表
typedef struct Lnode {
    int data;
    struct Lnode* next;
} Lnode, *Linklist;
int a[7] = {3, 1, 5, 7, 2, 4, 10};
int b[2] = { 4, 10};
int a1 = 7;
int b1 = 2;
// 带头结点的，尾插法
void buildList_01(Linklist& L, int aa[], int n) {
    L = (Linklist)malloc(sizeof(Lnode));  // 头节点
    Lnode *s, *r = L;                     //*r=L  尾指针  *s数据指针
    for (int i = 0; i < n; i++) {         // 尾插法,第一个元素赋值
        s = (Lnode*)malloc(sizeof(Lnode));
        s->data = aa[i];
        r->next = s;  // r是尾指针
        r = r->next;  // 尾指针向后移 r->next=s
    }
    r->next = NULL;  // r是
}
// 算链表长度函数
int length_L(Linklist L) {
    int k = 0;
    Lnode* s = L->next;
    while (s) {
        k++;
        s = s->next;
    }
    return k;
}
// 返回的是节点
Linklist findd(Linklist L1, Linklist L2) {
    int len1 = length_L(L1), len2 = length_L(L2);
    int dist = 0;
    Linklist long1, short1;
    if (len1 > len2) {
        long1 = L1->next;
        short1 = L2->next;
        dist = (len1 - len2);
    } else {
        long1 = L2->next;
        short1 = L1->next;
        dist = (len2 - len1);
    }
    while (dist--)
        long1 = long1->next;
    while (long1) {
        if (long1->data == short1->data &&
            long1->next->data == short1->next->data) {
            return long1;
        } else {
            long1 = long1->next;
            short1 = short1->next;
        }
    }
    return NULL;
}

// 输出链表
void display(Linklist L) {
    Lnode* s = L->next;
    while (s != NULL) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

// // 暴力解法
// Linklist findd_02(Linklist L1, Linklist L2) {
//     Lnode* s1 = L1->next;
//     while (s1) {
//         Lnode* s2 = L2->next;
//         while (s2) {
//             if (s1->data == s2->data && s1->next->data == s2->next->data) {
//                 return s1;
//             } else {
//                 s2 = s2->next;
//             }
//         }
//         s1 = s1->next;
//     }
//     return NULL;
// }

int main() {
    Linklist L1, L2;
    buildList_01(L1, a, a1);
    display(L1);
    buildList_01(L2, b, b1);
    display(L2);
    Linklist L3 = findd(L2, L1);
    cout << L3->data << "" << endl;
    display(L3);
    return 0;
    // Linklist L3 = findd_02(L1, L2);
    // cout << L3->data << "" << endl;
    // display(L3);
}
