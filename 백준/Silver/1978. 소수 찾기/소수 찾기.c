#include <stdio.h>
#include <math.h>
int main()
{
    int n, cnt=0, j=2, ch=0;
    double temp;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%lf", &temp);
        while(j<=sqrt(temp))
        {
            if((int)temp%j==0)
            {
                ch=1;
                break;
            }
            j++;
        }
        if(ch==0&&temp!=1)
            cnt++;
        j=2;
        ch=0;
    }
    printf("%d", cnt);
    return 0;
}