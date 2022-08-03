#include <bits/stdc++.h>
#include <unordered_map>
#define inf 2000000000
using namespace std;
vector<unordered_map<int,int>> v;
int vi[10002] = { 0 };
int n, m;
int st, ed, ch=0;
void dfs(int p, int mi)
{
	if (p == ed)
	{
		ch = 1;
		return;
	}
	vi[p] = 1;
	for (auto it = v[p].begin(); it != v[p].end(); it++)
	{
		if (vi[it->first] == 0&& it->second>=mi)
		{
			dfs(it->first, mi);
		}
		if (ch == 1)
			return;
	}
}

int main()
{
	int a, b, c, l=inf, r=-1, mid, ans=-1;
	scanf("%d %d", &n, &m);
	v.resize(n+1);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (c > r)
			r = c;
		if (c < l)
			l = c;
		if (v[a].find(b) == v[a].end())
		{
			v[a].insert({ b, c });
			v[b].insert({ a, c });
		}
		else
		{
			if (v[a][b] < c)
			{
				v[a][b] = c;
				v[b][a] = c;
			}
		}
	}
	scanf("%d %d", &st, &ed);
	mid = (l + r) / 2;
	while (r >= l)
	{
		dfs(st, mid);
		if (ch==1)
		{
			l = mid + 1;
			if (mid > ans)
				ans = mid;
		}
		else
			r = mid - 1;
		mid = (r + l) / 2;
		ch = 0;
		memset(vi, 0, sizeof(vi));
	}
	
	
	printf("%d", ans);

	return 0;
}