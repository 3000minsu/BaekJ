#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int meeting[100000][2];
int main()
{
    int n, st, en, cnt = 1;
    priority_queue<pair<int, int>> pq;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> st >> en;
        pq.emplace(-en, -st);
    }
    pair<int,int> p = pq.top();
    pq.pop();
    st = -p.second;
    en = -p.first;
    while (!pq.empty())
    {
        p = pq.top();
        pq.pop();
        if (en <= -p.second)
        {
            cnt++;
            st = -p.second;
            en = -p.first;
        }
    }
    cout<< cnt;
    return 0;
}