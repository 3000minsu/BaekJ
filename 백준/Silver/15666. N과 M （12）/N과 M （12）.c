#include <stdio.h>
int n, m, rn=0;
int arr[7] = { 0 };
int ans[7];
void dfs(int cnt, int pa)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for (int i = pa; i < rn; i++)
    {
            ans[cnt] = arr[i];
            dfs(cnt + 1, i);
    }
}
int main()
{
    int temp,temp2, a, ch=0, i=0;
    scanf("%d %d", &n, &m);
    while(i<n)
    {
        scanf("%d", &a);
        for (int j = 0; j < rn; j++)
        {
            if (arr[j] == a)
                ch = 1;
        }
        if (ch == 0)
        {
            arr[rn] = a;
            rn++;
        }
        i++;
        ch = 0;
    }
    for (int i = 0; i < rn; i++)//오름차순 정렬
    {
        for (int j = 0; j <rn - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    dfs(0, 0);
    return 0;
}