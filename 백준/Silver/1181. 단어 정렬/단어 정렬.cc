#include <bits/stdc++.h>
using namespace std;
bool cmp(string s1, string s2)
{
	if (s1.size() == s2.size())
	{
		return s1 < s2;
	}
	else
		return s1.size() < s2.size();
}
int main()
{
	vector<string> l;
	string temp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		l.push_back(temp);
	}
	sort(l.begin(), l.end(), cmp);
	temp = "\0";
	for (string k : l)
	{
		if(temp !=k)
			cout << k << endl;
		temp = k;
	}
	return 0;
}