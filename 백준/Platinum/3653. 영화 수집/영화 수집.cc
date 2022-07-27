#include <iostream>
#include <cstring>
//#define ma 1000000
#define m 100001
using namespace std;
int stree[1000000] = { 0 };
int hei[m];
void make_tree(int node, int s, int e, int size)
{
	if (s > size)
		return;
	if (s == e)
	{
		stree[node] = 1;
		return;
	}
	int mid = (s + e) / 2;
	make_tree(node * 2, s, mid, size);
	make_tree(node * 2 + 1, mid + 1, e, size);
	stree[node] = stree[node * 2] + stree[node * 2 + 1];
}

int cal(int node, int s, int e, int l, int r)
{
	if (e<l || s>r)
		return 0;
	if (l <= s && r >= e)
		return stree[node];
	int mid = (s + e) / 2;
	int l_result = cal(node * 2, s, mid, l, r);
	int r_result = cal(node * 2+1, mid+1, e, l, r);
	return l_result + r_result;
}

void rm(int node, int s, int e, int he)
{
	if (s > he || e < he)
		return;
	stree[node]--;
	if (s != e)
	{
		int mid = (s + e) / 2;
		rm(node * 2, s, mid, he);
		rm(node * 2 + 1, mid + 1, e, he);
	}
}

void add_new(int node, int s, int e, int max_height)
{
	if (s > max_height || e < max_height)
		return;
	stree[node]++;
	if (s != e)
	{
		int mid = (s + e) / 2;
		add_new(node * 2, s, mid, max_height);
		add_new(node * 2 + 1, mid + 1, e, max_height);
	}
}

int main()
{
	int T, a, temp, n;
	int max_height;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%d %d", &n, &a);
		temp = n;
		max_height = n;
		for (int j = 1; j <= n; j++)
		{
			hei[j] = temp;
			temp--;
		}
		make_tree(1, 1, n+m, n);
		for (int i = 0; i < a; i++)
		{
			scanf("%d", &temp);
			printf("%d ", cal(1, 1, n + m, hei[temp] + 1, max_height));
			rm(1, 1, n + m, hei[temp]);
			hei[temp] = ++max_height;
			add_new(1, 1, n + m, max_height);
			//위에 몇개있는지 계산하고
			//찾는 값에 범위에 속하는 node들 다 1씩 감소
			//새로 max_height에 1추가
		}
		printf("\n");
		memset(stree, 0, sizeof(stree));
	}



	return 0;
}