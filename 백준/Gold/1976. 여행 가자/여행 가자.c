#include <stdio.h>
int n, m;
int graph[201][201];
int parent[201];
int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	else
		parent[y] = x;
}
int main()
{
	int city, p, ch=0, temp;
	scanf("%d\n%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		for (int j = 1; j <= n; j++)
			scanf("%d", &graph[i][j]);
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (graph[i][j] == 1)
				merge(i, j);
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &city);
		if (i == 0)
			p = find(city);
		else
			temp = find(city);
		if (i != 0)
		{
			if (p != temp)
			{
				printf("NO");
				ch = 1;
				break;
			}
		}
	}
	if (ch == 0)
		printf("YES");

	return 0;
}