#include <stdio.h>
int main()
{
    long long int n, i = 1, cnt = 0, temp = 0;
    scanf("%lld", &n);
    while (1)
    {
        if (temp + i < n)
        {
            temp += i;
            i++;
            cnt++;
        }
        else if (temp + i == n)
        {
            cnt++;
            break;
        }
        else//n보다 클때
            break;
    }
    printf("%lld", cnt);
    return 0;
}