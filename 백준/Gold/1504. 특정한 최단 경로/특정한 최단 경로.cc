#include <bits/stdc++.h>
#define inf 2e9+10
using namespace std;
int dis[801];
int graph[801][801] = { 0 };
//bool visit[801] = { false };
int n, e, v1, v2;
int dij(int st, int ed)
{
	int ch = 0;
	pair<int, int> temp;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//memset(visit, false, sizeof visit);
	for (int i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	dis[st] = 0;
	pq.push({ 0, st });
	//temp = pq.top();
	while (!pq.empty())
	{
		temp = pq.top();
		pq.pop();
		/*if (dis[temp.second] < temp.first)
			continue;
		if (temp.second == ed)
		{
			ch = 1;
			break;
		}*/
		for (int i = 1; i <= n; i++)
		{
			if (dis[temp.second] + graph[temp.second][i] < dis[i])
			{
				dis[i] = dis[temp.second] + graph[temp.second][i];
				pq.push({ dis[i], i });
			}
		}
	} 
	//if (ch == 1)
		return dis[ed];
	//else
		//return -1;
}
int main()
{
	int a, b, c, ans1=0, ans2=0, temp, s;
	scanf("%d %d", &n, &e);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
				graph[i][j] = inf;
		}
	}
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[b][a] = c;
	}
	scanf("%d %d", &v1, &v2);
	int go1[4] = { 1, v1, v2, n };
	int go2[4] = { 1, v2, v1, n };
	for (int i = 0; i < 3; i++)
	{
		temp = dij(go1[i], go1[i + 1]);
		if (i == 1)
		{
			s = temp;
		}
		if (temp == inf)
		{
			ans1 = inf;
			break;
		}
		else
			ans1 += temp;
	}
	for (int i = 0; i < 3; i++)
	{
		if (i != 1)
			temp = dij(go2[i], go2[i + 1]);
		else
			temp = s;
		if (temp == inf)
		{
			ans2 = inf;
			break;
		}
		else
			ans2 += temp;
	}
	if (ans1 == inf && ans2 == inf)
		printf("-1");
	else
		printf("%d", min(ans1, ans2));
	return 0;
}