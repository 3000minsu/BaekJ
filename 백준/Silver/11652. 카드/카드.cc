#include <bits/stdc++.h>
using namespace std;
map<long long, int> m;
int main()
{
    int n, ma=0;
    long long ma_index, temp;
    map<long long, int>::iterator iter;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &temp);
        iter = m.find(temp);
        if (iter == m.end())
            m.emplace(temp, 1);
        else
            iter->second++;
    }
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second > ma)
        {
            ma = iter->second;
            ma_index = iter->first;
        }
    }
    printf("%lld", ma_index);
    return 0;
}