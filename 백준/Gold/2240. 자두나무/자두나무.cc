//움직인 횟수, 각 초마다 각자리의 최댓값 고려
#include <iostream>
#include <utility>
using namespace std;
int position[1002][2] = { 0 };
int dp[1002][32][2] = { 0 };
int max(int a, int b)
{
	return a >= b ? a : b;
}
int main()
{
	int t, w, temp, ans=-1;
	scanf("%d %d", &t, &w);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d", &temp);
		position[i][temp-1] = 1;
	}
	
	for (int i = 1; i <= t; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			for (int k = 0; k <= 1; k++)
			{
				if (j != 0)
				{
					if (k == 1)
						dp[i][j][k] = max(dp[i - 1][j][k] + position[i][k], dp[i - 1][j - 1][0] + position[i][k]);
					else
						dp[i][j][k] = max(dp[i - 1][j][k] + position[i][k], dp[i - 1][j - 1][1] + position[i][k]);
				}
				else
				{
					if (i != 1 || k != 1)
						dp[i][j][k] = dp[i - 1][j][k] + position[i][k];
				}
				
			}
		}
	}
	
	for (int j = 0; j <= w; j++)
	{
		for (int k = 0; k <= 1; k++)
		{
			if (ans < dp[t][j][k])
				ans = dp[t][j][k];
		}
	}

	printf("%d", ans);
	return 0;
}