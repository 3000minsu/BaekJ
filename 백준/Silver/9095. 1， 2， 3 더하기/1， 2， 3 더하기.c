#include <stdio.h>
int ca, n, cnt=0;
int arr[1000];
int ans[1000];
void dfs(int pre)
{
    if(pre==n)
    {
        cnt++;
        return;
    }
    if(pre>n)
        return;
    for(int i=1; i<=3; i++)
    {
        dfs(pre+i);
    }
}
int main()
{
    scanf("%d", &ca);
    for(int i=0; i<ca; i++)
    {
        scanf("%d", &n);
        dfs(0);
        ans[i]=cnt;
        cnt=0;
    }
    for(int i=0; i<ca; i++)
        printf("%d\n", ans[i]);
    return 0;
}