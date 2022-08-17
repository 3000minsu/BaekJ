#include <bits/stdc++.h>
using namespace std;
int want[100002];
int vi[100002] = { 0 };
bool team[100002] = { false };
int cnt = 0;
void dfs(int x)
{
	if (vi[x] == -1 || team[x] == true)
		return;
	if(vi[x]==0)
		vi[x] = 1;
	else if(vi[x]==1)
	{
		team[x] = true;
		cnt++;
	}
	
	dfs(want[x]);
	vi[x] = -1;
}
int main()
{
	int tc, n;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &want[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (vi[i]==0)
			{
				dfs(i);
			}
		}
		printf("%d\n", n-cnt);
		cnt = 0;
		memset(team, false, sizeof team);
		memset(vi, 0, sizeof vi);
	}
	return 0;
}