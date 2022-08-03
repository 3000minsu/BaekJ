#include <bits/stdc++.h>
using namespace std;
int tree[1000001];
int main()
{
	int n, m, mid, l, r=-1;
	long long cnt=0, ans=-1;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tree[i]);
		if (tree[i] > r)
			r = tree[i];
	}
	l = 0;
	mid = (r+l) / 2;

	while (r >= l)
	{
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if(tree[i]-mid>0)
				cnt += tree[i] - mid;
		}
		if (cnt >= m)
		{
			l = mid + 1;
			if (mid > ans) 
				ans = mid;
		}
		else
			r = mid - 1;
		mid = (l + r) / 2;
	}
	printf("%lld", ans);

	return 0;
}