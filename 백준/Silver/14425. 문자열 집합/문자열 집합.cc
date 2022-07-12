#include <bits/stdc++.h>
#define max_table 100003
#define max_key 501
using namespace std;
char str[max_table][max_key] = { 0 };
int gkey(char* key)
{
	int i = 0, k=0;
	long long h=5381;
	while (key[i] != '\0')
	{
		h = (((h << 5) + h) + key[i]) % max_table;
		i++;
	}
	return h;
}
void add(char* key)//충돌나겠어 설마..? ㅋㅋ 나네
{
	long long h;
	h = gkey(key);
	while (str[h][0] != 0)
	{
		h++;
		if (h == max_table)
			h = 0;
	}
	strcpy(str[h], key);
	//printf("%d\n", h);
}
int find(char* key)
{
	long long h;
	int cnt = max_table;
	h = gkey(key);
	//printf("%d\n", h);
	while (str[h][0] != 0&&cnt--)
	{
		if (!strcmp(key, str[h]))
			return 1;
		h++;
		if (h == max_table)
			h = 0;
	}
	return 0;
}
int main()
{
	int n, m, a, cnt=0;
	char temp[max_key];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		add(temp);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%s", temp);
		a=find(temp);
		if (a)
			cnt++;
	}
	printf("%d", cnt);

	return 0;
}