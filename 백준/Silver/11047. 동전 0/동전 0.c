#include <stdio.h>
int n, k;
int coin[10];
int main()
{
    int cnt=0, i, ch=0;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
        scanf("%d", &coin[i]);
    i=n-1;
    while(1)
    {
        while(1)
        {
             if(k-coin[i]>=0)   
             {
                 k-=coin[i];
                 cnt++;
                 if(k==0)
                 {
                     ch=1;  
                     break;
                 }
             }
            else
                break;
            
        }
        if(ch==1)
            break;
        i--;
    }
    printf("%d", cnt);
    
    return 0;
}