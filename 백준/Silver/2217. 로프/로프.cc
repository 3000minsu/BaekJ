#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;
int main()
{
    priority_queue < int> pq;
    int n, a, max=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        pq.push(-a);
    }
    while (!pq.empty())
    {
        int temp;
        temp = -pq.top();
        pq.pop();
        temp *= n;
        if (temp > max)
            max = temp;
        n--;
    }
    cout << max;
    return 0;
}