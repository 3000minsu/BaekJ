#include <iostream>
#define inf 100000
int arr[1005][3];
int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int ans = inf;
	int n;
	int pre[3];
	int now[3];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	for (int i = 0; i < 3; i++)//첫번째 집 색 3가지 경우 나눠서
	{
		for (int j = 0; j < 3; j++)//두번째 집 초기값 설정
		{
			if (i == j)
				pre[j] = inf;
			else
				pre[j] = arr[1][j]+arr[0][i];
		}
		for (int j = 2; j < n; j++)
		{
			now[0] = min(pre[1], pre[2]) + arr[j][0];
			now[1] = min(pre[0], pre[2]) + arr[j][1];
			now[2] = min(pre[1], pre[0]) + arr[j][2];
			for (int k = 0; k < 3; k++)
				pre[k] = now[k];
		}
		for (int j = 0; j < 3; j++)
		{
			if (j != i)
			{
				ans = min(ans, now[j]);
			}
		}
	}
	printf("%d", ans);
	return 0;
}