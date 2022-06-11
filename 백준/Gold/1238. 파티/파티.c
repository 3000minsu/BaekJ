#include <stdio.h>
#define inf 999999;
int graph[1001][1001] = { 0 };
int n, m, x;
void floyd()
{
	for (int m = 1; m <= n; m++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (graph[s][e] > graph[s][m] + graph[m][e])
					graph[s][e] = graph[s][m] + graph[m][e];
			}
		}
	}
}
int max()
{
	int ma = 0, temp=0;
	for (int i = 1; i <= n; i++)
	{
		temp = graph[i][x] + graph[x][i];
		if (temp > ma)
			ma = temp;
	}
	return ma;
}
int main()
{
	int a, b, c;
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
				graph[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
	}
	floyd();
	printf("%d", max());
	return 0;
}