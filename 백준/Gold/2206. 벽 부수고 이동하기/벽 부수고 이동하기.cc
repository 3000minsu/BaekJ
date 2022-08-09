#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int n, m;
bool graph[1001][1001];
bool visit[1001][1001][2];
//bool visit[1001][1001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int bfs()
{
	int ty, tx, y, x, cnt;
	bool c;
	memset(visit, false, sizeof visit);
	queue<tuple<int, int, int, bool>> q;
	q.push({ 0, 0, 1, true });
	visit[0][0][0] = true;
	visit[0][0][1] = true;
	//visit[0][0] = true;
	while (!q.empty())
	{
		y = get<0>(q.front());
		x = get<1>(q.front());
		cnt = get<2>(q.front());
		c = get<3>(q.front());
		if (y == n - 1 && x == m - 1)
		{
			//ch = 1;
			return cnt;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			ty = y + dy[i];
			tx = x + dx[i];
			if (tx >= 0 && tx < m && ty >= 0 && ty < n)
			{
				if (c && graph[ty][tx] == 1)
				{
					q.push({ ty, tx, cnt+1, false });
				}
				if (graph[ty][tx] == 0)
				{
					if (!c && !visit[ty][tx][1])
					{
						q.push({ ty, tx, cnt + 1, c });
						visit[ty][tx][1] = true;
					}
					else if(c&&!visit[ty][tx][0])
					{
						q.push({ ty, tx, cnt + 1, c });
						visit[ty][tx][0] = true;
					}
				}

			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &graph[i][j]);
	}
	printf("%d", bfs());

	return 0;
}