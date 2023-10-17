#include <stdio.h>
#define MaxSize 10
typedef struct {
    int data[MaxSize];//静态数组
    int length;
}SqlList;
//基本操作，初始化一个顺序表
void InitList(SqlList  &L){
    for (int i = 0; i<MaxSize; i++)
        L.data[i]=0;//将所有元素设置为默认初始值
        L.length=0;
    
}


int  main(){
    SqlList L;
    InitList(L);
    //这样访问是违规的  应该是 i<L.length;
    for (int  i = 0; i < MaxSize; i++)
    printf("data[%d]=%d\n",i,L.data[i]);
    
    return 0;
}