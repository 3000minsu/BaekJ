#include <bits/stdc++.h>
using namespace std;
long long n, p, q;
map<long long, long long> m;
long long rec(long long i)
{
	map<long long, long long>::iterator iter1;
	map<long long, long long>::iterator iter2;
	iter1 = m.find(i / p);
	iter2 = m.find(i / q);

	if (iter1 != m.end() && iter2 != m.end())
		return m[i] = iter1->second + iter2->second;
	else if (iter1 == m.end() && iter2 != m.end())
		return m[i] = rec(i / p) + iter2->second;
	else if (iter1 != m.end() && iter2 == m.end())
		return m[i] = rec(i / q) + iter1->second;
	else
		return m[i] = rec(i / p) + rec(i / q);
}
int main()
{
	long long ans;
	scanf("%lld %lld %lld", &n, &p, &q);
	m[0] = 1;
	if (n == 0)
		ans = 1;
	else
		ans=rec(n);
	printf("%lld", ans);
	return 0;
}