#include <stdio.h>
int n, k, cnt=0;
int wor[8];
int visit[8] = { 0 };
void dfs(int day,int now)
{
	if (day == n)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 0)
		{
			if (now - k + wor[i] >= 500)
			{
				visit[i] = 1;
				dfs(day + 1, now - k + wor[i]);
				visit[i] = 0;
			}
		}
	}
}
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &wor[i]);
	dfs(0, 500);
	printf("%d", cnt);
	return 0;
}