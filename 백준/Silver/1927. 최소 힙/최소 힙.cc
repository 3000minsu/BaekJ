#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int main()
{
    int n, temp;
    scanf("%d", &n);
    for(int i=0;i<n; i++)
    {
        scanf("%d", &temp);
        if(temp==0)
        {
            if(q.empty())
                printf("0\n");
            else
            {
                printf("%d\n", -q.top());
                q.pop();
            }
        }
        else
            q.push(-temp);
    }
    
    return 0;
}