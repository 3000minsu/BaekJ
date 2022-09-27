#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int pre_fish[5][5][9] = { 0 };
int now_fish[5][5][9];
bool smell[2][5][5] = { false };
int n, m, shark_x, shark_y, cnt, max_feed, shark_idx;
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int shark_dy[5] = { 0, 0, -1, 0, 1 };
int shark_dx[5] = { 0, -1, 0, 1, 0 };

int over_ch(int y, int x)
{
	if (y <= 0 || y > 4 || x <= 0 || x > 4)
		return 0;
	else
		return 1;
}

int fish_go(int y, int x)
{
	if (over_ch(y, x) && (y != shark_y || x != shark_x) && !smell[0][x][y] && !smell[1][x][y])
		return 1;
	else
		return 0;
}

//고쳐야됨

void fish_move()
{
	int tx, ty;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			if (!pre_fish[i][j][0])
				continue;
			for (int k = 1; k < 9; k++)
			{
				if (!pre_fish[i][j][k])
					continue;
				else
				{
					tx = i + dx[k];
					ty = j + dy[k];
					if (fish_go(ty, tx))
					{
						now_fish[tx][ty][k] += pre_fish[i][j][k];
						now_fish[tx][ty][0] += pre_fish[i][j][k];
						now_fish[i][j][0] -= pre_fish[i][j][k];
						now_fish[i][j][k] -= pre_fish[i][j][k];
					}
					else
					{
						for (int a = k + 8; a >= k + 1; a--)
						{
							if (a % 9 == 0)
								continue;
							else
							{
								tx = i + dx[a % 9];
								ty = j + dy[a % 9];
								if (fish_go(ty, tx))
								{
									now_fish[tx][ty][a % 9] += pre_fish[i][j][k];
									now_fish[tx][ty][0] += pre_fish[i][j][k];
									now_fish[i][j][0] -= pre_fish[i][j][k];
									now_fish[i][j][k] -= pre_fish[i][j][k];
									break;
								}
							}
						}
					}
				}
			}
		}
	}
}

void shark_dfs(int c, int x, int y, int idx, int feed)
{
	int ty, tx, tidx, temp;
	if (c == 3)
	{
		if (feed > max_feed)
		{
			max_feed = feed;
			shark_idx = idx;
		}
		return;
	}
	for (int i = 1; i < 5; i++)
	{
		ty = y + shark_dy[i];
		tx = x + shark_dx[i];
		if (over_ch(ty, tx))
		{
			tidx = idx + (int)((int)pow(10, c) * i);
			temp = now_fish[tx][ty][0];
			now_fish[tx][ty][0] = 0;
			shark_dfs(c + 1, tx, ty, tidx, feed + temp);
			now_fish[tx][ty][0]=temp;
		}
	}
}


void shark_move()
{
	int direction;
	max_feed = -1;
	shark_dfs(0, shark_x, shark_y, 0, 0);
	for (int i = 1; i < 4; i++)
	{
		direction = shark_idx % 10;
		shark_idx /= 10;
		shark_x += shark_dx[direction];
		shark_y += shark_dy[direction];
		if (now_fish[shark_x][shark_y][0])
		{
			memset(now_fish[shark_x][shark_y], 0, sizeof(now_fish[shark_x][shark_y]));
			smell[cnt % 2][shark_x][shark_y] = true;
		}
	}
}

void reset_smell()
{
	memset(smell[cnt % 2], false, sizeof(smell[cnt % 2]));
}

void copy_fish()
{
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				now_fish[i][j][k] += pre_fish[i][j][k];
				pre_fish[i][j][k] = now_fish[i][j][k];
			}
		}
	}
}

int main()
{
	int a, b, c, ans = 0;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		pre_fish[a][b][c]++;
		pre_fish[a][b][0]++;
		now_fish[a][b][c]++;
		now_fish[a][b][0]++;
	}
	scanf("%d %d", &shark_x, &shark_y);


	for (cnt = 0; cnt < n; cnt++)
	{
		fish_move();
		if (cnt > 1)
			reset_smell();
		for (int i = 1; i < 5; i++)
		{
			for (int j = 1; j < 5; j++)
			{
				ans += now_fish[i][j][0];
			}
		}
		ans = 0;
		shark_move();
		for (int i = 1; i < 5; i++)
		{
			for (int j = 1; j < 5; j++)
			{
				ans += now_fish[i][j][0];
			}
		}
		ans = 0;
		copy_fish();
	}
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			ans += now_fish[i][j][0];
		}
	}
	printf("%d", ans);
	return 0;
}