#include <bits/stdc++.h>
#define inf 2e9;
using namespace std;
int n, k;
int lug[102][2];
int dp[102][10100] = { 0 };
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &lug[i][0]);
	for (int i = 0; i < n; i++)
		scanf("%d", &lug[i][1]);
	int result = inf;
	for (int j = 0; j <= 10000; j++) {
		if (lug[0][1] <= j)
			dp[0][j] = lug[0][0];
		if (dp[0][j] >= k)
			result = min(result, j);
	}


	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (lug[i][1] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - lug[i][1]] + lug[i][0]);
			else
				dp[i][j] = dp[i - 1][j];

			if (dp[i][j] >= k) 
				result = min(result, j);
		}
	}
	printf("%d", result);

	return 0;
}