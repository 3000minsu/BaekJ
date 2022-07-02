#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, temp;
    vector<int> v1;
    vector<int> v2;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        v1.push_back(temp);
    }    
    sort(v1.begin(), v1.end());
        scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d", &temp);
        v2.push_back(temp);
    }  
     for(int i=0; i<m; i++)
    {
        if(binary_search(v1.begin(), v1.end(), v2[i]))
            cout<<1<<" ";
         else
             cout<<0<<" ";
    }  
    return 0;
}