#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, n, temp, cnt=0;
    int min=10000, minp;
    scanf("%d %d", &a, &b);
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        if(abs(temp-b)<min)
        {
            min=abs(temp-b);
            minp=temp;
        }
    }
    if(abs(minp-b)<abs(a-b))
        cnt=1+abs(minp-b);
    else
        cnt=abs(a-b);
    printf("%d", cnt);
    return 0;
}