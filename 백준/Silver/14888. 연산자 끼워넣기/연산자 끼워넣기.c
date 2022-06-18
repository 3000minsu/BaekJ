#include <stdio.h>
#define inf 1000000000
int n;
int arr[11];
int add, sub, mul, div;
int max = -inf, min = inf, ans;
void back(int cnt)
{
	int temp;
	if (cnt == n)
	{
		if (ans > max)
			max = ans;
		if (ans < min)
			min = ans;
		return;
	}
	if (add > 0)
	{
		ans += arr[cnt];
		add--;
		back(cnt + 1);
		add++;
		ans -= arr[cnt];
	}
	if (sub > 0)
	{
		ans -= arr[cnt];
		sub--;
		back(cnt + 1);
		sub++;
		ans += arr[cnt];
	}
	if (mul > 0)
	{
		ans *= arr[cnt];
		mul--;
		back(cnt + 1);
		mul++;
		ans /= arr[cnt];
	}
	if (div > 0)
	{
		temp = ans % arr[cnt];
		ans /= arr[cnt];
		div--;
		back(cnt + 1);
		div++;
		ans = ans*arr[cnt]+temp;
	}

}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d %d %d %d", &add, &sub, &mul, &div);
	ans = arr[0];
	back(1);
	printf("%d\n%d", max, min);
	return 0;
}