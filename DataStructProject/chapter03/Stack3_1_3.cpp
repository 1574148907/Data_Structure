// 定义链栈   只能在链表的链头 进行插入和删除  就是栈顶
#define MaxSize 10
typedef struct {
    int data[MaxSize];  // 静态数组存放栈中元素
    struct LinkStackNode *next;            // 指针域
} *LinkStrackNode;        // 

//用单链表实现链栈。分为  带头节点连栈和不带头节点的链栈
//进栈和出栈。类似于在表头进行插入和删除
//链栈  推荐不带头节点的链栈




