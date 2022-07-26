#include <bits/stdc++.h>
#define ma 2000001
using namespace std;
map<int, int> m;
//set<pair<int, int>> s;
int ar[500001];
//set<pair<int, int>>::iterator it;
long long stree[ma] = { 0 };
long long fi(int node, int s, int e,int l, int r)
{
	if (l > e || r < s)
		return 0;
	if (l <= s && e <= r)
		return stree[node];
	int m = (s + e) / 2;
	long long lresult = fi(node * 2, s, m, l, r);
	long long rresult = fi(node * 2+1, m+1, e, l, r);
	return lresult + rresult;
}

void pu(int node, int s, int e, int idx)
{
	if (idx<s || idx>e)
		return;
	stree[node]++;
	if (s != e)
	{
		int m = (s + e) / 2;
		pu(node * 2, s, m, idx);
		pu(node * 2 + 1, m + 1, e, idx);
	}
}

int main()
{
	int n, temp, a;
	long long cnt=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		m[temp] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		ar[m[temp]] = i;
	}
	a = ar[1];
	pu(1, 1, n, a);//집어넣는 함수
	for (int i = 2; i <= n; i++)
	{
		a = ar[i];
		cnt += fi(1, 1, n, a+1, n);//a보다 큰수 찾는 함수
		pu(1, 1, n, a);//a 트리에 집어넣는 함수
	}
	printf("%lld", cnt);
	return 0;
}