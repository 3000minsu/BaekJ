#include <stdio.h>
#include <stdlib.h>
//수열이니까 첫째항이 중요 첫째항을 박아버리고 검사하자
//마지막꺼부터 검사할거야 
//배열에 뒤에 있는 수 중에서 검사하는 수보다 크면서 가장 가까운 수의 최대 길이에 1을 더해준다
//검사하는 수보다 큰 수가 없으면 그수의 최대길이는 1로 해준다
int incseq(int* arr, int si)
{
	int max = 1;
	int bi = 0;
	int temp=0;
	int* len;
	len = (int*)calloc(si, sizeof(int));
	len[si - 1] = 1;
	for (int i = si - 1; i >= 0; i--)
	{
		for (int k = i; k < si; k++)
		{
			if (arr[k] > arr[i])
			{
				if (len[k] + 1 > len[i])
					len[i] = len[k] + 1;
				if (max < len[i])
					max = len[i];
				bi = 1;
			}
		}
		if (bi == 0)
			len[i] = 1;
		bi = 0;
	}
	free(len);
	return max;
}

int main()
{
	int* arr;
	int si;
	scanf("%d", &si);
	arr = (int*)calloc(si, sizeof(int));
	for (int i = 0; i < si; i++)
		scanf(" %d", &arr[i]);
	printf("%d", incseq(arr, si));
	free(arr);
}