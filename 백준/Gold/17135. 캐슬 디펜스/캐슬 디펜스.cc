#include <iostream>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;
int  garo, sero, range, total_enemy=0, kill, enemy_alive, answer=-1;
int map[16][16];
int original_map[16][16];
int visit[16][16] = { 0 };
int archer[16] = { 0 };
int archer_position[3];//궁수 x좌표 저장
int dx[3] = { -1, 0, 1 };
int dy[3] = { 0, -1, 0 };
queue<pair<pair<int, int>, int>> q;//두번째 int는 range 체크용

void input()
{
	scanf("%d %d %d", &sero, &garo, &range);
	for (int i = 0; i < sero; i++)
	{
		for (int j = 0; j < garo; j++)
		{
			scanf("%d", &original_map[i][j]);
			if (original_map[i][j] == 1)
				total_enemy++;
		}
	}
}

void archer_bfs()
{
	int tx, ty, current_range, ch;
	pair<int, int> current;
	for (int i = 0; i < 3; i++)
	{
		memset(visit, 0, sizeof(visit));
		q = queue<pair<pair<int, int>, int>>();
		q.emplace(make_pair(sero - 1, archer_position[i]), 1);
		visit[sero-1][archer_position[i]] = 1;
		
		current = q.front().first;
		if (map[current.first][current.second] != 0)
		{
			if (map[current.first][current.second] == 1)
			{
				enemy_alive--;
				kill++;
			}
			map[current.first][current.second] = -1;
			continue;
		}
		ch = 0;
		while (!q.empty())
		{
			current = q.front().first;
			current_range = q.front().second;
			if (current_range == range)
				break;
			q.pop();
			for (int i = 0; i < 3; i++)
			{
				ty = current.first + dy[i];
				tx = current.second + dx[i];
				if (ty >= 0 && ty < sero && tx >= 0 && tx < garo && visit[ty][tx] == 0)
				{
					if (map[ty][tx] != 0)
					{
						if (map[ty][tx] == 1)
						{
							enemy_alive--;
							kill++;
						}
						map[ty][tx] = -1;
						ch = 1;
						break;
					}
					else
					{
						q.emplace(make_pair(ty, tx), current_range+1);
					}
					visit[ty][tx] = 1;
				}
			}
			if (ch == 1)
				break;
		}
	}

}

void enemy_move()
{
	for (int i = sero - 1; i >= 0; i--)
	{
		for (int j = 0; j < garo; j++)
		{
			if (i == sero - 1 && map[i][j] == 1)
				enemy_alive--;
			if (i != 0)
			{
				if (map[i - 1][j] == -1)
					map[i][j] = 0;
				else
					map[i][j] = map[i - 1][j];
			}
			else
				map[i][j] = 0;
		}
	}
}

void simul()
{
	enemy_alive = total_enemy;
	kill = 0;
	for (int i = 0; i < sero; i++)
	{
		for (int j = 0; j < garo; j++)
		{
			map[i][j] = original_map[i][j];
		}
	}
	while (enemy_alive > 0)
	{
		archer_bfs();
		enemy_move();
	}
}

void brute_force(int cnt, int start_pt)
{
	if (cnt == 3)
	{
		simul();
		if (kill > answer)
			answer = kill;
		return;
	}
	else
	{
		for (int i = start_pt; i < garo; i++)
		{
			if (archer[i] == 0)
			{
				archer[i] = 1;
				archer_position[cnt] = i;
				brute_force(cnt + 1, i + 1);
				archer[i] = 0;
			}
		}
	}
}
void solve()
{
	brute_force(0, 0);
	printf("%d", answer);
}
int main()
{
	input();
	solve();
	return 0;
}