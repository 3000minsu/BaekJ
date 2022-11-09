#include <iostream>
using namespace std;
bool wall[18][18] = { false };
int dp[18][18][3] = { 0 };
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		wall[0][i] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			scanf("%d", &wall[i][j]);
	}
	dp[1][2][0] = 1;
	
	for (int i = 1; i <= n; i++)
	{
		for(int j=3; j <= n; j++)
		{
			if (wall[i][j])
				continue;
			if (!wall[i][j - 1])
				dp[i][j][0] = dp[i][j - 1][2] + dp[i][j - 1][0];
			if (!wall[i - 1][j])
				dp[i][j][1] = dp[i - 1][j][2] + dp[i - 1][j][1];
			if (!wall[i - 1][j - 1] && !wall[i][j - 1] && !wall[i - 1][j])
				dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
		}
	}
	
	printf("%d", dp[n][n][0]+ dp[n][n][1] + dp[n][n][2]);
	return 0;
}