#include <stdio.h>
int main()
{
    char sub[51];
    char sco[3];
    char hak[4];
    float cnt=0, temp=0, temp2=0, add=0;
    for(int i=0; i<20;i++)
    {
        scanf("%s", sub);
        scanf("%s", hak);
        temp=hak[0]-'0';
        scanf("%s", sco);
        if(sco[0]=='P')
            continue;
        if(sco[0]=='A')
        {
            if(sco[1]=='+')
                temp2=4.5;
            if(sco[1]=='0')
                temp2=4;
        }  
       if(sco[0]=='B')
        {
            if(sco[1]=='+')
                temp2=3.5;
            if(sco[1]=='0')
                temp2=3;
        }  
        if(sco[0]=='C')
        {
            if(sco[1]=='+')
                temp2=2.5;
            if(sco[1]=='0')
                temp2=2;
        }  
        if(sco[0]=='D')
        {
            if(sco[1]=='+')
                temp2=1.5;
            if(sco[1]=='0')
                temp2=1;
        }  
        if(sco[0]=='F')
            temp2=0;
        cnt+=temp;
        add+=temp*temp2;
    }
    
    printf("%6f", (float)add/(float)cnt);
    return 0;
    
}