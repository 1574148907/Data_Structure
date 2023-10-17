/*  p18页14题
定义三元组（a,b,c）,均为整数，的距离D=|a-b|+|b-c|+|c-a| ,给定3个非空集合S1,S2,S3,
按照升序分别存储在3个数组中
计算出三元组（a,b,c）【 a属于S1,b属于S2 c属于S3 】
最小距离
例如
S1={-1,0,9},S2={-25,10,10,11} S3={2,9,17,30,41}
最小距离为2，相应的三元组（9，10，9 ）                                                                                                                                                                                                                                                                                                                                ）

*/

#include <bits/stdc++.h>
using namespace std;
#define Max 0x7fffffff;
// 求绝对值
int abss(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
// 判断3个数，那个数最小
bool minn(int a, int b, int c)
{
    {
        if (min(a, min(b, c)) == a)
            return true; // 如果a的值最小，那就返回true 否则返回false
        return false;
    }
}
// 求最小值
int findd(int a[], int b[], int c[], int na, int nb, int nc)
{
    int i = 0, j = 0, k = 0, ans = Max; // 下标
    while (i < na && j < nb && k < nc && ans >= 0)
    {                                                                      // i<na  i小于a数组的个数，j小于b数组的个数,k小于c数组的个数
        int v = abss(a[i] - b[j]) + abss(b[j] - c[k]) + abss(c[k] - a[i]); // 题中给出的
        if (v < ans)
        { // 如果v小于ans，就更新ans
            ans = v;
        }
        if (minn(a[i], b[j], c[k]))
            i++;
        else
        {
            if (minn(b[j], c[k], a[i]))
                j++;
            else
                k++;
        }
    }
    return ans;
}

int main()
{
    int a[3] = {-1, 0, 9}, b[4] = {-25, -10, 10, 11}, c[5] = {2, 9, 17, 30, 41};
    int na = 3, nb = 4, nc = 5;
    cout << findd(a, b, c, na, nb, nc) << endl;

    return 0;
}
