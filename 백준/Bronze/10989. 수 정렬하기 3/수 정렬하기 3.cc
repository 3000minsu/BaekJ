#include <bits/stdc++.h>
using namespace std;
int arr[10001]={0};
int main()
{
    int n, temp;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        arr[temp]++;
    }
    for(int i=0; i<10001; i++)
    {
        for(int j=0; j<arr[i]; j++)
            cout<<i<<"\n";
    }
    return 0;
}