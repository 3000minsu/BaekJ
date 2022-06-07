#include <stdio.h>
#define inf 99999
int n, m, r;
int graph[101][101];
int item[101];
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
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] <= m)
				temp += item[j];
		}
		if (temp > ma)
			ma = temp;
		temp = 0;
	}
	return ma;
}
int main()
{
	int a, b, c;
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &item[i]);
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = inf;
			if (i == j)
				graph[i][j] = 0;
		}
	}
	
	for (int i = 0; i < r; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		
			if (graph[a][b] > c)
			{
				graph[a][b] = c;
				graph[b][a] = c;
			}
	}
	floyd();
	printf("%d", max());
	return 0;
}