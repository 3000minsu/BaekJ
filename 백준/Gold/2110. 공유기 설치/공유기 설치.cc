#include <bits/stdc++.h>
using namespace std;
int house[200001];
int main()
{
	int n, c, mid, l, r, ans = -1, cnt=0, pre;
	//int mi=2000000000;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &house[i]);
	}
	sort(house, house + n);
	/*for (int i = 0; i < n - 1; i++)
	{
		if (house[i] - house[i + 1] < mi)
			mi = house[i+1] - house[i];
	}*/
	l = 1;
	r = house[n - 1];
	mid = (r + l) / 2;
	//가장 인접한 두 공유기 사이의 최대 거리
	//최소거리를 바꿔가면서 탐색(최소 mid만큼은 떨어져있어야함)
	while (r >= l)
	{
		cnt = 1;
		pre = house[0];
		for (int i = 1; i < n; i++)
		{
			if (house[i] - pre >= mid)
			{
				cnt++;
				pre = house[i];
			}
		}
		if (cnt >= c)
		{
			l = mid + 1;
			if (mid > ans)
				ans = mid;
		}
		else
			r = mid - 1;
		mid = (l + r) / 2;
	}
	printf("%d", ans);

	return 0;
}