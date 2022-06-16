#include <stdio.h>
int n, m;
int ans[9];
int visit[9]={0};
void dfs(int cnt, int pa)
{
     if(cnt==m+1)
     {
         for(int i=1; i<=m; i++)
             printf("%d ", ans[i]);
         printf("\n");
         return;
     }
    for(int i=pa; i<=n; i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            ans[cnt]=i;
            dfs(cnt+1, i+1);
            visit[i]=0;
        }
        
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    dfs(1, 1);
    return 0;
}