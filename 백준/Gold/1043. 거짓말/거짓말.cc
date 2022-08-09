#include <bits/stdc++.h>
using namespace std;
bool true_people[52] = { false };
bool true_party[52] = { false };
int party[52][52];
//int true_party[52];
//int true_party_cnt = 0;
int main()
{
	int  n, m, t, temp, ans=0, ch=0;
	scanf("%d %d", &n, &m);
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &temp);
		true_people[temp] = true;
	}
	for (int i = 0; i < m; i++)
	{
		ch = 0;
		scanf("%d", &party[i][0]);
		for (int j = 1; j <= party[i][0]; j++)
		{
			scanf("%d", &party[i][j]);
			if (true_people[party[i][j]])
			{
				true_party[i] = true;
				ch = 1;
			}
		}
		if (ch == 1)
		{
			for (int j = 1; j <= party[i][0]; j++)
				true_people[party[i][j]] = true;
		}
	}

	for (int k = 0; k < m; k++)
	{
		for (int i = 0; i < m; i++)//한번 더 체크
		{
			ch = 0;
			for (int j = 1; j <= party[i][0]; j++)
			{
				if (true_people[party[i][j]])
				{
					true_party[i] = true;
					ch = 1;
				}
			}
			if (ch == 1)
			{
				for (int j = 1; j <= party[i][0]; j++)
					true_people[party[i][j]] = true;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (!true_party[i])
			ans++;
	}

	printf("%d", ans);


	return 0;
}