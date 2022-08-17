#include <bits/stdc++.h>
using namespace std;
char a[22][22];
int r, c, ans=-1;
bool vi[22][22] = { false };
bool a_vi[26] = { false };
int dx[4] = { 0, 1,0, -1 };	
int dy[4] = { -1, 0,1, 0 };
void dfs(int y, int x, int cnt)
{
	int tx, ty;
	vi[y][x] = true;
	a_vi[a[y][x] - 'A'] = true;
	if (cnt > ans)
		ans = cnt;

	for (int i = 0; i < 4; i++)
	{
		ty = y + dy[i];
		tx = x + dx[i];
		if (tx >= 0 && tx < c && ty >= 0 && ty < r&&!vi[ty][tx])
		{
			if (!a_vi[a[ty][tx] - 'A'])
			{
				dfs(ty, tx, cnt + 1);
				vi[ty][tx] = false;
				a_vi[a[ty][tx] - 'A'] = false;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
	{
		scanf("%s", a[i]);
	}
	dfs(0, 0, 1);
	printf("%d", ans);
}
