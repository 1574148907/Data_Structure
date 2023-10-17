/*
22
单链表查找倒数第k个节点
题目：
采用头节点的单链表保存单词，当两个单词有相同后缀时，可共享相同的后缀存储空间
例如：loading   和being的存储映像
srt1 str2 分别指向两个单词所在单链表的头节点，链表节点结构如下 data next
请设计一个时间上尽可能高效的算法，找出str1  str2
所指向的两个链表共同后缀的的起始位置 1，描述算法的设计思想
2，描述算法的详细实现步骤
3，写出c++代码，必要处给出注解


*/
#include <bits/stdc++.h>
using namespace std;
typedef struct LNode {
    int data, f;
    struct LNode *next, *prior;
} LNode, *LinkList;

char a[7] = {'l', 'o', 'a', 'd', 'i', 'n', 'g'};
char b[5] = {'b', 'e', 'i', 'n', 'g'};
int n1 = 7, n2 = 5;

// 建立单链表
void buildList(LinkList& L ,char aa[], int n) {
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;

    for (int i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = aa[i];
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

int length(LinkList L) {
    int ans = 0;
    LNode* s = L->next;
    while (s != NULL) {
        ans++;
        s = s->next;
    }
    return ans;
}

// 查找

LinkList find_first(LinkList L1, LinkList L2) {
    int len1 = length(L1), len2 = length(L2);
    int dist = abs(len1 - len2); //取绝对值的库函数
    LNode *p = L1->next, *q = L2->next;
    if (len1 >= len2) {
        while (dist--) {
            p = p->next;
        }
    } else {
        while (dist--) {
            q = q->next;
        }
    }
    while (p != NULL) {
        if (p->data != q->data) {
            p = p->next;
            q = q->next;
        } else {
            return p;
        }
    }
    return p;
}
int main() {
    LinkList L1, L2;
    buildList(L1, a, n1);
    buildList(L2, b, n2);
    cout << "L1:" << endl;
    disp(L1);

    cout << "L2:" << endl;
    disp(L2);

    cout << "find_first:" << endl;
    LinkList ans = find_first(L1, L2);
    cout << "公共后缀的起始节点为" << ans->data << endl;

    return 0;
}