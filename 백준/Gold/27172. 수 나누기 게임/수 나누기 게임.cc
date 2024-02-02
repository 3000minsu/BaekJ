#include <iostream>
#include <queue>
using namespace std;
vector<int> in_list;
bool is_exist[1000002] = {false, };
int score_list[1000002] = {0, };
int total_num;
void input()
{
	int temp;
	scanf("%d", &total_num);
	for (int i = 0; i < total_num; i++)
	{
		scanf("%d", &temp);
		is_exist[temp] = true;
		in_list.push_back(temp);
	}
}

void compute()
{
	int cur;
	//while (!in_list.empty())
	for(auto it = in_list.begin(); it != in_list.end(); it++ )
	{
		cur = *it;
		for (int i = cur * 2; i < 1000001; i += cur)
		{
			if (is_exist[i])
			{
				score_list[i]--;
				score_list[cur]++;
			}
		}
	}
}

void output()
{
	int cur;
	for (auto it = in_list.begin(); it != in_list.end(); it++)
	{
		cur = *it;
		printf("%d ", score_list[cur]);
	}
}

int main()
{
	input();
	compute();
	output();
	return 0;
}