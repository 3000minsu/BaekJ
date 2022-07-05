#include <bits/stdc++.h>
using namespace std;
int arr[100000]={false};
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+n);
    printf("%d ", arr[0]);
    for(int i=1; i<n; i++)
    {
        if(arr[i]!=arr[i-1])
            printf("%d ", arr[i]);
    }
    return 0;
}