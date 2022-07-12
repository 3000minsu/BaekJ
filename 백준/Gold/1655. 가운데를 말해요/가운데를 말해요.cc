#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pos;//최소힙 큰쪽
priority_queue<int> pre;//최대힙 중간보다 작은쪽
int main()
{
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (i == 0)
        {
            pre.push(temp);
            printf("%d\n", pre.top());
        }
        else if (i == 1)
        {
            if (pre.top() <= temp)
            {
                pos.push(temp);
                printf("%d\n", pre.top());
            }
            else
            {
                pos.push(pre.top());
                pre.pop();
                pre.push(temp);
                printf("%d\n", pre.top());
            }
        }
        else
        {
            if (temp < pre.top())
                pre.push(temp);
            else if (temp > pos.top())
                pos.push(temp);
            else
            {
                if (pre.size() > pos.size())
                    pos.push(temp);
                else
                    pre.push(temp);
            }


            if (abs((int)pre.size() - (int)pos.size()) <= 1)
            {
                //printf("%d", abs((int)pre.size() - (int)pos.size()));
                if (pre.size() >= pos.size())
                    printf("%d\n", pre.top());
                else
                    printf("%d\n", pos.top());
            }
            else
            {
                if (pre.size() > pos.size())
                {
                    pos.push(pre.top());
                    pre.pop();
                    printf("%d\n", pre.top());
                }
                else
                {
                    pre.push(pos.top());
                    pos.pop();
                    printf("%d\n", pre.top());
                }

            }

        }
    }

    return 0;
}