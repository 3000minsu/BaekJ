#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
int n, m;
bool field[1005][1005];
bool real_visit[1005][1005] = { false };
//bool temp_visit[1005][1005] = { false };
int ans[1005][1005] = { 0 };
pair<int, int> map[1005][1005];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


void bfs(int y, int x, int c)
{
	int tx, ty, cnt=1;
	queue<pair<int, int>> q;
	queue<pair<int, int>> nu_q;
	//memset(temp_visit, false, sizeof temp_visit);
	q.emplace(y, x);
	nu_q.emplace(y, x);
	real_visit[y][x] = true;
	//temp_visit[y][x] = true;
	while (!q.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			ty = dy[i] + q.front().first;
			tx = dx[i] + q.front().second;
			if (ty >= 0 && ty < n && tx >= 0 && tx < m)
			{
				if (real_visit[ty][tx] == false && field[ty][tx] == false)
				{
					q.emplace(ty, tx);
					nu_q.emplace(ty, tx);
					real_visit[ty][tx] = true;
					//temp_visit[ty][tx] = true;
					cnt++;
				}
			}
		}
		q.pop();
	}
	
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp_visit[i][j])
			{
				map[i][j].first = c;
				map[i][j].second = cnt;
			}
		}
	}*/
	while (!nu_q.empty())
	{
		map[nu_q.front().first][nu_q.front().second].first = c;
		map[nu_q.front().first][nu_q.front().second].second = cnt;
		nu_q.pop();
	}

}


int main()
{
	int cnt = 1, ty, tx, temp = 0, c = 0;
	int ch[4] = { 0 };
	memset(map, 0, sizeof map);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &field[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (real_visit[i][j] == false &&field[i][j] == false)
			{
				bfs(i, j, cnt);
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (field[i][j])
			{
				ans[i][j] = 1;
				temp = 0;
				for (int k = 0; k < 4; k++)
				{
					c = 0;
					ty = i + dy[k];
					tx = j + dx[k];
					if (ty >= 0 && ty < n && tx >= 0 && tx < m)
					{
						if (field[ty][tx] == false)
						{
							for (int a = 0; a < temp; a++)
							{
								if (ch[a] == map[ty][tx].first)
								{
									c = 1; 
									break;
								}
							}
							if (c == 0)
							{
								ans[i][j] += map[ty][tx].second;
								ch[temp++] = map[ty][tx].first;
							}
						}
					}
				}
				ans[i][j] %= 10;
				
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}