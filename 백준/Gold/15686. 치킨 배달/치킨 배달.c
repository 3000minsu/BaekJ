#include <stdio.h>
#include <stdlib.h>
#define inf 100000
int n, m, k=0;
int field[50][50];
int dis[50][50];
int chi[13][2];
int ans[13][2];
int min = inf;
void find()
{
	int temp=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (field[i][j] == 1)
			{
				for (int k = 0; k < m; k++)
				{
					if (abs(i - ans[k][0]) + abs(j - ans[k][1]) < dis[i][j])
						dis[i][j] = abs(i - ans[k][0]) + abs(j - ans[k][1]);
				}
				temp += dis[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dis[i][j] = inf;
		}
	}
	if (temp < min)
		min = temp;
}
void back(int cnt, int pa)
{
	if (cnt == m)
	{
		find();
		return;
	}
	for (int i = pa; i < k; i++)
	{
		ans[cnt][0] = chi[i][0];
		ans[cnt][1] = chi[i][1];
		back(cnt + 1, i + 1);
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &field[i][j]);
			dis[i][j] = inf;
			if (field[i][j] == 2)
			{
				chi[k][0] = i;
				chi[k][1] = j;
				k++;
			}
		}
	}
	back(0, 0);
	printf("%d", min);
	return 0;
}