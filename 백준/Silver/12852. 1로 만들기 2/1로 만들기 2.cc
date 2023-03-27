#include <iostream>
#define max 5000002
int target;
int number[max][2] = { 0 };//0은 횟수, 1은 전에 수
int main()
{
	int temp;
	scanf("%d", &target);
	number[1][0] = 0;
	number[1][0] = 1;
	for (int i = 1; i < target; i++)
	{
		if (number[i * 2][0] == 0)
		{
			number[i * 2][0] = number[i][0] + 1;
			number[i * 2][1] = i;
		}
		else
		{
			if (number[i * 2][0] > number[i][0] + 1)
			{
				number[i * 2][0] = number[i][0] + 1;
				number[i * 2][1] = i;
			}
		}

		if (number[i * 3][0] == 0)
		{
			number[i * 3][0] = number[i][0] + 1;
			number[i * 3][1] = i;
		}
		else
		{
			if (number[i * 3][0] > number[i][0] + 1)
			{
				number[i * 3][0] = number[i][0] + 1;
				number[i * 3][1] = i;
			}
		}

		if (number[i + 1][0] == 0)
		{
			number[i + 1][0] = number[i][0] + 1;
			number[i + 1][1] = i;
		}
		else
		{
			if (number[i + 1][0] > number[i][0] + 1)
			{
				number[i + 1][0] = number[i][0] + 1;
				number[i + 1][1] = i;
			}
		}
	}

	printf("%d\n", number[target][0]-1);
	temp = target;
	while (temp != 1)
	{
		printf("%d ", temp);
		temp = number[temp][1];
	}
	printf("1");
	return 0;
}