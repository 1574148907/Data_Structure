#include <stdlib.h>
#define InitSize 10;
// 动态分配
typedef struct shunxubiao02
{
    ElemType *data; // 动态分配数组的指针
    int MaxSize;    // 最大容量
    int length;     // 当前长度
} SqlList02;
// 初始化顺序表

void InitList(SqlList02 &L)
{
    // 使用 malloc 函数申请一片连续的空间
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}
//增加动态数组的长度
void IncreaseSize(SqlList02 &L, int len)
{
    int *p = L.data;
    // 使用 malloc 函数申请一片连续的空间
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i]; // 将数据复制到新的空间里
    }
    L.MaxSize = L.MaxSize + len; // 顺序表长度增加len
    free(p);                     // 释放原来的内存空间
}

int main()
{
    SqlList02 L;
    InitList(L);
    IncreaseSize(L, 5);

    return 0;
}
