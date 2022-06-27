#include <stdio.h>
#include <math.h>
int main()
{
    int ca;
    int x1, y1, r1, x2, y2, r2;
    int rd;
    double d;
    int ans[1000];
    scanf("%d", &ca);
    for(int i=0; i<ca; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);    
        rd=r1+r2;
        d=sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
        if(rd==d)
            ans[i]=1;
        else if(rd>d)
        {
           
            if(d+r2<r1||d+r1<r2)
                 ans[i]=0;
            else if(d==0&&r1==r2)
                ans[i]=-1;
            else if(r1==r2+d||r2==r1+d)
                ans[i]=1;
            else
                ans[i]=2;
        }
        else if(rd<d)
            ans[i]=0;
    }
    for(int i=0; i<ca; i++)
        printf("%d\n", ans[i]);
    
    return 0;
}