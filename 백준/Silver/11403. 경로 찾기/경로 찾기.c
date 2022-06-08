#include <stdio.h>
#define inf 99999999
int n;
int graph[101][101] = { 0 };
void floyd()
{
	for (int m = 0; m < n; m++)
	{
		for (int s = 0; s < n; s++)
		{
			for (int e = 0; e < n; e++)
			{
				if (graph[s][e] > graph[s][m] + graph[m][e])
					graph[s][e] = graph[s][m] + graph[m][e];
			}
		}
	}
}
int main()
{
	int temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &temp);
			if (temp == 0)
				graph[i][j] = inf;
			else
				graph[i][j] = 1;

		}
	}
	floyd();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == inf)
				printf("0 ");
			else
				printf("1 ");
		}
		printf("\n");
	}
	return 0;
}