#include <bits/stdc++.h>
using namespace std;
int area[10001];
int main()
{
	int n, m, mid, l, r = -1, ans=-1;
	long long cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &area[i]);
		if (area[i] > r)
			r = area[i];
	}
	scanf("%d", &m);
	l = 0;
	mid = (r + l) / 2;

	while (r >= l)
	{
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (area[i] > mid)
				cnt += mid;
			else
				cnt += area[i];
		}
		if (cnt <= m)
		{
			l = mid + 1;
			if (mid > ans)
				ans = mid;
		}
		else
			r = mid -1;
		mid = (l + r) / 2;
	}
	printf("%d", ans);

	return 0;
}