#include <stdio.h>
int graph[101][101] = { 0 };
int ans[101] = { 0 };
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
void know()
{
	int cnt = 0, temp = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!graph[i][j] && !graph[j][i])//어느 방향으로도 경로 없다면 무게 비교불가
				ans[i]++;
		}
	}
}
int main()
{
	int a, b;
	scanf("%d\n%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
	}
	floyd();
	know();
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]-1);//자기자신도 카운트돼서 -1해줌
	
	return 0;
}