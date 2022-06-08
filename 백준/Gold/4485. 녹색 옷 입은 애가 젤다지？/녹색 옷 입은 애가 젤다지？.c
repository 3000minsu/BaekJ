#include <stdio.h>
#define inf 999999

int graph[126][126];
int dp[126][126];
int visit[126][126] = { 0 };
int n;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans[300];
void dij()
{
	int tx, ty, min=inf;
	int nowx=0, nowy=0, minx=0, miny=0;
	visit[0][0] = 1;
	dp[0][0] = graph[0][0];
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			tx = nowx + dx[i];
			ty = nowy + dy[i];
			if (tx >= 0 && tx < n && ty >= 0 && ty < n)
			{
				if (dp[ty][tx] > dp[nowy][nowx] + graph[ty][tx])
					dp[ty][tx] = dp[nowy][nowx] + graph[ty][tx];
			}
		}
		min = inf;
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dp[i][j] < min&&visit[i][j]==0)
				{
					min = dp[i][j];
					miny = i; 
					minx = j;
					
				}
			}
		}
		if (minx == n - 1 && miny == n - 1)
			break;
		visit[miny][minx] = 1;
		nowx = minx;
		nowy = miny;
	}


}
int main()
{
	int p = 1;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &graph[i][j]);
				dp[i][j] = inf;
			}
		}
		dij();
		ans[p] = dp[n - 1][n - 1];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visit[i][j] = 0;
				dp[i][j] = inf;
			}
		}
		p++;
	}
	for (int i = 1; i < p; i++)
		printf("Problem %d: %d\n", i, ans[i]);

	return 0;
}