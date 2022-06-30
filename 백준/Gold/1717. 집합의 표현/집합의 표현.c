#include <stdio.h>
int parent[1000001];
int ans[100000];
int n, m, an=0;
int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	else
		parent[y] = x;
}
void check(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		ans[an] = 1;
	else
		ans[an] = 0;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
			merge(b, c);
		else
		{
			check(b, c);
			an++;
		}
	}
	for (int i = 0; i < an; i++)
	{
		if (ans[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}