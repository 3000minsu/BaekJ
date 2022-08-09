#include <bits/stdc++.h>
using namespace std;
int arr[100001][3];
int now[3][2];//0에 최대, 1에 최소
int pre[3][2];
int main()
{
	int n, mn, mx;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	if (n == 1)//1일때예외
	{
		mn = min({ arr[0][0], arr[0][1], arr[0][2] });
		mx = max({ arr[0][0], arr[0][1], arr[0][2] });

		printf("%d %d", mx, mn);
		return 0;
	}

	for (int i = 0; i < 3; i++)
	{
		pre[i][0] = arr[0][i];
		pre[i][1] = arr[0][i];
	}

	for (int i=1; i<n; i++)
	{
		now[0][0] = max(pre[0][0], pre[1][0]) + arr[i][0];
		now[0][1] = min(pre[0][1], pre[1][1]) + arr[i][0];
		now[2][0] = max(pre[1][0], pre[2][0]) + arr[i][2];
		now[2][1] = min(pre[1][1], pre[2][1]) + arr[i][2];

		now[1][0] = max({ pre[0][0], pre[1][0], pre[2][0] }) + arr[i][1];
		now[1][1] = min({ pre[0][1], pre[1][1], pre[2][1] }) + arr[i][1];

		for (int j = 0; j < 3; j++)
		{
			pre[j][0] = now[j][0];
			pre[j][1] = now[j][1];
		}
	}
	mn = min({ now[0][1], now[1][1], now[2][1] });
	mx = max({ now[0][0], now[1][0], now[2][0] });

	printf("%d %d", mx, mn);
	return 0;
}