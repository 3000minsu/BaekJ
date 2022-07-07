#include <bits/stdc++.h>
using namespace std;
struct cmp {

    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        else
            return abs(a) > abs(b);
    }
};
int main()
{
    priority_queue<int, vector<int>, cmp> q;
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp == 0)
        {
            if (q.empty())
                printf("0\n");
            else
            {
                printf("%d\n", q.top());
                q.pop();
            }
        }
        else
            q.push(temp);
    }

    return 0;
}