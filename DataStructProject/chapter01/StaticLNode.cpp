/*
静态链表
*/
#include <stdio.h>
#define MaxSize 10
struct SNode
{
    ElemType data;
    int next;
}SLink[MaxSize];
//等价于
#define MaxSize 10
struct Node
{
    ElemType data;
    int next;
};
Typedef struct Node SLink[MaxSize];





void testSLink(){
    Struct Node a[MaxSize];
    //......后续代码
}

//王道课本
