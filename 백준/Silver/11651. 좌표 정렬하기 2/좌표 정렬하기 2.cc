#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100000];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i].second, &a[i].first);
    sort(a, a+n);
    for (int i = 0; i < n; i++)
        printf("%d %d\n", a[i].second, a[i].first);
    return 0;
}