#include <stdio.h>
int m, n;
int arr[8];
//int visit[8]={0};
int ans[8];
void dfs(int cnt, int pa)
{
    if(cnt ==m)
    {
        for(int i=0; i<m; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for(int i=pa; i<n; i++)
    {
        ans[cnt]=arr[i];
        dfs(cnt+1, i+1);
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
    dfs(0, 0);
    return 0;
}