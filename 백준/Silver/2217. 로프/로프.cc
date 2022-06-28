#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;
int main()
{
    //최대무게= 최소 무게 * 로프 갯수
    priority_queue < int> pq;
    int n, a, max=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        pq.push(-a);//작은거 먼저
    }
    while (!pq.empty())//가장 약한 로프 하나씩 제거하면서
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