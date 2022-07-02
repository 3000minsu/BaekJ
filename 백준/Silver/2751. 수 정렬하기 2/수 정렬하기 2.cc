#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    int n, temp;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        pq.push(-temp);
    }
    while(!pq.empty())
    {
        temp=-pq.top();
        pq.pop();
        cout<<temp<<"\n";
    }
    return 0;
}