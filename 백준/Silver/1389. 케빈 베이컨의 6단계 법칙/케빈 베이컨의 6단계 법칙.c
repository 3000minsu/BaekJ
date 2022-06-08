#include <stdio.h>
#define inf 100000
int n, m, i, j;//n은 사람수 m은 간선수
int graph[101][101] = { 0 };
void floy()
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
	int a, b, min = inf, temp=0, minp;
	scanf("%d %d", &n, &m);
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
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	floy();
	for (i = 1; i <= n; i ++)
	{
		for (j = 1; j <= n; j++)
		{
			temp += graph[i][j];
		}
		if (temp < min)
		{
			min = temp;
			minp = i;
		}
		temp = 0;
	}

	printf("%d", minp);


}