#include <iostream>
#define inf 1000000
int arr[100005];
int main()
{
	int n, s, idx_f=0, idx_b=0, sum=0, cnt=1, ans=inf;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sum = arr[0];
	while (idx_b < n)
	{
		if (sum < s)
		{
			while (sum<s&&idx_b<n)
			{
				idx_b++;
				sum += arr[idx_b];
				cnt++;
			}
		}
		else
		{
			if (ans > cnt)
				ans = cnt;
			if (idx_f == idx_b)
			{
				if (idx_b < n)
				{
					idx_b++;
					idx_f++;
					sum = arr[idx_b];
					cnt = 1;
				}
			}
			else
			{
				sum -= arr[idx_f];
				idx_f++;
				cnt--;
			}
		}

	}
	if (ans == inf)
		printf("0");
	else
		printf("%d", ans);

	return 0;
}