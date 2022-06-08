#include <stdio.h>
int main()
{
    int n, temp, add=0;
    scanf("%d", &n);
    for(int i=0; i<n;i++)
    {
        scanf("%1d", &temp);
        add+=temp;
    }
    printf("%d", add);
    return 0;
}