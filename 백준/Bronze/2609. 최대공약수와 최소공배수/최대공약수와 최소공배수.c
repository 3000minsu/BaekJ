#include <stdio.h>
int main()
{
    int a, b, temp, ra, rb;
    scanf("%d %d",&ra, &rb);
    a=ra;
    b=rb;
    while(1)
    {
        if(b>a)
        {
            temp=b;
            b=a;
            a=temp;
        }
        temp=a%b;
        if(temp==0)
            break;
        a=b;
        b=temp;
    }
    printf("%d\n%d", b, (ra*rb)/b);
    return 0;
}