#include <bits/stdc++.h>
#define mod 1000000007
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
	SegmentTree[Node] = (Left_Result * Right_Result)%mod;
	return SegmentTree[Node];
}

long long mul(int Node, int Start, int End, int Left, int Right)
{
	if (Left > End || Right < Start)
		return 1;
	if (Left <= Start && End <= Right)
		return SegmentTree[Node];
	int Mid = (Start + End) / 2;
	long long Left_Result = mul(Node * 2, Start, Mid, Left, Right);
	long long Right_Result = mul(Node * 2 + 1, Mid + 1, End, Left, Right);
	return (Left_Result * Right_Result)%mod;
}
void Update_SegmentTree(int Node, int Start, int End, int Index, int ne)
{
	if (Index < Start || Index > End)
		return;
	if (Start == End) 
	{ 
		SegmentTree[Node] = ne; 
		return; 
	}
	if (Start != End)
	{
		int Mid = (Start + End) / 2;
		Update_SegmentTree(Node * 2, Start, Mid, Index, ne);
		Update_SegmentTree(Node * 2 + 1, Mid + 1, End, Index, ne);
	}
	SegmentTree[Node] = (SegmentTree[Node * 2] * SegmentTree[Node * 2 + 1]) % mod;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
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
			Update_SegmentTree(1, 0, n - 1, b - 1, c);
			Arr[b - 1] = c;
		}
		if (a == 2)
		{
			temp = mul(1, 0, n - 1, b - 1, c - 1);
			cout << temp % mod << endl;
		}

	}

	return 0;
}