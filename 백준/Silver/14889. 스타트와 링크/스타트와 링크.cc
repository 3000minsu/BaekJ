#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define inf 2e9
using namespace std;
int ab[20][20];
int lin[20];
int sta[20];
int n;
int mi = inf;
void find()
{
	int s = 0, l = 0;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			s += ab[lin[i]][lin[j]];
			l += ab[sta[i]][sta[j]];
		}
	}
	if (abs(l - s) < mi)
		mi = abs(l - s);
}
void dfs(int depth, int pa)
{
	if (depth == n / 2)
	{
		int a = 0, ch=0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				if (lin[j] == i)
				{
					ch = 1;
					break;
				}
			}
			if (ch == 0)
			{
				sta[a] = i;
				a++;
			}
			ch = 0;
		}
		find();
		return;
	}
	for (int i = pa; i < n; i++)
	{
		lin[depth] = i;
		dfs(depth + 1, i + 1);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> ab[i][j];
	}
	dfs(0, 1);
	cout << mi;
	return 0;
}