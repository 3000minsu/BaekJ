#include <stdio.h>
#define inf 10000
int dp[5001];
int main()
{
    int n, cnt=0, temp;
    scanf("%d", &n);
    for(int i=0; i<=n; i++)
        dp[i]=inf;
    dp[3]=1;
    dp[5]=1;
    for(int i=0; i<=n; i++)
    {
       if(dp[i]!=inf)
       {
           if(dp[i+3]>dp[i]+1)
               dp[i+3]=dp[i]+1;
           if(dp[i+5]>dp[i]+1)
               dp[i+5]=dp[i]+1;
       }
    }
    if(dp[n]!=inf)
        printf("%d", dp[n]);
    else
        printf("-1");
    
    return 0;
}