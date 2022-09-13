#include <iostream>
#include <cstring>

using namespace std;
int pre[1005] = { 0 };
int now[1005] = { 0 };
char pre_char[1005][1005] = { 0 };
char now_char[1005][1005] = { 0 };
char a[1005];
char b[1005];
int main()
{
	int len_a, len_b, ch=0;
	scanf("%s", a);
	scanf("%s", b);
	len_a = strlen(a);
	len_b = strlen(b);
	for (int i = 0; i < len_a; i++)
	{
		if (ch)
		{
			pre[i+1] = 1;
			strncpy(pre_char[i+1], &b[0], 1);
		}
		if (a[i] == b[0])
		{
			pre[i+1] = 1;
			strncpy(pre_char[i+1], &b[0], 1);
			ch = 1;
		}
	}

	for (int i = 1; i < len_b; i++)
	{
		for (int j = 0; j < len_a; j++)
		{
			if (b[i] == a[j])
			{
				now[j+1] = pre[j] + 1;
				strncpy(now_char[j + 1], pre_char[j], pre[j]);
				now_char[j + 1][pre[j]] = a[j];
			}
			else
			{
				if (pre[j + 1] > now[j])
				{
					now[j + 1] = pre[j + 1];
					strncpy(now_char[j + 1], pre_char[j + 1], pre[j + 1]);
				}
				else
				{
					now[j + 1] = now[j];
					strncpy(now_char[j + 1], now_char[j], now[j]);
				}
			}
		}
		for (int j = 0; j <= len_a; j++)
		{
			strncpy(pre_char[j], now_char[j], now[j]);
			pre[j] = now[j];
		}
	}
	printf("%d\n", now[len_a]);
	for (int i = 0; i < now[len_a]; i++)
		printf("%c", now_char[len_a][i]);


	return 0;
}