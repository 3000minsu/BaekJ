#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp;
    vector<int> v;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++)
        cout<<v[i]<<"\n";
    return 0;
}