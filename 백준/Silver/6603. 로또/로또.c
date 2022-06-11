#include <stdio.h>
int arr[100][14];
int visit[14] = { 0 };
int ans[6];
void dfs(int cnt, int ca)
{
	if (cnt == 6)
	{
		for (int j = 0; j < 6; j++)
			printf("%d ",ans[j]);
		printf("\n");
		return;
	}
	for (int i =1; i <= arr[ca][0] ; i++)
	{
		if (visit[i] != 1)
		{
			if (cnt > 0)
			{
				if (ans[cnt - 1] < arr[ca][i])
				{
					visit[i] = 1;
					ans[cnt] = arr[ca][i];
					dfs(cnt + 1, ca);
					visit[i] = 0;
				}
			}
			else
			{
				visit[i] = 1;
				ans[cnt] = arr[ca][i];
				dfs(cnt + 1, ca);
				visit[i] = 0;
			}
		}
	}


}
int main()
{
	int ca=0, n;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		else
			arr[ca][0] = n;
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[ca][j]);
		ca++;
	}
	for (int i = 0; i < ca; i++)
	{
		dfs(0, i);
		printf("\n");
		for (int j = 1; j <= arr[i][0]; j++)
			visit[j] = 0;
	}


	return 0;
}