#include <stdio.h>
int n;
int sta[301];
int dp[301][2] = { 0 };
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int temp;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &sta[i]);
	dp[1][0] = 0;
	dp[1][1] = sta[1];
	if (n == 1)
	{
		printf("%d", sta[1]);
		return 0;
	}
	else if (n == 2)
	{
		printf("%d", sta[1] + sta[2]);
		return 0;
	}
	dp[2][0] = sta[2];
	dp[2][1] = sta[1] + sta[2];
	for (int i = 1; i <= n; i++)
	{
		if (i + 1 <= n)
		{
			if (dp[i + 1][1] < dp[i][0] + sta[i + 1])
				dp[i + 1][1] = dp[i][0] + sta[i + 1];
		}
		
		if (i + 2 <= n)
		{
			temp = max(dp[i][1] + sta[i + 2], dp[i][0] + sta[i + 2]);
			if (dp[i + 2][0] < temp)
				dp[i + 2][0] = temp;
		}
	}
	temp = max(dp[n][0], dp[n][1]);
	printf("%d", temp);
	return 0;
}