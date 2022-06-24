#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    int n, da, cnt=0;
    cin>>n;
    cin>>da;
    for(int i=0; i<n-1; i++)
    {
        int temp;
        cin>>temp;
        if(temp>=da)
            pq.push(temp);
    }
    while(1)
    {
        if(pq.empty())
            break;
        int k;
        k=pq.top();
        pq.pop();
        k--;
        da++;
        cnt++;
        pq.push(k);
        k=pq.top();
        if(da>k)
            break;
    }
    cout<<cnt;
    return 0;
}