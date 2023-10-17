/*带头结点的循环单链表


*/
typdef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;
//初始化循环单连表
bool InitList(LinkList &L){
    L = (Lnode * )malloc(sizeof(LNode));
    if(L == NULL){
        return false;
    }
    L->next = L;
    return true;
}
//判断循环单链表是否为空
bool Empty(LinkList L){
if(L->next == L){
        return true;
    }
    return false;   
}
//判断节点p是否为循环单链表的表位节点
bool IsTail(LinkList L, LNode *p){
    if(p->next == L){
        return true;
    }
    return false;   
}
//求表长
int ListLength(LinkList L){
    int len = 0;
    LNode *p = L->next;
    while(p != L){
        len++;
        p = p->next;
    }
    return len;
}