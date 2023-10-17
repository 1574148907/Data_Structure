/*
设将n （n>1）个整数存放在一维数组R中，设计一个时间，空间尽可能高效的算法，
将R保存的序列循环左移p (0<p<n) 个位置，
将R中的数据由（x0 ,x1,x2,x3....xn-1）变为（xp,xp+1 ...  xn-1,x0,x1..xp-1  ）


*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
int a[9] = {1, 2, 3,4, 5, 6, 7, 8, 9};
int length = 9;
void Reverse(int a[], int left,int right)
{
    for (int  i = left; i < (left+right)/2; i++)
    {
        /* code */
        int t=a[i];
        a[i]=a[(left+right)-i];
        a[(left+right)-i]=t;
    }
}
void Print(int a[]){
    for (int i = 0; i < length; i++)
   cout<<a[i]<<" ";
   cout<<endl;
    
}
void Change(int a [], int left){
  cout << "整个逆置"
         << " ";
    cout<<endl;
    Reverse(a, 0, length - 1);
    Print(a);
    cout << "前n-left 个逆置"  
         << " ";  //9-6=3  前7个逆置，
       cout<<endl;
    Reverse(a, 0, length-left-1);
    Print(a);
    cout << "后left 个逆置"  
         << " ";    //后6个逆置
     cout<<endl;
    Reverse(a, length-left, length-1);
    Print(a);


}
int main()
{

    cout <<"开始数组"<< endl;
    Print(a);
    Change(a, 6);
    cout <<"结束数组"<< endl;
    Print(a);
    return 0;
}
