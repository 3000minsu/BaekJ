#include <iostream>
#include <cstring>
using namespace std;
int n, k, w;
int cost[1005];
int real_cost[1005];
int to[1005][1005] = { 0 };

int cal(int des)
{
	int max = -1, temp;
	if (to[des][0] == 0)
	{
		real_cost[des] = cost[des];
		return cost[des];
	}
	for (int i = 1; i <= to[des][0]; i++)
	{
		if (real_cost[to[des][i]] == -1)
		{
			temp = cal(to[des][i]);
			if (max < temp)
				max = temp;
		}
		else
		{
			if (max < real_cost[to[des][i]])
				max = real_cost[to[des][i]];
		}
	}
	//visit[des] = true;
	return real_cost[des] = max + cost[des];
}

int main()
{
	int tc, a, b;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++)
	{
		memset(to, 0, sizeof to);
		memset(real_cost, -1, sizeof real_cost);//cost로 0을 가질수도 있으므로 -1로 초기화
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &cost[i + 1]);
		for (int i = 0; i < k; i++)
		{
			scanf("%d %d", &a, &b);
			to[b][0]++;
			to[b][to[b][0]] = a;
		}
		scanf("%d", &w);
		printf("%d\n", cal(w));
	}

	return 0;
}