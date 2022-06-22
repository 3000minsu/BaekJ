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
             if(k-coin[i]>=0)//k가 동전 금액보다 클때   
             {
                 k-=coin[i];//가장 금액이 큰 동전부터 뺌
                 cnt++;
                 if(k==0)//0원이면 종료
                 {
                     ch=1;  
                     break;
                 }
             }
            else//k가 0보다 작으면 작은 동전으로 다시
                break;
            
        }
        if(ch==1)//0원이면 종료
            break;
        i--;
    }
    printf("%d", cnt);
    
    return 0;
}