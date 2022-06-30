#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;
map<string, string> parent;
map<string, int> fri;
//vector<int> ans;
int ca, n;
string find(string x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}
void merge(string x, string y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		cout<<fri[x]<<"\n";
	else
	{
		cout<<fri[x] + fri[y]<<"\n";
		parent[y] = x;
		fri[x] += fri[y];
	}
}
int main()
{
    char t1[21], t2[21];
	string temp1, temp2;
	int x, y;
	scanf("%d", &ca);
	for (int i = 0; i < ca; i++)
	{
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%s", t1);
            scanf("%s", t2);
            temp1.assign(t1);
            temp2.assign(t2);
			parent.insert({ temp1, temp1 });
			parent.insert({ temp2, temp2 });
			fri.insert({ temp1, 1 });
			fri.insert({ temp2, 1 });
			merge(temp1, temp2);
		}
		fri.clear();
		parent.clear();
	}
	
	
	return 0;
}