#include <bits/stdc++.h>
using namespace std;
list<int> l;
int ans[5001];
int main()
{
	int n, k, g=0, cnt=0;
	list<int>::iterator iter;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		l.push_back(i);
	}
	iter = l.begin();
	
	while (!l.empty())
	{
		for (int i = 0; i < k-1; i++)
		{
			iter++;
			if (iter == l.end())
				iter = l.begin();
		}
		ans[cnt] = *iter;
		cnt++;
		iter = l.erase(iter);
		if (iter == l.end())
			iter = l.begin();
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