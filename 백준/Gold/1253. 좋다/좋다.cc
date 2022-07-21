#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int arr[2001];
int main()
{
	int n, temp, k, cnt=0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr[i] = temp;
		if (m.find(temp) != m.end())
			m[temp]++;
		else
			m.emplace(temp, 1);
	}
	for (int i = 0; i < n; i++)
	{
		k = arr[i];
		for (int j = 0; j < n; j++)
		{
			if (m.find(k - arr[j]) != m.end())
			{
				if (arr[j] == k)
				{
					if (m[k] > 2)
					{
						cnt++;
						break;
					}
					continue;
				}
				if (k - arr[j] == k)
				{
					if (m[k] > 1)
					{
						cnt++;
						break;
					}
					continue;
				}
				if (k - arr[j] == arr[j])
				{
					if (m[arr[j]] > 1)
					{
						cnt++;
						break;
					}
					continue;
				}
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}