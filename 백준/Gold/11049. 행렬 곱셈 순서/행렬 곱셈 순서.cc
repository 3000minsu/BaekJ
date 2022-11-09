#include <iostream>
#include <utility>
#define inf 2147483647
using namespace std;
pair<int, int> mat[502];
int dp[502][502];
int min(int a, int b)
{
	return a > b ? b : a;
}
int main()
{
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		mat[i].first = a;
		mat[i].second = b;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = inf;
		}
	}

	for (int i = 1; i< n; i++)
	{
		for (int j = 0; i+j < n; j++)
		{
			for (int k = 0; k < i; k++)
			{
				dp[j][j + i] = min(dp[j][j + i], dp[j][j + k] + dp[j + k + 1][i + j] + mat[j].first * mat[j + k].second * mat[i + j].second);
			}
		}
	}

	printf("%d", dp[0][n - 1]);


	return 0;
}