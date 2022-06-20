#include <stdio.h>
int dp[100001] = { 0 };
int dp2[100001] = { 0 };
int lug[100][2];
int n, k;
int main()
{
    int j = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &lug[i][0], &lug[i][1]);
    for (int i = 0; i < n; i++)
    {
        while (lug[i][0] + j <= k)
        {
            if (dp2[lug[i][0] + j] < dp2[j] + lug[i][1])
                dp[lug[i][0] + j] = dp2[j] + lug[i][1];
            j++;
        }
        for (int a = 0; a <= k; a++)
            dp2[a] = dp[a];
        j = 0;
    }
    printf("%d", dp[k]);


    return 0;
}