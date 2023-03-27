#include <iostream>
#include <list>
#include <utility>
using namespace std;

int field_size, apple_cnt, shift_cnt;
int apples[105][105] = { 0 };
int snake_body[105][105] = { 0 };
int shift_info[105][2];
list<pair<int, int>> snake;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void input()
{
	char temp;
	int y, x;
	scanf("%d", &field_size);
	scanf("%d", &apple_cnt);
	for (int i = 0; i < apple_cnt; i++)
	{
		scanf("%d %d", &y, &x);
		apples[y - 1][x - 1] = 1;
	}
	scanf("%d", &shift_cnt);
	for (int i = 0; i < shift_cnt; i++)
	{
		scanf("%d %c", &shift_info[i][0], &temp);
		if (temp == 'D')
			shift_info[i][1] = 1;//오른쪽 회전
		else
			shift_info[i][1] = -1;//왼쪽회전
	}
}

int terminate_check(int y, int x)
{
	//list<pair<int, int>>::iterator it;
	if (y < 0 || y >= field_size || x < 0 || x >= field_size || snake_body[y][x] == 1)
		return 1;
	else
		return 0;

}

void solve()
{
	int sec = 0, cur_direc = 0, ch = 0, x, y, shift_idx = 0;
	pair<int, int> del;
	snake.push_front(make_pair(0,0));//좌측 상단 시작
	snake_body[0][0] = 1;
	while (sec < 10200)
	{
		if (shift_idx < shift_cnt && sec == shift_info[shift_idx][0])//방향 전환
		{
			cur_direc += shift_info[shift_idx][1];
			if (cur_direc > 3)
				cur_direc = 0;
			else if (cur_direc < 0)
				cur_direc = 3;
			shift_idx++;
		}

		sec++;

		y = snake.front().first + dy[cur_direc];//다음 대가리 위치
		x = snake.front().second + dx[cur_direc];
		ch = terminate_check(y, x);//종료 체크
		if (ch == 1)
			break;
		snake.push_front(make_pair( y, x ));
		snake_body[y][x] = 1;

		if (apples[y][x] == 1)//사과 먹음
			apples[y][x] = 0;
		else//못먹음
		{
			del = snake.back();
			snake.pop_back();//꼬리 삭제
			snake_body[del.first][del.second] = 0;
			//printf("%d %d\n", del.first, del.second);
		}

	}
	printf("%d", sec);
}

int main()
{
	input();
	solve();
	return 0;
}