#include <stdio.h>
#define inf 99999999
int n, m;
int graph[101][101] = { 0 };
//int flo[101][101];
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
int main()
{
	int a, b, c;
	scanf("%d", &n);
	scanf("%d", &m);
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
		if (graph[a][b] != inf)
		{
			if (c < graph[a][b])
				graph[a][b] = c;
		}
		else
			graph[a][b] = c;
	}
	floyd();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == inf)
				printf("0 ");
			else
				printf("%d ", graph[i][j]);
		}
		printf("\n");
	}

}