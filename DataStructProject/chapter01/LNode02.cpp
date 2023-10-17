/*
尾插法建立单链表


*/
typdef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 初始化带头结点的单链表
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
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
//尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
     L->next = NULL; // 建立头节点
    scanf("%d", &x);
    while (x != 9)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;// 生成新节点
        r->next = s;// 插入到表尾
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}
// 头插法建立单链表
bool List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL; // 建立头节点
    scanf("%d", &x);
    while (x != 9)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return true;    

}
