#include <stdio.h>
int visit[9] = { 0 };
int ans[8];
int n, m;
void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			ans[cnt] = i;
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	dfs(0);
	return 0;
}