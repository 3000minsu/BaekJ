#include <stdio.h>
int n, m;
int arr[8];
int visit[8]={0};
int ans[9];
void dfs(int cnt)
{
    if(cnt==m+1)
    {
        for(int i=1; i<=m; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for(int i=0; i<n; i++)
    {
       if(visit[i]==0)
       {
           visit[i]=1;
           ans[cnt]=arr[i];
           dfs(cnt+1);
           visit[i]=0;
       }
    }
}
int main()
{
    int temp;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    dfs(1);
    return 0;
}