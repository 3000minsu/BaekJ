#include <bits/stdc++.h>
#define ma 1000000001
using namespace std;
vector<pair<int, int>> SegmentTree;
int Arr[100000];
pair<int,int> Make_SegmentTree(int Node, int Start, int End)
{
	if (Start == End)
	{
		SegmentTree[Node].first = Arr[Start];
		SegmentTree[Node].second = Arr[Start];
		return SegmentTree[Node];
	}
	int Mid = (Start + End) / 2;
	pair<int, int> Left_Result = Make_SegmentTree(Node * 2, Start, Mid);
	pair<int, int> Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);
	SegmentTree[Node].first = Left_Result.first > Right_Result.first ? Left_Result.first : Right_Result.first;
	SegmentTree[Node].second = Left_Result.second < Right_Result.second ? Left_Result.second : Right_Result.second;
	return SegmentTree[Node];
}

void cmp(int Node, int Start, int End, int Left, int Right, pair<int,int> *res)
{
	if (Left > End || Right < Start)
	{
		return;
	}
	if (Left <= Start && End <= Right)
	{
		res->first =res->first > SegmentTree[Node].first?res->first: SegmentTree[Node].first;
		res->second = res->second < SegmentTree[Node].second ? res->second : SegmentTree[Node].second;
		return;
	}
	int Mid = (Start + End) / 2;
	cmp(Node * 2, Start, Mid, Left, Right, res);
	cmp(Node * 2 + 1, Mid + 1, End, Left, Right, res);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	int a, b;
	pair<int, int> res;
	cin >> n >> m;
	int Tree_Height = (int)ceil(log2(n));
	int Tree_Size = (1 << (Tree_Height + 1));
	SegmentTree.resize(Tree_Size);
	for (int i = 0; i < n; i++)
		cin >> Arr[i];
	Make_SegmentTree(1, 0, n - 1);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		res.first = 0;
		res.second = ma;
		cmp(1, 0, n - 1, a - 1, b - 1, &res);
		cout << res.second << " " << res.first <<"\n";
	}

	return 0;
}