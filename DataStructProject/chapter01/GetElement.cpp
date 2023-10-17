//按位查找
#define InitSize 10;
typedef struct{
    int *data;
    int MaxSize;
    int length;
}SqlList;
int GetEle(SqlList L ,int i){
    return L.data[i-1];
    
}

//按值查找

#define InitSize 10;
typedef struct{
    int *data;
    int MaxSize;
    int length;
}SqlList02;
int GetEle(SqlList L ,int e){
    for (int i = 0; i < L.length; i++)
   if (L.data[i]==e)
   {
    return i+1;  //数组下标为i的元素值等于e   其返回的位序为 i+ 
   }
   return 0;
    
    
}