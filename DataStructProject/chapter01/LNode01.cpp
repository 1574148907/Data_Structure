
/*

单链表查找（带头结点）
按位查找


*/
typdef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;
// GetElem
// 按位查找，返回第i个元素 （带头结点）
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    int j = 0;                 // j为计数器
    LNode *p;                  // 指针p指向当前结点
    p = L;                     // p指向头结点
    while (p != NULL && j < i) /* 遍历单链表 */
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找，找到数据作用域==e的节点 （带头结点）
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p;
    p = L->next; // p指向第一个元素结点
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}
// 求表长
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 在第i个位置插入元素 e （带头结点单链表）
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    LNode *p;  // 指针p 指向当前扫描到的节点
    int j = 0; // 当前p指向的是第几个节点
    p = L;     // L指向头节点，头节点是第0个节点（不存在数据）
    // 循环找到第i-1个节点
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL) // i值不合法
        return false;
    LNode *s = (LNode *)malloc(Sizeof(LNode)); // 新节点 s
    s->data = e;
    s->next = p->next;
    p->next = s; // 将节点s  链接到p之后
    return true;
}
// 删除第i个元素
bool ListDelete(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    LNode *p;  // 指针p 指向当前扫描到的节点
    int j = 0; // 当前p指向的是第几个节点
    p = L;     // L指向头节点，头节点是第0个节点（不存在数据）
    // 循环找到第i-1个节点
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL) // i值不合法
        return false;
    if (p->next == NULL)
        return false;

    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}