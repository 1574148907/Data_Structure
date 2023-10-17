/*带头结点的双链表


*/
typdef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
// 初始化带头结点的双链表
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(Sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL; // 头结点的前驱为空
    L->next = NULL;  // 头结点的后继为空
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
    InitDLinkList(L);
}

// 双链表的插入,在p节点的后面插入s节点
bool InsertNextDNode(DLinkList &L, DNode *p, ElemType e)
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}
// 双链表的删除,删除p节点的后继节点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;
    DNode *q = p->next;
    if (q == NULL)
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}
//销毁双链表
void DestroyDLinkList(DLinkList &L)
{
    while (L->next != NULL)/* 循环结束条件是链表为空 */
    {
        DeleNextDNode(L);
    }
      free(L);
      L=NULL;

}
//后向遍历
void TraverseDLinkList(DLinkList L) {
    DNode *p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;  
    }
    cout << endl;
}
//前向遍历
void TraverseDLinkList_2(DLinkList L) {
   DNode *p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->prior;  
    }
    cout << endl;
}
//前向遍历(跳过头节点)
void TraverseDLinkList_3(DLinkList L) {
   DNode *p = L->next;
    while (p->prior != NULL) {
        cout << p->data << " ";
        p = p->prior;  
    }
    cout << endl;
}