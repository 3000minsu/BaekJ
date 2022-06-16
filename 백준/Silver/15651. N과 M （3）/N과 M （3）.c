#include <stdio.h>
int n, m;
int ans[8];
void dfs(int cnt)
{
     if(cnt==m+1)
     {
         for(int i=1; i<=m; i++)
             printf("%d ", ans[i]);
         printf("\n");
         return;
     }
     for(int i=1; i<=n; i++)
     {   
        ans[cnt]=i;
        dfs(cnt+1);   
     }
}
int main()
{
    scanf("%d %d", &n, &m);
    dfs(1);
    return 0;
}