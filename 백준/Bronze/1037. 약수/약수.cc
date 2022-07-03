#include <bits/stdc++.h>
#define inf 1000001
using namespace std;
int main()
{
    int arr[50];
    int n, max=0, min=inf;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+n);
    if(n%2==0)
        printf("%d", arr[0]*arr[n-1]);
    else
        printf("%d", arr[n/2]*arr[n/2]);
    return 0;
}