typdef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;
// GetElem

LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
    {
        return L;
    }
    if (i < 1)
    {
        return NULL;
    }
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 不带头节点的单链表
typdef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode01, *LinkList01;
// 初始化一个空表
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}
void test()
{
    LinkList L;
    InitList(L);
}

// 判断单链表是否为空
bool Empty(LinkList L)
{
    if (L == NULL)
        return true;
    else
        return false;
}
// 或者
bool Empty(LinkList L)
{
    return (L == NULL);
}

// 带头结点的单链表
typdef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 初始化带头结点的单链表
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(Sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;

    return true;
}
void test()
{
    LinkList L;
    InitList(L);
}

// 带头结点 的单链表的插入和删除
/*            */
// 按位序插入（带头结点）
typdef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 在第i个位置插入元素 e （带头结点单链表）
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
     // --可以使用LNode *p=GetElem(L,i-1)
    LNode *p;  // 指针p 指向当前扫描到的节点
    int j = 0; // 当前p指向的是第几个节点
    p = L;     // L指向头节点，头节点是第0个节点（不存在数据）
    // 循环找到第i-1个节点
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    //---
    //-可以用return  InsertNextNode(p,e);
    if (p == NULL) // i值不合法
        return false;
    LNode *s = (LNode *)malloc(Sizeof(LNode)); // 新节点 s
    s->data = e;
    s->next = p->next;
    p->next = s; // 将节点s  链接到p之后
    return true;
    //-
}
// 按位序删除（带头结点）
bool ListDelete(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    //---可以使用LNode *p=GetElem(L,i-1)
    LNode *p;  // 指针p 指向当前扫描到的节点
    int j = 0; // 当前p指向的是第几个节点
    p = L;     // L指向头节点，头节点是第0个节点（不存在数据）
    // 循环找到第i-1个节点
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    //--
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

/*            */

// 在第i个位置插入元素 e （不带头结点单链表）
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    if (i = 1)
    { // 插入第一个节点操作与其他节点操作不同
        LNode *s = (LNode *)malloc(Sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s; // 头指针指向新节点
        retuen true;
    }
    LNode *p;  // 指针p 指向当前扫描到的节点
    int j = 1; // 当前p指向的是第1个节点
    p = L;     // p指向第1个节点（注意 不是头节点）
    // 循环找到i-1个节点
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    //  调用后插操作  InsertNextNode
    //  --后插操作  return  InsertNextNode(p,e);
    if (p == NULL) // i值不合法
        return false;
    LNode *s = (LNode *)malloc(Sizeof(LNode)); // 新节点 s
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 指定节点的后插操作  在p节点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false; // 内存分配失败
    LNode *s = (LNode *)malloc(Sizeof(LNode));
    if (s == NULL)
        return false;
    s->data = e; // 用节点s 保存数据元素e
    s->next = p->next;
    p->next = s; // 将节点s链接到pzh
    return true;
}

// 前插操作  在p节点之前插入元素e(偷天换日)
bool InsertPriorNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(Sizeof(LNode));
    if (s == NULL) // 内存分配失败
        return false;
    s->next = p->next;
    p->next = s;       // 将节点s链接到p->next
    s->data = p->data; // 将p->data前移
    p->data = e;       // 将e赋值给p->data
    return true;
}

// 按位序删除（带头节点）
typdef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 删除第i个元素
bool DeleteNode(LinkList &L, int i, ElemType &e)
{
    if (i < 1)
        return false;
    LNode *p;  // 指示被删节点的指针
    int j = 0; // 指示操作位置的指针
    p = L;     // 头指针
               // 寻找第i-1个结点
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL) // 删除位置不合理
        return false;
    if (p->next == NULL) // 删除位置为最后一个节点
        return false;
    LNode *q = p->next;
    e = q->data; // 保存被删节点的数据
    p->next = q->next;
    free(q);
    return true;
}
