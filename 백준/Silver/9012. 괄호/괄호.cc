#include <bits/stdc++.h>
using namespace std;
int main()
{
    string temp;
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        cnt = 0;
        for (char k : temp)
        {
            if (cnt < 0)
                break;
            if (k == '(')
                cnt++;
            else if (k == ')')
                cnt--;
        }
        if (cnt == 0)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}