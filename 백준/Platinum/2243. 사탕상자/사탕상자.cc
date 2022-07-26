#include <bits/stdc++.h>
#define ma 1000000
using namespace std;
int stree[4000004];
//int arr[ma] = { 0 };
int ch;
void fi(int node, int s, int e, int rank)
{
	if (s == e)
	{
		stree[node]--;
		ch = s;
		return;
	}
	int mid = (s + e) / 2;
	if (rank <= stree[node * 2])
		fi(node * 2, s, mid, rank);
	else
		fi(node * 2 + 1, mid + 1, e, rank-stree[node*2]);
	stree[node]--;
}

void pu(int node, int s, int e, int idx, int c)
{
	if (idx<s || idx>e)
		return;
	stree[node] += c;
	if (s != e)
	{
		int mid = (s + e) / 2;
		pu(node * 2, s, mid, idx, c);
		pu(node * 2 + 1, mid + 1, e, idx, c);
	}
}

int main()
{
	int n;
	int a, b, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a == 2)
		{
			scanf("%d %d", &b, &c);
			//arr[b] += c;
			pu(1, 1, ma, b, c);//사탕 넣거나 빼는 함수
		}
		else if (a == 1)
		{
			scanf("%d", &b);
			//arr[b]--;
			fi(1, 1, ma, b);
			printf("%d\n", ch);//사탕 번호 찾고 사탕 하나 제거하고
		}
	}
	return 0;
}