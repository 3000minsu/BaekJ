#include <stdio.h>
int n;
int now[9][2];
int temp = 0, max = 0;;
void dfs(int hit)//hit은 지금 집은 계란의 인덱스
{
	int ch = 0;
	if (hit == n+1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (now[i][0] <= 0)
				temp++;
		}
		if (temp > max)
			max = temp;
		temp = 0;
		return;
	}
	if (now[hit][0] <= 0)//집은 계란이 이미 깨져있을때
	{
		dfs(hit + 1);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i == hit)
			continue;
		if (now[i][0]>0)
		{
			ch = 1;
			now[i][0] -= now[hit][1];
			now[hit][0] -= now[i][1];
			dfs(hit + 1);
			now[i][0] += now[hit][1];//원상복구 시켜야지
			now[hit][0] += now[i][1];//     "
		}
	}
	if (ch == 0)//자신빼고 다 깨져서 칠 수 있는 계란이 없어
		dfs(hit + 1);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &now[i][0], &now[i][1]);
		
	}
	dfs(1);
	printf("%d", max);
	return 0;
}