#include <iostream>
#include <cstring>
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;
int n, ch = 0;
char bu[9];
char ans[10];
int visit[10] = { 0 };
void sdfs(int depth, int pre)
{
	if (depth == n + 1)
	{
		cout << ans;
		ch = 1;
		return;
	}
	if (depth == 0)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (visit[j] == 0)
			{
				visit[j] = 1;
				ans[depth] = j + 48;
				sdfs(depth + 1, j);
				if (ch == 1)
					return;
				visit[j] = 0;
			}
		}
	}
	else {
		if (bu[depth - 1] == '>')
		{
			for (int j = 0; j < pre; j++)
			{
				if (visit[j] == 0)
				{
					visit[j] = 1;
					ans[depth] = j + 48;
					sdfs(depth + 1, j);
					if (ch == 1)
						return;
					visit[j] = 0;
				}
			}
		}
		if (bu[depth - 1] == '<')
		{
			for (int j = pre + 1; j <= 9; j++)
			{
				if (visit[j] == 0)
				{
					visit[j] = 1;
					ans[depth] = j + 48;
					sdfs(depth + 1, j);
					if (ch == 1)
						return;
					visit[j] = 0;
				}
			}
		}
	}
}
void bdfs(int depth, int pre)
{
	if (depth == n + 1)
	{
		cout << ans << endl;
		ch = 1;
		return;
	}
	if (depth == 0)
	{
		for (int j = 9; j >= 0; j--)
		{
			if (visit[j] == 0)
			{
				visit[j] = 1;
				ans[depth] = j + 48;
				bdfs(depth + 1, j);
				if (ch == 1)
					return;
				visit[j] = 0;
			}
		}
	}
	else {
		if (bu[depth - 1] == '>')
		{
			for (int j = pre - 1; j >= 0; j--)
			{
				if (visit[j] == 0)
				{
					visit[j] = 1;
					ans[depth] = j + 48;
					bdfs(depth + 1, j);
					if (ch == 1)
						return;
					visit[j] = 0;
				}
			}
		}
		if (bu[depth - 1] == '<')
		{
			for (int j = 9; j > pre; j--)
			{
				if (visit[j] == 0)
				{
					visit[j] = 1;
					ans[depth] = j + 48;
					bdfs(depth + 1, j);
					if (ch == 1)
						return;
					visit[j] = 0;
				}
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> bu[i];
	bdfs(0, 0);
	memset(visit, 0, sizeof(int) * 10);
	ch = 0;
	sdfs(0, 0);
	return 0;
}