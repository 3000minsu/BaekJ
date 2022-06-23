#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;
int n;
int ch = 0;
char arr[80];
int check(int depth)
{
	char temp[80];
	int c = 0;
	for (int i = 2; i <= depth/2; i++)
	{
		strncpy(temp, &arr[depth - i], i);
		int j = depth - i * 2;
		if (!strncmp(temp, &arr[j], i))
			{
				c = 1;
				break;
			}
	}
	if (c == 1)
		return 0;
	else
		return 1;
}
void dfs(int depth, int pa)
{
	if (depth != 0)
	{
		if (!check(depth))
			return;
	}
	if (depth == n)
	{
		cout << arr;
		ch = 1;
		return;
	}
	for (int i = 1; i <= 3; i++)
	{
		if (i != pa)
		{
			arr[depth] = i + 48;
			dfs(depth + 1, i);
		}
		if (ch == 1)
			return;
	}
}
int main()
{
	cin>>n;
	dfs(0, -1);
	return 0;
}