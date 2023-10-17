#define MaxSize 10;
typedef struct{
    int data[MaxSize];
    int length;

}SqlList;

void InitList(SqlList02 &L)
{
    // 使用 malloc 函数申请一片连续的空间
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}
bool ListInsert(SqlList &L,int i,int e){
    if (i<1 || i>L.length+1) return false;//在第i个位置上插入元素，判断i的范围是否有效
    if (L.length>=MaxSize) return false;//当存储空间满，不能插入
//遍历顺序表
   for (int  j = L.length; j>=i ; j--){//将第i个元素以及之后元素后移
    //  data[5] =data[4]
   L.data[j]=L.data[j-1]; //数组元素
   L.data[i-1]=e;
   }
   L.length++;
   return true;    
}
//删除
bool ListDelete(SqlList &L,int i,int &e){
    if (i<1 || i>L.length+1) return false;//在第i个位置上插入元素，判断i的范围是否有效
 e=L.data[i-1];

//遍历顺序表
   for (int  j = i; j<L.length ; j++){//将第i个位置后的元素前移
    //  data[5] =data[4]
   L.data[j-1]=L.data[j]; //数组元素
   }
   L.length--;
   return true;    
}

int main()
{
   SqlList L;
   InitList(L);
//    ListInsert(L,3,3)
int e=-1;
if (ListDelete(L,3,e))
{
    printf("删除第三个元素，值为%d",e)
}else{
    printf("删除失败")
}
return 0;

}
