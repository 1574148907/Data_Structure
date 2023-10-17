/*  p18页13题
找数组中最小正整数

*/

#include <bits/stdc++.h>
using namespace std;
#define Max 50
int a[4] = {-5, 3, 2, 3};
int b[3] = {1, 2, 3};
int n = 4;

int findMisMin(int a[])
{
    int c[n + 2] = {0};
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && a[i] <=n + 1)
            c[a[i]] = 1;
    }

    int ans = 0;
    for (int i = 1; i < n + 2; i++)
    {
        if (c[i] == 0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
   for(int i=0;i<n;i++)
   cout<<a[i]<<" ";
   cout<<endl;
   cout<<findMisMin(a)<<endl;

}
