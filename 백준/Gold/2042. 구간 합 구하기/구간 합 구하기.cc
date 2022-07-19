#include <bits/stdc++.h>
using namespace std;
vector<long long> SegmentTree;
long long Arr[1000000];
long long Make_SegmentTree(int Node, int Start, int End)
{
	if (Start == End)
		return SegmentTree[Node] = Arr[Start];
	int Mid = (Start + End) / 2;
	long long Left_Result = Make_SegmentTree(Node * 2, Start, Mid);
	long long Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);
	SegmentTree[Node] = Left_Result + Right_Result;
	return SegmentTree[Node];
}

long long Sum(int Node, int Start, int End, int Left, int Right)
{
	if (Left > End || Right < Start)
		return 0;
	if (Left <= Start && End <= Right)
		return SegmentTree[Node];
	int Mid = (Start + End) / 2;
	long long Left_Result = Sum(Node * 2, Start, Mid, Left, Right);
	long long Right_Result = Sum(Node * 2 + 1, Mid + 1, End, Left, Right);
	return Left_Result + Right_Result;
}
void Update_SegmentTree(int Node, int Start, int End, int Index, long long Diff)
{
	if (Index < Start || Index > End)
		return;
	SegmentTree[Node] = SegmentTree[Node] + Diff;
	if (Start != End)
	{
		int Mid = (Start + End) / 2;
		Update_SegmentTree(Node * 2, Start, Mid, Index, Diff);
		Update_SegmentTree(Node * 2 + 1, Mid + 1, End, Index, Diff);
	}
}

int main()
{
	int n, m, k;
	int a, b;
	long long c, temp;
	cin >> n >> m >> k;
	int Tree_Height = (int)ceil(log2(n));
	int Tree_Size = (1 << (Tree_Height + 1));
	SegmentTree.resize(Tree_Size);
	for (int i = 0; i < n; i++)
		cin >> Arr[i];
	Make_SegmentTree(1, 0, n - 1);
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			Update_SegmentTree(1, 0, n - 1, b - 1, c - Arr[b - 1]);
			Arr[b - 1] = c;
		}
		if (a == 2)
		{
			temp=Sum(1, 0, n - 1, b - 1, c - 1);
			cout << temp << endl;
		}

	}

	return 0;
}