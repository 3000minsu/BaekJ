#include <stdio.h>
int l, c;
char arr[15];
char ans[15];
void back(int cnt, int pa)
{
	int temp=0, temp2=0;
	if (cnt == l)
	{
		for (int i = 0; i < l; i++)
		{
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				temp++;
			else
				temp2++;
		}
		if (temp >= 1 && temp2 >= 2)
		{
			for (int i = 0; i < l; i++)
				printf("%c", ans[i]);
			printf("\n");
		}
		return;
	}
	for (int i = pa; i < c; i++)
	{
			ans[cnt] = arr[i];
			back(cnt + 1, i + 1);
	}
}
int main()
{
	int temp;
	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; i++)
		scanf(" %c", &arr[i]);
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	back(0, 0);
	return 0;
}