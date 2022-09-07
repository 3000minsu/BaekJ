#include <iostream>
#include <utility>
using namespace std;
bool s[9][10]={false};
bool g[9][10] = { false };
bool sq[9][10] = { false };
int field[9][9];
pair<int, int> zeros[82];
int nzero = 0;
bool ch = false;
int square_ch(int y, int x)
{
	return (y / 3 )*3 + (x /3);
}

void dfs(int cnt)
{
	int y, x, nsq;
	if (cnt == nzero)
	{
		ch = true;
		return;
	}
	y = zeros[cnt].first;
	x = zeros[cnt].second;
	nsq = square_ch(y, x);
	for (int i = 1; i <= 9; i++)
	{
		if (g[y][i])
			continue;
		if (s[x][i])
			continue;
		if (sq[nsq][i])
			continue;
		g[y][i] = true;
		s[x][i]=true;
		sq[nsq][i] = true;
	
		field[y][x] = i;
		dfs(cnt + 1);
		//field[y][x] = 0;
		if (ch)
			return;
		g[y][i] = false;
		s[x][i] = false;
		sq[nsq][i] = false;
	}
}

int main()
{
	int nsq;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%1d", &field[i][j]);
			if (field[i][j] != 0)
			{
				g[i][field[i][j]] = true;
				s[j][field[i][j]] = true;
				nsq = square_ch(i, j);
				sq[nsq][field[i][j]] = true;
			}
			else
			{
				zeros[nzero].first = i;
				zeros[nzero++].second = j;
			}
		}
	}
	dfs(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d", field[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}