#include <bits/stdc++.h>
using namespace std;
int n;
bool vi[100001] = { false };
bool ans[300001] = { false };
stack<int> s;
int main()
{
    int temp,c=0, t=1, cnt=0;
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &temp);
        if (s.empty())
        {
            for (int i = t; i <= temp; i++)
            {
                if (!vi[i])
                {
                    s.push(i);
                    vi[i] = true;
                    ans[cnt] = true;
                    cnt++;
                }
            }
            t = s.top();
            s.pop();
            ans[cnt] = false;
            cnt++;
        }
        else if (s.top() > temp)
        {
            c = 1;
            break;
        }
        else if (s.top() == temp)
        {
            s.pop();
            ans[cnt] = false;
            cnt++;
        }
        else if (s.top() < temp)
        {
            for (int i = s.top(); i <= temp; i++)
            {
                if (!vi[i])
                {
                    s.push(i);
                    vi[i] = true;
                    ans[cnt] = true;
                    cnt++;
                }
            }
            t = s.top();
            s.pop();
            ans[cnt] = false;
            cnt++;
        }
    }
    if (c == 1)
        printf("NO");
    else
    {
        for (int i = 0; i < cnt; i++)
        {
            if (ans[i])
                printf("+\n");
            else
                printf("-\n");
        }

    }




    return 0;
}