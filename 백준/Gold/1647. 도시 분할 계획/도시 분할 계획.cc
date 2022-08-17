#include <bits/stdc++.h>
using namespace std;
int n, m;
vector< pair<int, pair<int, int>>> v(1000001);
int parent[100001];
int find_root(int x) 
{
	if (parent[x] == x) 
		return x;
	return parent[x] = find_root(parent[x]);        //경로 압축
}
void union_root(int x, int y) {
	x = find_root(x);
	y = find_root(y);

	if (x != y)
		parent[y] = x;
	//else if (y < x)
		//parent[x] = y;
}

int kruskal() {
	int mx = -1, a, b, ans=0, cnt=0;
	pair<int, pair<int, int>> temp;
    for (int i = 0; i < m; i++) {
        temp = v[i];
		a = temp.second.first;
        b = temp.second.second;

        //Union-Find로 사이클이 발생하는지 확인
        if (find_root(a) == find_root(b)) 
			continue;        
        //사이클이 발생하지 않는다면 전체 길이에 더해줌
		ans += temp.first;
        union_root(a, b);
		if (temp.first > mx)
			mx = temp.first;
		cnt++;
		//n - 1개의 간선을 찾았다면 종료
        if (cnt == n - 1) 
			break;
    }
	return ans-mx;
}

int main()
{
	int a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		v[i]={ c, { a, b } };
	}
	sort(v.begin(), v.begin() + m);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	printf("%d", kruskal());
	return 0;
}