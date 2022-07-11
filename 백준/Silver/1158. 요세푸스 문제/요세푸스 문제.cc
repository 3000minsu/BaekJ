#include <bits/stdc++.h>
using namespace std;
bool ch[5001] = { false };
int ans[5001];
int main()
{
	int n, k, g=0, no=1, cnt=0;
	scanf("%d %d", &n, &k);
	
	while (1)
	{
		if (no > n)
			no = 1;
		if (no <= n && !ch[no])
			g++;
		if (g == k)
		{
			ch[no] = true;
			ans[cnt] = no;
			cnt++;
			g = 0;
		}
		if (cnt == n)
			break;
		no++;
	}
	printf("<");
	for (int i = 0; i < cnt; i++)
	{
		if (i != cnt - 1)
			printf("%d, ", ans[i]);
		else
			printf("%d>", ans[i]);
	}
	return 0;
}