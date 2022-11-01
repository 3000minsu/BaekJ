#include <iostream>
int greet[25][2];//0는 잃는 체력, 1은 얻는 기쁨
int dp_past[102] = { 0 };//체력당 얻는 최대 기쁨 저장
int dp_now[102] = { 0 };
int main()
{
	int n, temp, max=-1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &greet[i][0]);
	for (int i = 0; i < n; i++)
		scanf("%d", &greet[i][1]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 100; j >= 1; j--)
		{
			if (j - greet[i][0] > 0 && dp_past[j - greet[i][0]]< dp_past[j]+greet[i][1])
			{
				dp_now[j - greet[i][0]] = dp_past[j] + greet[i][1];
			}
		}
		for (int j = 100; j >= 1; j--)
		{
			dp_past[j] = dp_now[j];
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (max < dp_now[i])
			max = dp_now[i];
	}
	printf("%d", max);
	return 0;
}