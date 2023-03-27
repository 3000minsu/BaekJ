#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
int sero, garo;
int map[102][102];
int visit[102][102] = { 0 };
int cheese_cnt=0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;

void input()
{
	scanf("%d %d", &sero, &garo);
	for (int i = 0; i < sero; i++)
	{
		for (int j = 0; j < garo; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				cheese_cnt++;
		}
	}
}
void cheese_bfs()
{
	int tx, ty;
	pair<int, int> current;
	memset(visit, 0, sizeof(visit));
	q = queue<pair<int, int>>();
	q.emplace(0, 0);
	visit[0][0] = 1;
	while (!q.empty())
	{
		current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			ty = current.first + dy[i];
			tx = current.second + dx[i];
			if (ty >= 0 && ty < sero && tx >= 0 && tx < garo && visit[ty][tx] == 0)
			{
				if (map[ty][tx] == 1)
				{
					cheese_cnt--;
					map[ty][tx] = 0;
				}
				else
				{
					q.emplace(ty, tx);
				}
				visit[ty][tx] = 1;
			}
		}
	}
}

void solve()
{
	int hour = 0, pre_cheese= cheese_cnt;
	while (cheese_cnt > 0)
	{
		pre_cheese = cheese_cnt;
		cheese_bfs();
		hour++;
	}
	printf("%d\n%d", hour, pre_cheese);
}
int main()
{
	input();
	solve();
	return 0;
}