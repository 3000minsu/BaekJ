#include <bits/stdc++.h>
using namespace std;
long long line[10001];
int main()
{
	long long k, n, l, r=-1, mid, cnt=0, ans=1;
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &line[i]);
		if (line[i] > r)
			r = line[i];
	}
	l = 0;
	mid = (l + r) / 2;
	while (r >= l&&mid>0)
	{
		cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += line[i] / mid;

		if (cnt >= n)
		{
			l = mid+1;
			if (mid >= ans)
				ans = mid;
		}
		else
			r = mid-1;
		mid = (r + l) / 2;
	}
	printf("%d", ans);
	return 0;
}