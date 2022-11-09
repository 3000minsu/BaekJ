#include <iostream>
#include <vector>
#include <queue>
#define max 1000001
using namespace std;
vector<int> child[max];
vector<int> edge[max];
int dp[max][2] = { 0 };
bool visit[max] = { false };
int n;
int min(int a, int b)
{
	return a < b ? a : b;
}

void make_tree(int x)
{
	visit[x] = true;
	for (int i = 0; i < edge[x].size(); i++)
	{
		if (!visit[edge[x][i]])
		{
			child[x].push_back(edge[x][i]);
			visit[x] = true;
			make_tree(edge[x][i]);
		}
	}
}


void dfs(int x)
{
	dp[x][0] = 1;
	if (child[x].size() == 0)
	{
		return;
	}
	for (int j = 0; j < child[x].size(); j++)
	{
		dfs(child[x][j]);
	}
	for (int j = 0; j < child[x].size(); j++)
	{
		dp[x][0] += min(dp[child[x][j]][0], dp[child[x][j]][1]);
		dp[x][1] += dp[child[x][j]][0];
	}
	return;
}

int main()
{
	int a, b;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	make_tree(1);
	dfs(1);
	printf("%d", min(dp[1][0], dp[1][1]));

	return 0;
}