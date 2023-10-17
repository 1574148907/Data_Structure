#define MaxSize 10;
typedef struct shunxubiao01
{
    ElemType data[MaxSize];//静态分配
    int length;
}SqlList01;

//动态分配
typedef struct shunxubiao02
{
    ElemType *data;//动态分配数组的指针
    int MaxSize; //最大容量
    int length;//当前长度
}SqlList02;
