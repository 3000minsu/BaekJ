#include <stdio.h>
#define inf 99999999
int graph[101][101] = { 0 };
int dp[101][101][101] = { 0 };
int n, m;
void floyd()
{
	for (int m = 1; m <= n; m++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (graph[s][e] > graph[s][m] + graph[m][e])
				{
					graph[s][e] = graph[s][m] + graph[m][e];

					dp[s][e][0] = dp[s][m][0] + dp[m][e][0] - 1;

					for (int i = 1; i <= dp[s][m][0]; i++)
						dp[s][e][i] = dp[s][m][i];

					for (int i = 2; i <= dp[m][e][0]; i++)
						dp[s][e][(i-1) + dp[s][m][0]] = dp[m][e][i];
				}
			}
		}
	}
}
void print()
{
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



	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k <= dp[i][j][0]; k++)
			{
				printf("%d ", dp[i][j][k]);
			}
			printf("\n");
		}
	}
}


int main()
{
	int a, b, c;
	scanf("%d\n%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
				graph[i][j] = inf;
			/*else
			{
				dp[i][j][0] = 1;
				dp[i][j][1] = i;
			}*/

		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (graph[a][b] > c)
		{
			graph[a][b] = c;
			dp[a][b][0] = 2;
			dp[a][b][1] = a;
			dp[a][b][2] = b;
		}
	}
	floyd();
	print();
	return 0;
}