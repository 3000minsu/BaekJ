//https://dlwnsdud205.tistory.com/156
#include <stdio.h>
int gi[100000] = { 0 };
int find(int x)
{
    if (gi[x] == x)
        return x;
    return gi[x] = find(gi[x]);
}
int merge(int x, int y)
{
    x = find(x);
    y = find(y);
    gi[y] = x;
}
int main()
{
    int g, p, cnt = 0, temp, parent;
    scanf("%d\n%d", &g, &p);
    for (int i = 0; i <= g; i++)
        gi[i] = i;
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &temp);
        parent = find(temp);
        if (parent == 0)
            break;
        else
        {
            merge(parent - 1, parent);
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}