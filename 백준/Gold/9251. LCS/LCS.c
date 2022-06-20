#include <stdio.h>
#include <string.h>
int lcs(char arr1[1002], char arr2[1002])
{
	int len1, len2;
	int ch = 0;
	int dp[1001][1001];
	len1 = strlen(arr1);
	len2 = strlen(arr2);
	for (int i = 0; i < len2; i++)
	{
		if (arr1[0] == arr2[i])
			ch = 1;
		if (ch == 0)
			dp[0][i] = 0;
		else
			dp[0][i] = 1;

	}
	for (int i = 1; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				if (j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i-1][j - 1] + 1;
			}
			else
			{
				if (j == 0)
					dp[i][j] = dp[i - 1][j];
				else
				{
					if (dp[i - 1][j] > dp[i][j - 1])
						dp[i][j] = dp[i - 1][j];
					else
						dp[i][j] = dp[i][j - 1];
				}

			}
		}
	}
	return dp[len1 - 1][len2 - 1];
}	
int main()
{
	char arr1[1002];
	char arr2[1002];
	scanf("%s", arr1);
	scanf("%s", arr2);
	printf("%d", lcs(arr1, arr2));
	return 0;
}