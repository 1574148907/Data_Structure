// 定义顺序栈
#define MaxSize 10
typedef struct {
    int data[MaxSize];  // 静态数组存放栈中元素
    int top;            // 栈顶指针
} SequenceStack;        // Sequence 顺序
// C
void InitStack(SequenceStack& S) {
    S.top = -1;  // 栈顶指针置为-1
}
void testStack() {
    SequenceStack S;  // 定义栈
    InitStack(S);
    //...后续操作
}
// 判断栈空
void StackEmpty(SequenceStack S) {
    if (S.top == -1) {
        cout << "栈空" << endl;
        // printf("栈空\n");
        return;
    } else {
        cout << "栈非空" << endl;
        // printf("栈非空\n");
        return;
    }
}

// 进栈操作
#define MaxSize 10
typedef struct {
    int data[MaxSize];  // 静态数组存放栈中元素
    int top;            // 栈顶指针
} SequenceStack_01;

// 新元素入栈
bool Push(SequenceStack_01& S, ElemType e) {
    if (S.top == MaxSize - 1)  // 栈满，报错
        return false;
    S.top = S.top + 1;  // 指针先加1
    S.data[S.top] = x;  // 两行等价与    S.data[++S.top]=x;
    return true;
}
// 出栈
bool Pop(SequenceStack_01& S, Element& x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];  // 栈顶元素先出栈
    S.top = S.top - 1;  // 指针再减1    等价于 x=S.data[S.top--];
    return true;
}
//读取栈顶元素
bool GetTop(SequenceStack_01 S,ElemType &x){
    if (S.top=-1)
    return false;
    x=S.data[S.top];  //x记录栈顶元素
    return true;
    
}
//判断栈空
bool StackEmpty(SequenceStack_01 S){
    if(S.top==0)
    return true;
    else
    return false; 
}
int main() {
    SequenceStack S;
    InitStack(S);
    StackEmpty(S);
}

//共享栈
#define MaxSize 10
typedef struct {
    int data[MaxSize];  // 静态数组存放栈中元素
    int top0;            //0号栈顶 顶指针
      int top1;            //1栈底的底指针
} SequenceStack_02;
//初始栈
void InitStack(ShStack &S){
    S.top0=-1;
    S.top1=MaxSize;
}
