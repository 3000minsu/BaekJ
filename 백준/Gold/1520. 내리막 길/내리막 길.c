#include <stdio.h>
int graph[500][500];
int dp[500][500] = { 0 };
int visit[500][500] = { 0 };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0,0 };
int n, m;//n이 세로
int cnt = 0;
void dfs(int y, int x)
{
	int tx, ty;
	if (visit[y][x] && dp[y][x] == 0)
		return;
	visit[y][x] = 1;
	if (y == n - 1 && x == m - 1)
	{
		cnt++;
		dp[n - 1][m - 1]=1;
		return;
	}
	if (dp[y][x] != 0)
	{
		cnt += dp[y][x];
		return;
	}
	for (int i = 0; i < 4; i++)
	{
	
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx >= 0 && tx < m && ty >= 0 && ty < n &&graph[y][x]>graph[ty][tx])
		{
			dfs(ty, tx);
			dp[y][x] += dp[ty][tx];
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &graph[i][j]);
	}
	dfs(0, 0);
	printf("%d", cnt);
	return 0;
}