#include <bits/stdc++.h>
using namespace std;
int arr[500000];
int main()
{
    int n, m, temp, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp);
        c = (int)(upper_bound(arr, arr + n, temp) - arr) - (int)(lower_bound(arr, arr + n, temp) - arr);
        printf("%d ", c);
    }
    return 0;
}