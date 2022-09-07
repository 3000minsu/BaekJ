#include <bits/stdc++.h>
using namespace std;
int arr[500000];
int find(int x)
{
    if(arr[x]==x)
        return x;
    return arr[x]=find(arr[x]);
}
int merge(int x, int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
        return 1;
    else
    {
        if(x<y)
            arr[y]=x;
        else
            arr[x]=y;
        return 0;
    }
}
int main()
{
    int n, m, a, b, temp, ch=0, i;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        arr[i]=i;
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        temp=merge(a,b);
        if(temp)
        {
            ch=1;
            break;
        }
    }
    if(ch==1)
        printf("%d", i+1);
    else    
        printf("0");
    return 0;
}