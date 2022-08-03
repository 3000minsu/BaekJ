#include <stdio.h>
int main()
{
    int a, b, c, go, ans;
    scanf("%d %d %d", &a, &b, &c);
    go=a-b;
    c-=a;
    if(c%go==0)
        ans=c/go;
    else
        ans=c/go+1;
    printf("%d", ans+1);
}