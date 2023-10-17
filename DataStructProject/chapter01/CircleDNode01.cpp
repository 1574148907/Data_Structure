/*带头结点的循环双链表


*/
typdef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
// 初始化带头结点的双链表
bool InitCircleDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(Sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = L; 
    L->next = L;  
    return true;
}
// 判断单链表是否为空
bool Empty(DLinkList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}

void testDLinkList()
{
    DLinkList L;
    InitCircleDLinkList(L);
}

//判断循环双链表是否为空
bool Empty(DLinkList L){
    if(L->next == L)
        return true;
    else
        return false;
}
//判断是否为表位节点
bool is_tail(DLinkList L, DNode *p){
    if(p->next == L)
        return true;
    else
        return false;   
}
//判断是否为表头节点
bool is_head(DLinkList L, DNode *p){
    if(p->prior == L)
        return true;
    else
        return false;
}
//判断是否为中间节点
bool is_middle(DLinkList L, DNode *p){
    if(p->prior != L && p->next != L)
        return true;
    else
        return false;
}
// 循环双链表的插入
bool InsertNextDNode(DLinkList L, DNode *p, ElemType e){
    if(p == NULL)
        return false;
    DNode *s = (DNode *)malloc(Sizeof(DNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
    return true;
}
// 循环双链表的删除
bool DeleteNextDNode(DLinkList L, DNode *p){
    if(p == NULL)
        return false;
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}