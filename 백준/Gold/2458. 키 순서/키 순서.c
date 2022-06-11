#include <stdio.h>
#define inf 10000;
int graph[501][501] = { 0 };
int n, m;
void floyd()
{
	for (int m = 1; m <= n; m++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (graph[s][m] && graph[m][e])
					graph[s][e] = 1;
			}
		}
	}
}
int know()
{
	int cnt = 0, temp=0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] || graph[j][i])//모두 연결되어있는지 체크
				temp++;
		}
		if (temp == n - 1)
			cnt++;
		temp = 0;
	}
	return cnt;
}
int main()
{
	int a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
	}
	floyd();
	printf("%d", know());
	return 0;
}